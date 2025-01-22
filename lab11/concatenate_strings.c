#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate_strings(const char *str1, const char *str2);

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("ERROR: Invalid arguments!\n");
    return 1;
  }
  char *str1 = argv[1];
  char *str2 = argv[2];

  printf("First word: %s\n", str1);
  printf("Second word: %s\n", str2);

  char *combined_word = concatenate_strings(str1, str2);
  if (combined_word == NULL) {
    return 1;
  }

  printf("Combined word: %s\n", combined_word);
  free(combined_word);
  return 0;
}

char *concatenate_strings(const char *str1, const char *str2) {
  size_t str1_len = 0;
  size_t str2_len = 0;
  if (str1 != NULL)
    str1_len = strlen(str1);
  if (str2 != NULL)
    str2_len = strlen(str1);

  char *buffer = (char *)malloc(str1_len + str2_len + 1);
  if (buffer == NULL) {
    printf("ERROR: Couldn't allocate memory!\n");
    return NULL;
  }

  bzero(buffer, str1_len + str2_len + 1);
  if (str1 != NULL)
    memcpy(buffer, str1, str1_len);
  if (str2 != NULL)
    memcpy(buffer + str1_len, str2, str2_len);

  return buffer;
}
