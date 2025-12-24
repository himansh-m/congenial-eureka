#include <stdio.h>

#define swap(t, x, y)                                                          \
  {                                                                            \
    t xy = x;                                                                  \
    x = y;                                                                     \
    y = xy;                                                                    \
  }

int main() {
  float x;
  printf("Enter x: ");
  scanf("%g", &x);
  float y;
  printf("Enter y: ");
  scanf("%g", &y);
  swap(float, x, y);
  printf("x: %f\ny: %f\n", x, y);
  return 0;
}
