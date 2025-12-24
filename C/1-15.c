#include <stdio.h>

float convert(float fahr) {
  fahr -= 32.0;
  fahr *= (5.0 / 9.0);
  return fahr;
}

int main() {
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  
  float fahr, celsius;
  fahr = lower;
  while (fahr <= upper) {
    celsius = convert(fahr);
    printf("%3.0f %6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
