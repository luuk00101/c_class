#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MAX_BUFFER_LEN 512

void deleteNewLine(char *buffer);
void rtrim(char *str);
void printAscii(char *str);

int main(int argc, char *argv[]) {
  char buffer[MAX_BUFFER_LEN];
  bzero(buffer, MAX_BUFFER_LEN);

  printf("Your name: ");
  fflush(stdout);
  char *ret = fgets(buffer, MAX_BUFFER_LEN, stdin);
  if (ret == NULL) {
    printf("Input error");
    return 1;
  }

  printAscii(buffer);
  rtrim(buffer);
  printf("Hi, %s!\n", buffer);

  return 0;
}

void deleteNewLine(char *buffer) { buffer[strcspn(buffer, "\n")] = 0; }

void rtrim(char *str) {
  size_t str_len = strlen(str);

  for (size_t i = str_len - 1; i >= 0; i--) {
    if (str[i] < 32) {
      str[i] = 0;
    } else {
      return;
    }
  }
}

void printAscii(char *str) {
  for (size_t i = 0; i < strlen(str); i++) {
    printf("[%lu] %u | ", i, str[i]);
  }

  printf("\n");
}
