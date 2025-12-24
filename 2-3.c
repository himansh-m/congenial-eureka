#include <math.h>
#include <stdio.h>
#include <string.h>

#define lim 1000

void reverse(char num[]);

int main() {
  int c, i;
  char num[lim];

  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    num[i] = c;
  }

  num[i] = '\0';

  if (num[0] == '0') {
    if (num[1] == 'X' || num[1] == 'x') {
      reverse(num);
      num[strlen(num) - 2] = '\0';
      reverse(num);

    } else {
      reverse(num);
      num[strlen(num) - 1] = '\0';
      reverse(num);
    }
  }

  size_t length = strlen(num);
  int answer = 0;
  for (size_t j = 0; j < length; ++j) {
    int curr = (int)(pow(16, (length - j - 1)));
    if (num[j] <= '9' && num[j] >= '0') {
      answer += (int)(num[j] - '0') * curr;
    } else if (num[j] <= 'F' && num[j] >= 'A') {
      answer += (int)(num[j] - 'A' + 10) * curr;
    } else if (num[j] <= 'f' && num[j] >= 'a') {
      answer += (int)(num[j] - 'a' + 10) * curr;
    } else {
      printf("Print a valid number");
      break;
    }
  }

  printf("\nDecimal version: %d\n", answer);
  return 0;
}

void reverse(char num[]) {
  size_t length = strlen(num);
  for (size_t i = 0; i < (size_t)(length / 2); i++) {
    char temp = num[i];
    num[i] = num[length - 1 - i];
    num[length - 1 - i] = temp;
  }
}
