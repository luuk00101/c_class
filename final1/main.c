#include "mylib.h"

int main(int argc, char *argv[]) {
  char file_buffer[MAX_BUFFER_SIZE];
  bzero(file_buffer, MAX_BUFFER_SIZE);

  printf("Enter the desired file name: ");
  fflush(stdout);
  char *name = fgets(file_buffer, MAX_BUFFER_SIZE, stdin);
  if (name == NULL) {
    perror("Input error!");
    return 1;
  }
  rtrim(file_buffer);

  read_file_content(file_buffer);
}
