#include <stdio.h>

// This doesn't handle strings.

int main() {
  char program[10000];
  int c, index;
  index = 0;

  while ((c = getchar()) != EOF) {
    if (c != '/') {
      program[index++] = c;
    } else {
      int n;
      n = getchar();
      if (n == '/') {
        while ((n = getchar()) != EOF) {
          if (n == '\n') {
            break;
          }
        }
      } else if (n == '*') {
        while ((n = getchar()) != EOF) {
          if (n == '*' && (n = getchar()) == '/') {
            break;
          }
        }
      } else {
        program[index++] = c;
        program[index++] = n;
      }
    }
  }

  program[index] = '\0';
  printf("%s", program);
  return 0;
}
