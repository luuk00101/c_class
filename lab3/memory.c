#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LENGTH 10

int main(int argc, char *argv[]) {

  char *greeting = "Hello";

  char *str = NULL;
  str = (char *)malloc(STR_MAX_LENGTH);
  if (str == NULL) {
    printf("Memory allocation failed\n");
    return 1;
  }

  // Toto mi všade napchá \0, takže to viem použiť na detekovanie konca stringu
  bzero(str, STR_MAX_LENGTH + 1);

  *str = 'A';
  str[1] = 'H';
  *(str + 2) = 'O';
  str[1 + 2] = 'J';

  printf("%s\n", str);

  // dereferencujem cez []
  for (int i = 0; i < 2; i++) {
    printf("%c", str[i]);
  }
  printf("\n");

  // použijeme pointrovú aritmetiku
  for (int i = 0; i < 2; i++) {
    printf("%c", *(str + i));
  }
  printf("\n");

  if (str != NULL) {
    free(str);
  }

  return 0;
}
