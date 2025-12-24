#include <stdio.h>

void intToString(int n, char num[20]) {
  static int i = 0;
  if (n < 0 && i == 0) {
    n = -n;
    num[i++] = '-';
  }
  if (n == 0) {
    if (i != 0) {
      num[i] = '\0';
      return;
    } else {
      num[0] = '0';
      num[1] = '\0';
      return;
    }
  }
  if (n / 10) {
    intToString(n / 10, num);
  }
  num[i++] = (n % 10) + '0';
  return;
}

int main() {
  int n;
  char num[20];
  printf("Enter n: ");
  scanf("%d", &n);
  intToString(n, num);
  printf("Output: %s\n", num);
  return 0;
}
