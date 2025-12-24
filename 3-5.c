#include <stdio.h>

void function(char line[]);

void itob(int n, char s[], int b) {
  // Max Limit b = 36
  unsigned index = 0;
  char sign;
  if (n < 0) {
    sign = '-';
  } else {
    sign = '+';
  }

  while (n) {
    if ((n % b) <= 9) {
      s[index++] = (n % b) + '0';
    } else {
      s[index++] = (n % b) - 9 + 'a';
    }
    n /= b;
  }
  if (sign == '-') {
    s[index++] = '-';
  }
  s[index] = '\0';
  function(s);

  // Use 1-19.c
}

int main() {
  char s[1000];
  int n, b;
  printf("Enter n: ");
  scanf("%d", &n);
  printf("Enter b: ");
  scanf("%d", &b);
  itob(n, s, b);
  printf("Result: %s\n", s);
}
