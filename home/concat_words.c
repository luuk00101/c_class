#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(const char *str1, const char *str2);

int main(int argc, char *argv[]) {

  char str1[] = "Ahoj";
  char str2[] = "Ako sa mas?";

  char *new_string = concat(str1, str2);
  if (new_string == NULL) {
    return 1;
  }

  printf("String 1: %s\n", str1);
  printf("String 2: %s\n", str2);
  printf("New string: %s\n", new_string);

  free(new_string);

  return 0;
}

char *concat(const char *str1, const char *str2) {
  size_t str1_len = strlen(str1);
  size_t str2_len = strlen(str2);
  size_t final_len = str1_len + str2_len + 1; // plus NULL

  char *final_string = malloc(final_len);

  if (final_string == NULL) {
    printf("Failed to malloc!!");
    return NULL;
  }
  bzero(final_string, final_len);

  size_t str1_counter = 0;
  size_t str2_counter = 0;
  size_t index = 0;
  while (str1_counter < str1_len || str2_counter < str2_len) {
    if (str1_counter < str1_len) {
      final_string[index] = str1[str1_counter];
      str1_counter++;
      index++;
    }
    if (str2_counter < str2_len) {
      final_string[index] = str2[str2_counter];
      str2_counter++;
      index++;
    }
  }

  return final_string;
}
