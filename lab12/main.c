#include "mylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    perror("Wrong argument count!\n");
    return 1;
  }

  char *str1 = argv[1];
  char *str2 = argv[2];

  printf("First string: %s\n", str1);
  printf("Second string: %s\n", str2);

  char *new_str = remove_duplicates(str1, str2);
  if (new_str == NULL) {
    return 1;
  }

  printf("FINAL string: %s\n", new_str);

  free(new_str);
  return 0;
}
