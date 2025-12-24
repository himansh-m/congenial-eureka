#include <stdio.h>

int main() {
  int c, tabs, spaces, newlines;
  tabs = spaces = newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      spaces++;
    else if (c == '\t')
      tabs++;
    else if (c == '\n')
      newlines++;
  }

  printf("Number of tabs: %d\nNumber of spaces: %d\nNumber of newlines: %d\n",
         tabs, spaces, newlines);
}
