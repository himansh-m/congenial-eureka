#include <ctype.h>
#include <stdio.h>
#include <string.h>

double atof(char line[]);
double tpow(int x);

int main() {
  printf("Enter the number: ");
  char line[100];
  int index = 0, c;
  while (((c = getchar()) != EOF) && (c != '\n')) {
    line[index++] = c;
  }
  line[index] = '\0';
  printf("%f", atof(line));
}

double atof(char s[]) {
  double val, power, result;
  int i, sign, exp;

  for (i = 0; isspace(s[i]); i++)
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  result = sign * val / power;
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  if (s[i] == '-' || s[i] == '+') {
    sign = (s[i] == '-') ? -1 : 1;
    i++;
  }
  for (exp = 0; isdigit(s[i]); i++) {
    exp = exp * 10 + (s[i] - '0');
  }
  exp *= sign;
  result *= tpow(exp);
  return result;
}

double tpow(int x) {
  double answer = 1;
  if (x < 0) {
    for (int i = 0; i < (-1 * x); i++) {
      answer /= 10;
    }
  } else {
    for (int i = 0; i < x; i++) {
      answer *= 10;
    }
  }
  return answer;
}
