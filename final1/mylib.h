#ifndef __MY_LIB__
#define __MY_LIB__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

#define MAX_BUFFER_SIZE 512

void rtrim(char *str);

void read_file_content(const char *file_fullpath);
char *transform_line(const char *line);

#endif
