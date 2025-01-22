#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *generate_string_array(uint8_t length);
char **random_string(uint8_t chars[]);

int main(int argc, char *argv[]) {

  uint8_t chars[] = {2, 3, 1, 5};
  char **string_array = random_string(chars);
  if (string_array == NULL) {
    printf("Failed to allocate memory!");
    return 1;
  }

  for (int i = 0; i < sizeof(string_array); i++) {
    printf("%s", string_array[i]);
  }

  free(string_array);
  return 0;
}

char *generate_string_array(u_int8_t length) {
  char *string_array = (char *)malloc(length + 1);

  if (string_array == NULL) {
    return NULL;
  }
  bzero(string_array, length + 1);

  for (u_int8_t i = 0; i < length; i++) {
    string_array[i] = 97 + (rand() % 26);
  }

  return string_array;
}

char **random_string(uint8_t chars[]) {
  uint8_t char_array_len = sizeof(chars); // pozor, treba pridať 0 na koniec
  char **random_string_array = (char **)malloc(char_array_len);

  if (random_string_array == NULL) {
    return NULL;
  }

  for (uint8_t i = 0; i < char_array_len; i++) {
    random_string_array[i] = generate_string_array(chars[i]);
    if (random_string_array[i] == NULL) {
      return NULL;
    }
  }

  return random_string_array;
}
