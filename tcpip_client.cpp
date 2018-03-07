#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <fcntl.h>
#include <sstream>
#include <map>

#define MAXDATASIZE 1000000

struct Url {
  bool https; 
  std::string hostname;
  std::string filename;
};

struct Header {
  int code;
  std::map<std::string, std::string> attrs;
  int size;
};

struct Response {
  Header header;
  std::string body;
};

void *get_in_addr(struct sockaddr* sa) {
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*) sa)->sin_addr);
  }
  return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

class TCPClient {
  static Header ParseHeader(const std::string& msg) {
    Header h;

    size_t start = 0;
    size_t end = msg.find("\r\n", start);
    std::string status_line = msg.substr(start, end);
    size_t code_start = status_line.find(" ");
    size_t code_end = status_line.find(" ", code_start + 1);
    h.code = atoi(status_line.substr(code_start + 1, code_end - code_start - 1).c_str());
    start = end + 2;

    while ((end = msg.find("\r\n", start)) != std::string::npos) {
      if (end == start) {
        end += 2;
        break; // End of header "\r\n\r\n".
      }

      std::string line = msg.substr(start, end - start);
      int key_end = line.find(": ", 0);
      std::string key = line.substr(0, key_end);
      std::string value = line.substr(key_end + 2);
      h.attrs.insert(std::pair<std::string, std::string>(key, value));
      start = end + 2; 
    }
    h.size = end;
    return h;
  }

  static Url ParseUrl(const std::string& url) {
    Url obj_url;
    if (url.find("http://") == 0) {
      obj_url.https = false;
      obj_url.hostname = url.substr(7);
    } else if (url.find("https://") == 0) {
      obj_url.https = true;
      obj_url.hostname = url.substr(8);
    } else {
      throw std::runtime_error("Missing protocol (http:// or https://).");
    }

    obj_url.filename = "/";
    size_t hostname_end = obj_url.hostname.find("/");
    if (hostname_end != std::string::npos) {
      obj_url.filename = obj_url.hostname.substr(hostname_end);
      obj_url.hostname = obj_url.hostname.substr(0, hostname_end);
    }
    return obj_url; 
  }

  static int Send(int socket, const std::string& msg, SSL* ssl, bool is_ssl) {
    int length = msg.size();
    char* buffer = new char[msg.size() + 1];
    std::copy(msg.begin(), msg.end(), buffer);
    buffer[msg.size()] = '\0';

    int total = 0;           // Total bytes sent.      
    int bytes_left = length; // How many bytes are left to send.
    int num_bytes;           // Number of bytes sent in the last package.
  
    while (total < length) {
      num_bytes = send(socket, buffer + total, bytes_left, 0);
      if (num_bytes == -1) break;
      total += num_bytes;
      bytes_left -= num_bytes;
    }
  
    delete[] buffer;
    if (total < length) {
      throw std::runtime_error("Sending error.");
    }
    return total;
  } 

  static int HttpsReceive(SSL* ssl, char buffer[], int length) {
    int num_read = 0;
    num_read = SSL_read(ssl, buffer, length);

    if (length < 0) {
      int err = SSL_get_error(ssl, num_read);
      if (err == SSL_ERROR_WANT_READ)
        return 0;
      if (err == SSL_ERROR_WANT_WRITE)
        return 0;
      if (err == SSL_ERROR_ZERO_RETURN || err == SSL_ERROR_SYSCALL || err == SSL_ERROR_SSL)
        return -1;
    }
    return num_read;
  }

  static int HttpsSend(SSL* ssl, const std::string& msg) {
    int length = msg.size();
    char* buffer = new char[msg.size() + 1];
    std::copy(msg.begin(), msg.end(), buffer);
    buffer[msg.size()] = '\0';

    int len = SSL_write(ssl, buffer, strlen(buffer));
    if (len < 0) {
      int err = SSL_get_error(ssl, len);
      switch (err) {
      case SSL_ERROR_WANT_WRITE:
        return 0;
      case SSL_ERROR_WANT_READ:
        return 0;
      case SSL_ERROR_ZERO_RETURN:
      case SSL_ERROR_SYSCALL:
      case SSL_ERROR_SSL:
      default:
        return -1;
      }
    }
  }

  static size_t Recv(int socket, SSL* ssl, char buffer[], int length, bool is_ssl) {
    if (is_ssl) {
      return HttpsReceive(ssl, buffer, length);
    } else {
      return recv(socket, buffer, length, 0);
    }
  }

