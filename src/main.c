#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("Welcome to Postguy! A simple tool to make HTTP requests\n");

  char url[100];
  printf("Enter request URL: ");
  scanf("%s", url);

  char method[10];
  printf("Enter request method: ");
  scanf("%s", method);

  CURL *curl = curl_easy_init();
  if (!curl) {
    fprintf(stderr, "Failed to initialize curl\n");
    return EXIT_FAILURE;
  }

  printf("Making %s request to url %s\n", method, url);

  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, method);

  CURLcode res = curl_easy_perform(curl);
  if (res != CURLE_OK) {
    fprintf(stderr, "Request failed: %s\n", curl_easy_strerror(res));
    return EXIT_FAILURE;
  }

  printf("%u\n", res),

      curl_easy_cleanup(curl);
  return EXIT_SUCCESS;
}
