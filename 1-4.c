#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, step, upper;

  lower = 0;
  step = 20;
  upper = 300;

  celsius = lower;
  printf("Celsius\t\tFahrenheit\n");

  while (celsius <= upper) {
    fahr = (celsius * (9.0 / 5.0)) + 32.0;
    printf("%3.0f\t \t%6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
