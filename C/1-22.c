#include <stdio.h>

// This code doesn't work.

int main() {
  char word[81];
  int c, index = 0, charcount = 0;
  word[80] = '\0';

  while ((c = getchar()) != EOF) {
    if ((c != ' ' && c != '\t' && c != '\n') && charcount <= 80) {
      word[index++] = c;
      charcount++;
    } else if (c == ' ' && charcount <= 79) {
      word[index] = '\0';
      printf("%s", word);
      index = 0;
      charcount++;
      putchar(' ');
    } else if (c == '\t' && charcount <= 76) {
      word[index] = '\0';
      printf("%s", word);
      index = 0;
      charcount += 4;
      putchar('\t');
    } else if (c == '\n') {
      word[index] = '\0';
      printf("%s", word);
      index = 0;
      putchar('\n');
      charcount = 0;
    } else if (charcount > 80) {
      putchar('\n');
      if (index > 0) {
        putchar('-');
        word[index] = '\0';
        printf("%s", word);
      }
      index = 0;
    }
  }
}
