#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MAX_BUFFER_SIZE 512

void rtrim(char *str);

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

  char text_buffer[MAX_BUFFER_SIZE];
  bzero(text_buffer, MAX_BUFFER_SIZE);

  printf("Enter the desired text: ");
  fflush(stdout);
  char *text = fgets(text_buffer, MAX_BUFFER_SIZE, stdin);
  if (text == NULL) {
    perror("Input error!");
    return 1;
  }
  rtrim(text_buffer);

  FILE *fs = fopen(file_buffer, "w");
  if (fs == NULL) {
    perror("Could not open file!\n");
    return 1;
  }

  for (size_t i = 0; i < MAX_BUFFER_SIZE; i++) {
    if (text_buffer[i] == 0)
      break;
    if (text_buffer[i] == 32)
      fwrite("\t", 1, 1, fs);
    else
      fwrite(&text_buffer[i], 1, 1, fs);
  }
  fwrite("\n", 1, 1, fs);

  fclose(fs);
  return 0;
}

void rtrim(char *str) {
  size_t str_len = strlen(str);

  for (size_t i = str_len - 1; i >= 0; i--) {
    if (str[i] < 32) {
      str[i] = 0;
    } else {
      return;
    }
  }
}
