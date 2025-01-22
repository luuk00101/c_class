#include <_stdio.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#define MAX_BUFFER_LEN 512

void deleteNewLine(char *buffer);
void replace_vowels(char *str);

int main(int argc, char *argv[]) {
  char buffer[MAX_BUFFER_LEN];
  bzero(buffer, MAX_BUFFER_LEN);

  printf("Insert some text: ");
  fflush(stdout);
  char *ret = fgets(buffer, MAX_BUFFER_LEN, stdin);
  if (ret == NULL) {
    printf("Input error");
    return 1;
  }

  deleteNewLine(buffer);
  printf("Original text: %s\n", buffer);
  replace_vowels(buffer);
  printf("New text: %s\n", buffer);

  return 0;
}

void deleteNewLine(char *buffer) { buffer[strcspn(buffer, "\n")] = 0; }

void replace_vowels(char *str) {
  size_t str_len = strlen(str);
  char vowels[] = "aeiou";
  char *vowel_ptr;

  for (size_t i = 0; i < strlen(vowels); i++) {
    vowel_ptr = strchr(str, vowels[i]);

    while (vowel_ptr != NULL) {
      str[vowel_ptr - str] = '_';
      vowel_ptr = strchr(vowel_ptr + 1, vowels[i]);
    }
  }
}
