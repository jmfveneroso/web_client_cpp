#include <string>
#include <iostream>

const std::string test_urls[] = {
  "http://www.globo.com",
  "https://www.uol.com.br",
  "http://www.youtube.com",
  "https://stackoverflow.com",
  "https://www.google.com.br"
};


bool ValidateHtml(const std::string& html) {
  return html.find("<html"  ) != std::string::npos &&
         html.find("</html>") != std::string::npos;
}
