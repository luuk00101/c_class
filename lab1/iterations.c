#include <stdio.h>

int main() {
  int a = 10;
  int b = 25;

  int iteration = 1;

  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("%d.th Hello, world!\n", iteration);
      iteration++;
    }
  }

  return 0;
}
