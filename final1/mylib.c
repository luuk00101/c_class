#include "mylib.h"
#include <stdio.h>

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

uint8_t is_char(char c) {
  if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z'))) {
    return TRUE;
  }
  return FALSE;
}

uint8_t have_word(const char *line) {
  size_t index = 0;
  while (line[index] != '\n' && line[index] != '\0') {
    if (is_char(line[index])) {
      return TRUE;
    }
  }
  return FALSE;
}

void read_file_content(const char *file_fullpath) {
  FILE *fs = fopen(file_fullpath, "r");
  if (fs == NULL) {
    perror("Could not open file!\n");
    return;
  }

  char line[MAX_BUFFER_SIZE];
  bzero(line, MAX_BUFFER_SIZE);

  uint8_t have_words = FALSE;
  while (fgets(line, MAX_BUFFER_SIZE, fs)) {
    if (have_word(line)) {
      have_words = TRUE;
      break;
    }
  }
  if (!have_words) {
    printf("Empty file!\n");
    return;
  }

  rewind(fs); // get back to start of the file
  bzero(line, MAX_BUFFER_SIZE);

  while (fgets(line, MAX_BUFFER_SIZE, fs)) {
    char *new_line = transform_line(line);
    printf("%s", new_line);
    free(new_line);
    bzero(line, MAX_BUFFER_SIZE);
  }
}

char *transform_line(const char *line) {
  char *new_line = (char *)malloc(MAX_BUFFER_SIZE);
  bzero(new_line, MAX_BUFFER_SIZE);

  uint8_t written_chars = 0;
  char new_word[MAX_BUFFER_SIZE];
  bzero(new_word, MAX_BUFFER_SIZE);
  uint8_t new_word_len = 0;
  uint8_t has_char = FALSE;

  size_t index = 0;

  while (line[index] != '\n' && line[index] != '\0') {
    if (line[index] == ' ') {
      if (new_word_len > 0) {
        if (has_char) {
          new_line[written_chars] = new_word[0];
          written_chars++;

          if (new_word_len > 2) {
            memset(new_line + written_chars, '-', new_word_len - 2);
            written_chars += new_word_len - 2;
          }

          if (new_word_len > 1) {
            new_line[written_chars] = new_word[new_word_len - 1];
            written_chars++;
          }
        } else {
          memcpy(new_line + written_chars, new_word, new_word_len);
          written_chars += new_word_len;
        }

        if (line[index] == ' ') {
          new_line[written_chars] = ' ';
          written_chars++;
        }
      }

      bzero(new_word, MAX_BUFFER_SIZE);
      new_word_len = 0;
      has_char = FALSE;
    } else { // increasing the new_word_len
      new_word[new_word_len] = line[index];
      if (is_char(line[index])) {
        has_char = TRUE;
      }
      new_word_len++;
    }
    index++;
  }

  // last word
  if (new_word_len > 0) {
    if (has_char) {
      new_line[written_chars++] = new_word[0];

      if (new_word_len > 2) {
        memset(new_line + written_chars, '-', new_word_len - 2);
        written_chars += new_word_len - 2;
      }

      if (new_word_len > 1) {
        new_line[written_chars++] = new_word[new_word_len - 1];
      }
    } else {
      memcpy(new_line + written_chars, new_word, new_word_len);
      written_chars += new_word_len;
    }
  }

  new_line[written_chars] = '\n';
  written_chars++;
  new_line[written_chars] = '\0';

  return new_line;
}
