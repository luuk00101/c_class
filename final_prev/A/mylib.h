#ifndef __MY_LIB__
#define __MY_LIB__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
  uint16_t num_words;
  uint16_t num_wchars;
  uint16_t num_tchars;
} word_stat_t;

size_t str_length(const char *str);
word_stat_t get_text_stat(const char *str);

#endif
