#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_LEN 256

void get_chars_used(const char *str, int chars_used[]) {
  memset(chars_used, 0, ASCII_LEN * sizeof(int));

  uint8_t str_len = strlen(str);

  // store used chars + calculate new_str_len
  for (uint8_t i = 0; i < str_len; i++) {
    int index = (int)str[i];

    if (chars_used[index] == 0) {
      chars_used[index]++;
    }
  }
}

uint8_t get_new_str_len(const char *str, int chars_used[]) {
  uint8_t str_len = strlen(str);
  uint8_t new_str_len = 0;

  for (int i = 0; i < str_len; i++) {
    int index = (int)str[i];

    if (chars_used[index] == 0)
      new_str_len++;
  }

  return new_str_len;
}

char *remove_duplicates(const char *str1, const char *str2) {
  if (str1 == NULL || str2 == NULL) {
    return NULL;
  }

  int chars_used[ASCII_LEN];
  get_chars_used(str2, chars_used);

  uint8_t new_str_len = get_new_str_len(str1, chars_used);

  char *new_str = (char *)malloc(new_str_len + 1); // + 1 for \0
  if (new_str == NULL) {
    perror("Couldn't allocate memory!\n");
    return NULL;
  }
  bzero(new_str, new_str_len);

  uint8_t str1_len = strlen(str1);

  int new_str_index = 0;

  int chars_written[ASCII_LEN] = {0};
  for (int i = 0; i < str1_len; i++) {
    int index = (int)str1[i];

    if (chars_used[index] == 0 && chars_written[index] == 0) {
      chars_written[index] = 1;
      new_str[new_str_index] = str1[i];
      new_str_index++;
    }
  }

  return new_str;
}
