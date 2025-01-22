#include "mylib.h"

size_t str_length(const char *str) {
  size_t length = 0;
  while (str[length++] != 0)
    ;
  return --length;
}

word_stat_t get_text_stat(const char *str) {
  word_stat_t stat = {.num_words = 0, .num_wchars = 0, .num_tchars = 0};

  size_t s_len = str_length(str);
  uint8_t is_word = 0;

  for (size_t i = 0; i < s_len; i++) {
    if ((str[i] == ' ') && (is_word)) {
      stat.num_words++;
      is_word = 0;
    } else {
      if (((str[i] >= '0') && (str[i] <= '9')) ||
          ((str[i] >= 'A') && (str[i] <= 'Z')) ||
          ((str[i] >= 'a') && (str[i] <= 'z'))) {
        is_word = 1;
        stat.num_wchars++;
      }
      if (str[i] > 32) {
        stat.num_tchars++;
      }
    }
  }
  if (is_word)
    stat.num_words++;

  return stat;
}
