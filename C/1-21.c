#include <stdio.h>

#define TAB 4

int main() {
  int c, count;
  count = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      count++;
    } else if (c == '\n') {
      count = 0;
    } else {
      if (count != 0) {
        for (int i = 0; i < (int)(count / TAB); i++) {
          putchar('\t');
        }
        for (int i = 0; i < (int)(count % TAB); i++) {
          putchar(' ');
        }
      }
      count = 0;
      putchar(c);
    }
  }
}
