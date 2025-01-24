#include "mylib.h"

#define ARGUMENT_COUNT 3 // commadn + 2 arguments

int main(int argc, char *argv[]) {
  if (argc != ARGUMENT_COUNT) {
    fprintf(stderr, "Error: Exactly 2 arguments wanted!\n");
    return 1;
  }

  if (atoi(argv[2]) < 1) {
    fprintf(
        stderr,
        "Error: Word index must be an INTEGER greater than or equal to 1!\n");
    return 1;
  }

  char *word = select_word(argv[1], atoi(argv[2]));
  if (word == NULL) {
    printf("Word not found!\n");
    return 1;
  }
  printf("%s\n", word);

  free(word);

  return 0;
}
