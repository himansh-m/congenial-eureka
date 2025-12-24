#include <stdio.h>

int bitcount(unsigned x);

int main() {
  printf("Enter x: ");
  unsigned x;
  scanf("%u", &x);
  printf("Result: %d\n", bitcount(x));
  return 0;
}

int bitcount(unsigned x) {
  int setbits = 0;
  while (x) {
    x &= (x - 1);
    setbits++;
  }
  return setbits;
}

// x &= (x - 1) removes the rightmost set bit of x.
// When you subtract 1 from x, all bits to the right of the lowest set bit flip,
// and the lowest set bit itself becomes 0. AND-ing this result with the
// original x keeps all higher bits the same but clears that one lowest set
// bit—effectively deleting it.
