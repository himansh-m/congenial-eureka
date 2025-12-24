#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
  unsigned x, y;
  int p, n;
  printf("Enter x: ");
  scanf("%u", &x);
  printf("Enter p: ");
  scanf("%d", &p);
  printf("Enter n: ");
  scanf("%d", &n);
  printf("Enter y: ");
  scanf("%u", &y);
  printf("Result: %u", setbits(x, p, n, y));
  putchar('\n');
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
  y = (~(~(unsigned)0 << n) & y) << (p - n + 1);
  x = (x & (~(~(~(unsigned)0 << n) << (p - n + 1)))) | y;
  return x;
}
