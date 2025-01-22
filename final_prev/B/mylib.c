#include "mylib.h"

size_t str_length(const char *str) {
  size_t length = 0;
  while (str[length++] != 0)
    ;
  return --length;
}

uint8_t is_punctuation(char c) {
  if ((c == ' ') || (c == ',') || (c == '.') || (c == '!') || (c == '?') ||
      (c == ':') || (c == ';')) {
    return TRUE;
  }
  return FALSE;
}

wret_t get_next_word(const char *str) {
  size_t str_len = str_length(str);
  wret_t ret = {0, NULL};

  for (size_t i = 0; i < str_len; i++) {
    if ((is_punctuation(str[i])) || (str[i] < 32)) {
      if (ret.length > 0) {
        return ret;
      }
      continue;
    }
    if (ret.length == 0) {
      ret.start = (char *)&str[i];
    }
    ret.length++;
  }

  return ret;
}
