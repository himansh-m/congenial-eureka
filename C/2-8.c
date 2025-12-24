#include <stdio.h>

int rightrot(unsigned x, int n);

int main() {
  unsigned x;
  printf("Enter x: ");
  scanf("%u", &x);

  int n;
  printf("Enter n: ");
  scanf("%d", &n);

  printf("Result: %d\n", rightrot(x, n));

  return 0;
}

int rightrot(unsigned x, int n) {
  while (n) {
    unsigned extra = x & 1u;
    x = x >> 1;
    extra = extra << (sizeof(unsigned) * 8 - 1);
    x = x | extra;
    --n;
  }
  return x;
}
