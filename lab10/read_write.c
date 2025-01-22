#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "myfile.txt"

int main(int argc, char *argv[]) {

  FILE *fs = fopen(FILENAME, "w");
  if (fs == NULL) {
    perror("Could not open file!\n");
    return 1;
  }

  for (uint8_t i = 1; i < argc; i++) {
    size_t wnum = fwrite(argv[i], 1, strlen(argv[i]), fs);
    fwrite("\n", 1, 1, fs);
    printf("Written %lu bytes to the file.\n", wnum);
  }

  char readchar = 0;
  while (fread(&readchar, 1, 1, fs)) {
    if (readchar <= 32) {
      printf(" ");
    } else {
      printf("%c", readchar);
    }
  }

  fclose(fs);
  return 0;
}
