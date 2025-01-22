#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct duplicateArrayTuple {
  size_t duplicate_length;
  char *pduplicate_chars;
};

struct duplicateArrayTuple find_duplicates(const char *str, size_t length);

int main(int argc, char *argv[]) {
  char char_array[] = {'A', 'B', 'C', 'A', 'D', 'C'};
  size_t char_array_len = sizeof(char_array);

  struct duplicateArrayTuple result =
      find_duplicates(char_array, char_array_len);
  if (result.pduplicate_chars == NULL) {
    return 1;
  }
  printf("Found %zu duplicates: \n", result.duplicate_length);
  for (size_t i = 0; i < result.duplicate_length; i++) {
    printf("%c\n", result.pduplicate_chars[i]);
  }

  free(result.pduplicate_chars);
  return 0;
}

struct duplicateArrayTuple find_duplicates(const char *str, size_t length) {
  int character_count[128] = {0}; // 128 ASCII characters

  size_t new_array_len = 0;
  for (size_t i = 0; i < length; i++) {
    character_count[str[i]]++;
    if (character_count[str[i]] == 2)
      new_array_len++;
  }

  struct duplicateArrayTuple result;
  result.duplicate_length = new_array_len;

  char *duplicate_chars = (char *)malloc(new_array_len * sizeof(char));
  if (duplicate_chars == NULL) {
    result.duplicate_length = 0;
    printf("ERROR: Couldn't allocate memory!\n");
    return result;
  }

  int char_index = 0;
  for (int i = 0; i < 128; i++) {
    if (character_count[i] > 1) {
      duplicate_chars[char_index] = (char)i;
      char_index++;
    }
  }

  result.pduplicate_chars = duplicate_chars;
  return result;
}
