#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mirror_string(const char *str);

int main(int argc, char *argv[]) {

  char str[] = "Lukas";
  printf("String: %s\n", str);

  char *new_string = mirror_string(str);
  if (new_string == NULL) {
    return 1;
  }

  printf("New string: %s\n", new_string);
  free(new_string);

  return 0;
}

char *mirror_string(const char *str) {
  size_t str_len = strlen(str);
  char *mirrored_string = malloc(str_len + 1); // + 1 for NULL

  if (mirrored_string == NULL) {
    printf("Failed to malloc!!");
    return NULL; // since mirrored_string if already NULL
  }

  size_t str_i = 0;
  for (size_t i = str_len - 1; i >= 0; i--) {
    mirrored_string[i] = str[str_i];
    str_i++;
  }

  return mirrored_string;
}
