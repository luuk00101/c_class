#include <stdint.h>
#include <string.h>
#include <unistd.h>

#include "mylib.h"

#define MAX_BUF_LEN 256

int main(int argc, char *argv[]) {
  char buffer[MAX_BUF_LEN];
  memset(buffer, 0, MAX_BUF_LEN);

  printf("Insert some text: ");
  fflush(stdout);
  char *ret = fgets(buffer, MAX_BUF_LEN, stdin);
  if (ret == NULL) {
    perror("Buffer not ready!\n");
    return EXIT_FAILURE;
  }

  char *act_pos = buffer;
  while (1) {
    wret_t word = get_next_word(act_pos);
    if (word.length == 0) {
      printf("%s\n", act_pos);
      break;
    }
    if (word.start > act_pos) {
      fwrite(act_pos, 1, (word.start - act_pos), stdout);
    }
    printf("%d", word.length);
    act_pos = word.start + word.length;
  }

  return EXIT_SUCCESS;
}
