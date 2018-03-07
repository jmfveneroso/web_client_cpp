#ifndef __CURL_CLIENT_HPP__
#define __CURL_CLIENT_HPP__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <curl/curl.h>

class CurlClient {
  char error_buffer_[CURL_ERROR_SIZE];
  std::string buffer_;
 
  static int WriteCallback(char*, size_t, size_t, std::string*);
  bool Init(CURL*&, const std::string&);

 public:
  std::string Download(const std::string&);
};

#endif
