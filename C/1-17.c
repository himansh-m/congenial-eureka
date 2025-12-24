#include <stdio.h>

int main() {

  int c, i, rep;
  char line[81];
  i = 0;
  rep = 0;

  line[80] = '\0';

  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      i = 0;
      rep = 0;
      putchar('\n');
    }
    if (i < 80) {
      line[i++] = c;
    } else {
      if (rep == 0) {
        printf("%s", line);
        rep = 1;
      }
      putchar(c);
    }
  }
}
