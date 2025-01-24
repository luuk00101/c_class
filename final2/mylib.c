#include "mylib.h"

uint8_t is_word_char(char c) {
  if (((c >= '0') && (c <= '9')) || ((c >= 'A') && (c <= 'Z')) ||
      ((c >= 'a') && (c <= 'z')) || (c == '-')) {
    return TRUE;
  }
  return FALSE;
}

char *select_word(const char *text, int count) {
  int word_count = 0;
  int is_word = 0;
  size_t start = 0;
  size_t text_len = strlen(text);

  for (size_t i = 0; i < text_len; i++) {
    if (is_word_char(text[i])) {
      if (!is_word) {
        word_count++;
        is_word = 1;
        start = i; // continually move the start index of the potential word

        if (word_count == count) {
          size_t end = i;
          while (end < text_len && is_word_char(text[end])) {
            end++;
          }

          size_t word_len = end - start;
          char *word = malloc(word_len + 1);
          if (word == NULL) {
            fprintf(stderr,
                    "Error: Couldn't allocate memory for the new word!\n");
            return NULL;
          }

          memcpy(word, text + start, word_len);
          word[word_len] = '\0';
          return word;
        }
      }
    } else { // found a non-word character
      is_word = 0;
    }
  }

  // if no character is the a word character
  return NULL;
}
