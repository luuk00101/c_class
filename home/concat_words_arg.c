#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *form_word(int argc, char *argv[]);

int main(int argc, char *argv[]) {

  char *concatenated_string = form_word(argc, argv);
  if (concatenated_string == NULL) {
    return 1;
  }

  printf("The concatenated string: %s", concatenated_string);
  free(concatenated_string);

  return 0;
}

char *form_word(int argc, char *argv[]) {

  int final_len = 1; // 1 for NULL
  for (int i = 1; i < argc; i++) {
    int current_len = strlen(argv[i]);

    final_len += current_len;
  }

  char *final_string = malloc(final_len);
  if (final_string == NULL) {
    printf("Failed to allocate memory!");
    return NULL;
  }

  bzero(final_string, final_len);

  int turn = 1;
  int indices[argc];
  memset(indices, 0, sizeof(indices));

  for (int i = 0; i < final_len - 1; i++) {
    while (indices[turn] == strlen(argv[turn])) {
      turn++;
    }

    final_string[i] = argv[turn][indices[turn]];

    indices[turn]++;
    turn++;
    if (turn >= argc) {
      turn = 1;
    }
  }

  return final_string;
}
