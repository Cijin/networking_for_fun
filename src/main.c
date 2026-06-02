#include <stdio.h>
#include <string.h>
#include <curl/curl.h>

void log_error(CURLcode result, char *errbuf) {
  size_t len = strlen(errbuf);
  fprintf(stderr, "\nlibcurl: (%d) ", result);

  if (len) fprintf(stderr, "%s%s", errbuf, ((errbuf[len - 1] != '\n') ? "\n" : ""));
  else fprintf(stderr, "%s\n", curl_easy_strerror(result));
}

int main(void) {
  CURL *curl = curl_easy_init();
  if (!curl) {
    fprintf(stderr, "failed to init curl\n");
    return 1;
  }

  CURLcode result;
  char errbuf[CURL_ERROR_SIZE] = {0};

  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errbuf);
  curl_easy_setopt(curl, CURLOPT_URL, "https://example.com");

  result = curl_easy_perform(curl);
  if (result != CURLE_OK) {
    log_error(result, errbuf);
  }

  curl_easy_cleanup(curl);
  return (result == CURLE_OK) ? 0 : 1;
}
