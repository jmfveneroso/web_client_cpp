#ifndef __CUSTOM_CLIENT_HPP__
#define __CUSTOM_CLIENT_HPP__

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

#define MAX_REDIRECTS 5
#define MAX_DATA_SIZE 1000000
#define TIMEOUT 5000
#define VERBOSE

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

struct HttpResponse {
  Header header;
  std::string body;
};

class CustomClient {
  SSL* ssl_;
  bool use_ssl_;

  static Header ParseHeader(const std::string&);
  static Url ParseUrl(const std::string&);
  int Send(int, const std::string&);
  int HttpsReceive(SSL*, char[], int);
  int HttpsSend(const std::string&);
  size_t Recv(int, char[], int);
  HttpResponse Receive(int);
  int GetSocket(const Url&, const char[]);
  std::string GetRequestMessage(const Url&);
  int InitSSL(const Url&);
  HttpResponse DownloadHttp(const Url&);
  HttpResponse DownloadHttps(const Url&);

 public:
  std::string Download(const std::string&);
};

#endif
