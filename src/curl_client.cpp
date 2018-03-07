#include "curl_client.hpp"
 
int CurlClient::WriteCallback(
  char *data, size_t size, size_t nmemb,
  std::string *writer_data
) {
  if (writer_data == NULL) return 0;
  writer_data->append(data, size * nmemb);
  return size * nmemb;
}
 
bool CurlClient::Init(CURL*& conn, const std::string& url) {
  conn = curl_easy_init();
  if (conn == NULL) {
    throw std::runtime_error("Failed to create CURL connection.");
  }
 
  CURLcode code = curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, error_buffer_);
  if (code != CURLE_OK) {
    throw std::runtime_error("Failed to set error buffer.");
  }
 
  code = curl_easy_setopt(conn, CURLOPT_URL, url.c_str());
  if (code != CURLE_OK) {
    throw std::runtime_error("Failed to set url.");
  }
 
  code = curl_easy_setopt(conn, CURLOPT_FOLLOWLOCATION, 1L);
  if (code != CURLE_OK) {
    throw std::runtime_error("Failed to set redirect option.");
  }
 
  code = curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, WriteCallback);
  if (code != CURLE_OK) {
    throw std::runtime_error("Failed to set write callback.");
  }
 
  code = curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer_);
  if (code != CURLE_OK) {
    throw std::runtime_error("Failed to set write data.");
  }
 
  return true;
}

std::string CurlClient::Download(const std::string& url) {
  curl_global_init(CURL_GLOBAL_DEFAULT);
 
  // Initialize CURL connection.
  CURL *conn = NULL;
  Init(conn, url);
 
  // Retrieve content.
  CURLcode code = curl_easy_perform(conn);
  curl_easy_cleanup(conn);
 
  if (code != CURLE_OK) {
    throw std::runtime_error("Failed to get content.");
  }

  return buffer_;
}
