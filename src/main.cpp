#include "web_client.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong number of arguments." << std::endl;
    return 1;
  }

  WebClient web_client;
  HttpResponse response = web_client.Download(argv[1]);
  std::cout << response.body << std::endl;
  return 0;
}
