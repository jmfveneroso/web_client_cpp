#include "curl_client.hpp"
#include "test.hpp"
#include <iostream>
#include <cassert>

int main() {
  CurlClient client;
  for (auto& url : test_urls) {
    std::string html = client.Download(url);
    assert(ValidateHtml(html));
  }
  return 0;
}