  static Response Receive(int socket, SSL* ssl, bool is_ssl) {
    Response response;
    int num_bytes; 
    int received = 0;
    char buffer[MAXDATASIZE];

    if ((num_bytes = Recv(socket, ssl, buffer, MAXDATASIZE - 1, is_ssl)) == -1) {
      throw std::runtime_error("Receiving error.");
    }
    received += num_bytes;
    buffer[num_bytes] = '\0';

    response.header = ParseHeader(buffer);
    response.body = "";
    bool chunked = false;
    if (response.header.attrs.find("Transfer-Encoding") != response.header.attrs.end()) {
      chunked = response.header.attrs["Transfer-Encoding"] == "chunked";
    }

    size_t cursor = response.header.size;
    if (chunked) {
      int size = -1;
      received = 0;
      while (true) {
        if (cursor >= num_bytes) {
          if ((num_bytes = Recv(socket, ssl, buffer, MAXDATASIZE - 1, is_ssl)) == -1) {
            throw std::runtime_error("Receiving error.");
          }
          buffer[num_bytes] = '\0';
          cursor = 0;
        }

        if (size == -1) {
          std::string s;
          for (; cursor < MAXDATASIZE; cursor++) {
            if (buffer[cursor] == '\r') {
              if (buffer[++cursor] == '\n') break;
              s += '\r';
            }
            s += buffer[cursor];
          }
          ++cursor;

          std::stringstream ss;
          ss << std::hex << s;
          ss >> size;

          if (size == 0) break;
          received = 0;
        }

        response.body += buffer[cursor];
        cursor++;

        if (++received == size) {
          cursor += 2;
          size = -1;
        }
      }
    } else {  
      response.body += std::string(buffer).substr(response.header.size, num_bytes);

      int length = 0;
      if (response.header.attrs.find("Content-Length") != response.header.attrs.end()) {
        length = atoi(response.header.attrs["Content-Length"].c_str());
      }

      while (received < length) {
        if ((num_bytes = Recv(socket, ssl, buffer, MAXDATASIZE - 1, is_ssl)) == -1) {
          throw std::runtime_error("Receiving error.");
        }
        buffer[num_bytes] = '\0';
        response.body += std::string(buffer).substr(0, num_bytes);
        received += num_bytes;
      }
    }
    return response;
  }

  static int GetSocket(const Url& url, const char port[]) {
    addrinfo hints;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;     // IPv4 or IPv6.
    hints.ai_socktype = SOCK_STREAM; // TCP.

    // Resolve hostname.
    addrinfo *res;
    int status = getaddrinfo(url.hostname.c_str(), port, &hints, &res);
    if (status != 0) {
      throw std::runtime_error(gai_strerror(status));
    }

    // Try to connect to each IP discovered.
    addrinfo *p;
    int sock;
    for (p = res; p != NULL; p = p->ai_next) {
      if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
        perror("client: socket");
        continue;
      }

      if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
        close(sock);
        perror("client: connect");
        continue;
      }

      break;
    }

    if (p == NULL) {
      throw std::runtime_error("Failed to connect.");
    }

    // Convert IP to string format.
    char ip[INET6_ADDRSTRLEN];
    inet_ntop(p->ai_family, get_in_addr((sockaddr*) p->ai_addr), ip, sizeof ip);
    freeaddrinfo(res);
#ifdef VERBOSE
    std::cout << "IP: " << ip << std::endl; 
#endif
    return sock;
  }

  static std::string GetRequestMessage(const Url& url) {
    std::stringstream ss;
    ss << "GET " << url.filename << " HTTP/1.1\r\n";
    ss << "Host: " << url.hostname << "\r\n";
    ss << "User-Agent: curl/7.43.0\r\n";
    ss << "Accept: */*\r\n";
    ss << "\r\n";
    return ss.str();
  }

  static Response DownloadHttp(const Url& url) {
    const char port[] = "80";

    int sock = GetSocket(url, port);
    Send(sock, GetRequestMessage(url), nullptr, false);
    Response response = Receive(sock, nullptr, false);
    close(sock);

    return response;
  }

  static Response DownloadHttps(const Url& url) {
    const char port[] = "443";
    int s = GetSocket(url, port);

    SSL_library_init();
    SSLeay_add_ssl_algorithms();
    SSL_load_error_strings();
    const SSL_METHOD* meth = TLSv1_2_client_method();
    SSL_CTX* ctx = SSL_CTX_new(meth);
    SSL* ssl = SSL_new(ctx);
    if (!ssl) {
      throw std::runtime_error("SSL error.");
    }
    int sock = SSL_get_fd(ssl);
    SSL_set_fd(ssl, s);
    if (SSL_connect(ssl) <= 0) {
      throw std::runtime_error("SSL error.");
    }

    HttpsSend(ssl, GetRequestMessage(url));
    Response response = Receive(sock, ssl, true);
    return response;
  }

 public:
  static Response Download(const std::string& url) {
    std::string current_url = url;

    // Maximum 5 redirects.
    for (int i = 0; i < 5; i++) {
      Url obj_url = ParseUrl(current_url);
      if (obj_url.https) {
        return DownloadHttps(obj_url);
      } else {
        Response res = DownloadHttp(obj_url);
        if (res.header.code == 301 || res.header.code == 302 ) {
          current_url = res.header.attrs["Location"];
        } else {
          return res;
        }
      }
    }
    throw std::runtime_error("Exceeded maxmium number of redirects.");
  }
};

int main(int argc, char* argv[]) {
  // Response r = TCPClient::Download("http://www.google.com");
  Response r = TCPClient::Download(argv[1]);
  std::cout << r.body << std::endl;
}
