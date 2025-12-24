#include <stdio.h>

#define TAB 6

int main() {
  int c, count;
  count = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (int i = 0; i < TAB - (count % TAB); i++) {
        putchar(' ');
        count++;
      }
    } else if (c == '\n') {
      putchar('\n');
      count = 0;
    } else {
      putchar(c);
      count++;
    }
  }
}
