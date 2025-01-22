#include <stdio.h>
#include <string.h>

void invert(char *str);

int main(int argc, char *argv[]) {

  char str[] = "AKO sa MAS?";
  printf("String: %s\n", str);
  invert(str);
  printf("New string: %s\n", str);

  return 0;
}

void invert(char *str) {
  size_t str_len = strlen(str);
  for (size_t i = 0; i < str_len; i++) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      str[i] += 32;
    } else if ('a' <= str[i] && str[i] <= 'z') {
      str[i] -= 32;
    }
  }
}
