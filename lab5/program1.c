#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char *my_array = "Ahoj svet";
  char **p_my_array = &my_array;

  printf("Hodnota my_array: %s\n", my_array);
  printf("Adresa my_array: %p\n", (void *)my_array);
  printf("Hodnota p_my_array: %p\n", (void *)p_my_array);
  printf("Adresa p_my_array: %p\n", (void *)&p_my_array);
  printf("Hodnota *p_my_array: %s\n", *p_my_array);

  return 0;
}
