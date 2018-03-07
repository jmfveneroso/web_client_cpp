#include "web_client.hpp"

void *get_in_addr(struct sockaddr* sa) {
  if (sa->sa_family == AF_INET) {
    return &(((struct sockaddr_in*) sa)->sin_addr);
  }
  return &(((struct sockaddr_in6*) sa)->sin6_addr);
}

Header WebClient::ParseHeader(const std::string& msg) {
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

Url WebClient::ParseUrl(const std::string& url) {
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

int WebClient::Send(int socket, const std::string& msg) {
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

int WebClient::HttpsReceive(SSL* ssl, char buffer[], int length) {
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

int WebClient::HttpsSend(const std::string& msg) {
  char* buffer = new char[msg.size() + 1];
  std::copy(msg.begin(), msg.end(), buffer);
  buffer[msg.size()] = '\0';

  int len = SSL_write(ssl_, buffer, strlen(buffer));
  if (len < 0) {
    int err = SSL_get_error(ssl_, len);
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
  return len;
}

size_t WebClient::Recv(int socket, char buffer[], int length) {
  if (use_ssl_) {
    return HttpsReceive(ssl_, buffer, length);
  } else {
    return recv(socket, buffer, length, 0);
  }
}

HttpResponse WebClient::Receive(int socket) {
  HttpResponse response;
  int num_bytes; 
  int received = 0;
  char buffer[MAX_DATA_SIZE];

  if ((num_bytes = Recv(socket, buffer, MAX_DATA_SIZE - 1)) == -1) {
    throw std::runtime_error("Receiving error.");
  }
  received += num_bytes;
  buffer[num_bytes] = '\0';

  response.header = ParseHeader(buffer);
  response.body = "";
  bool chunked = false;

  // Servers may respond with chunked messages or with the entire message.
  if (response.header.attrs.find("Transfer-Encoding") != response.header.attrs.end()) {
    chunked = response.header.attrs["Transfer-Encoding"] == "chunked";
  }

  int cursor = response.header.size;
 
  // Chunked encoding. 
  if (chunked) {
    int size = -1;
    received = 0;
    while (true) {
      if (cursor >= num_bytes) {
        if ((num_bytes = Recv(socket, buffer, MAX_DATA_SIZE - 1)) == -1) {
          throw std::runtime_error("Receiving error.");
        }
        buffer[num_bytes] = '\0';
        cursor = 0;
      }

      if (size == -1) {
        std::string s;
        for (; cursor < MAX_DATA_SIZE; cursor++) {
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

  // Content length. 
  } else {  
    response.body += std::string(buffer).substr(response.header.size, num_bytes);

    int length = 0;
    if (response.header.attrs.find("Content-Length") != response.header.attrs.end()) {
      length = atoi(response.header.attrs["Content-Length"].c_str());
    }

    while (received < length) {
      if ((num_bytes = Recv(socket, buffer, MAX_DATA_SIZE - 1)) == -1) {
        throw std::runtime_error("Receiving error.");
      }
      buffer[num_bytes] = '\0';
      response.body += std::string(buffer).substr(0, num_bytes);
      received += num_bytes;
    }
  }
  return response;
}

int WebClient::GetSocket(const Url& url, const char port[]) {
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

  // Try to connect to each returned IP.
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

std::string WebClient::GetRequestMessage(const Url& url) {
  // Very simple http GET request message.
  std::stringstream ss;
  ss << "GET " << url.filename << " HTTP/1.1\r\n";
  ss << "Host: " << url.hostname << "\r\n";
  ss << "User-Agent: curl/7.43.0\r\n";
  ss << "Accept: */*\r\n";
  ss << "\r\n";
  return ss.str();
}

int WebClient::InitSSL(const Url& url) {
  // OpenSSL initialization.
  int s = GetSocket(url, "443");
  SSL_library_init();
  SSLeay_add_ssl_algorithms();
  SSL_load_error_strings();
  const SSL_METHOD* meth = TLSv1_2_client_method();
  SSL_CTX* ctx = SSL_CTX_new(meth);
  ssl_ = SSL_new(ctx);
  if (!ssl_) {
    throw std::runtime_error("SSL error.");
  }
  int sock = SSL_get_fd(ssl_);
  SSL_set_fd(ssl_, s);
  if (SSL_connect(ssl_) <= 0) {
    throw std::runtime_error("SSL error.");
  }
  return sock;
}

HttpResponse WebClient::DownloadHttp(const Url& url) {
  use_ssl_ = false;
  int sock = GetSocket(url, "80");
  Send(sock, GetRequestMessage(url));
  HttpResponse response = Receive(sock);
  close(sock);
  return response;
}

HttpResponse WebClient::DownloadHttps(const Url& url) {
  use_ssl_ = true;
  int sock = InitSSL(url);
  HttpsSend(GetRequestMessage(url));
  HttpResponse response = Receive(sock);
  close(sock);
  return response;
}

HttpResponse WebClient::Download(const std::string& url) {
  std::string current_url = url;

  // Performs a finite number of redirects.
  for (int i = 0; i < MAX_REDIRECTS; i++) {
    Url obj_url = ParseUrl(current_url);
    if (obj_url.https) {
      return DownloadHttps(obj_url);
    } else {
      HttpResponse res = DownloadHttp(obj_url);

      // Code 301 - Moved Permanently, Code 302 - Found.
      if (res.header.code == 301 || res.header.code == 302 ) {
        current_url = res.header.attrs["Location"];
      } else {
        return res;
      }
    }
  }
  throw std::runtime_error("Exceeded maxmium number of redirects.");
}
