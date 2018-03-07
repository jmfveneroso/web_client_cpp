#include "curl_client.hpp"
#include "chilkat_client.hpp"
#include "custom_client.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong number of arguments." << std::endl;
    return 1;
  }

  // Curllient client;
  // ChilkatClient client;
  CustomClient client;
  std::cout << client.Download(argv[1]) << std::endl;
  return 0;
}
