#include <string.h>

#include <stdio.h>

void function(char s[]);

void itoa(int n, char s[], int w) {
  int i, sign;

  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0;

  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0) {
    s[i++] = '-';
  }
  while (i < w) {
    s[i++] = ' ';
  }

  s[i] = '\0';
  function(s);
}

int main() {
  int n, w;
  char s[100];

  printf("Enter the int: ");
  scanf("%d", &n);
  printf("Enter width: ");
  scanf("%d", &w);
  itoa(n, s, w);
}
