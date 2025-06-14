#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// An api request handler as an example
struct api_request {
  int id;
  char body[20];
};

enum response_code { SUCCESS, ERROR };

struct api_response {
  int id;
  enum response_code code;
  int body[20];
};

int mock_api(const struct api_request *req, struct api_response *resp,
             enum response_code mocked_code) {
  resp->id = req->id;
  resp->code = mocked_code;
  if (mocked_code == SUCCESS) {
    strcpy(resp->body, "authorized_user");
  } else {
    // mocked_code == ERROR
    strcpy(resp->body, "unauthorized_user");
  }
  return 0; // indicate request was processed successfully, error codes are used
            // for functions here
}
int main(int argc, char const *argv[]) {
  // Statically allocated array struct for request
  struct api_request reqs[3];
  reqs[0].id = 0;
  strcpy(reqs[0].body, "GET user_name_0");
  reqs[1].id = 1;
  strcpy(reqs[1].body, "GET user_name_1");
  reqs[2].id = 3;
  strcpy(reqs[2].body, "GET user_name_2");

  // Dynamically allocated struct for response
  struct api_response *resps =
      (struct api_response *)malloc(sizeof(struct api_response) * 3);

  // Call the function by passing references to structs
  mock_api(&reqs[0], &resps[0], SUCCESS);
  mock_api(&reqs[1], &resps[1], ERROR);
  mock_api(&reqs[2], &resps[2], ERROR);

  // Print the responses by looping over the arrays
  for (int i = 0; i < 3; i++) {
    printf("\nID: %d\n", reqs[i].id);
    printf("Request: %s\n", reqs[i].body);
    printf("Response: %s, code: %d\n", resps[i].body, resps[i].code);
  }

  return 0;
}
