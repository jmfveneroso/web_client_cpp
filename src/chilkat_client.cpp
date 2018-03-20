#include "chilkat_client.hpp"
#include <iostream>

std::string ChilkatClient::Download(const std::string& url) {
  CkSpider spider;
  spider.AddUnspidered(url.c_str());
  if (!spider.CrawlNext()) {
    CkString error;
    spider.LastErrorText(error);
    throw std::runtime_error(error.getString());
  }

  std::string html = spider.lastHtml();
  std::vector<std::string> queue;

  // Inbound links.
  int size = spider.get_NumUnspidered();
  for (int i = 0; i < size; i++) {
    std::string link = spider.getUnspideredUrl(0);
    spider.SkipUnspidered(0);
    queue.push_back(link);
  }

  // Outbound links.
  for (int i = 0; i < spider.get_NumOutboundLinks(); i++) {
    std::string link = spider.getOutboundLink(i);
    queue.push_back(link);
  }

  return html;
}
