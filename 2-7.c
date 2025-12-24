#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {
  unsigned x;
  printf("Enter x: ");
  scanf("%u", &x);

  int p;
  printf("Enter p: ");
  scanf("%d", &p);

  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  printf("Result: %u\n", invert(x, p, n));
  return 0;
}

unsigned invert(unsigned x, int p, int n) {
  unsigned mask = ~(~0u << n) << (p - n + 1);
  x = x ^ mask;
  return x;
}
