#ifndef __MY_LIB__
#define __MY_LIB__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

typedef struct {
  uint8_t length;
  char *start;
} wret_t;

size_t str_length(const char *str);
uint8_t is_punctuation(char c);
wret_t get_next_word(const char *str);

#endif
