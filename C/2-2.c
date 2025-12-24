#include <stdio.h>

#define lim 1000

int main() {
  int i, c;
  char s[lim];

  for (i = 0; (i < lim - 1) * ((c = getchar()) != '\n') * (c != EOF); ++i)
    s[i] = c;
  s[++i] = '\0';
  printf("%s", s);
  return 0;
}
