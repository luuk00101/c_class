#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PTR_ARRAY 10
#define MAX_STR_LEN 10

int main(int argc, char *argv[]) {

  char *parray[MAX_PTR_ARRAY];

  char *str1 = (char *)malloc(MAX_STR_LEN);
  if (str1 == NULL) {
    perror("Allocation error.\n");
    return 1;
  }

  memset(str1, 0, MAX_STR_LEN);
  strcpy(str1, "AHOJ SVET");

  parray[0] = str1;

  printf("Address: %p\n", parray);
  printf("Address: %p\n", parray[0]);

  printf("First character of first word: %c\n", parray[0][0]);
  printf("Second character of first word: %c\n", *(parray[0] + 1));
  printf("First word /wout brackets: %s\n", *parray);
  printf("First word /w brackets: %s\n", parray[0]);

  return 0;
}
