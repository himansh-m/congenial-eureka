#include <ctype.h>
#include <stdio.h>
#include <string.h>

/*Filled with so many errors god know why I created this.*/

void expand(char s1[], char s2[]);

int main() {}

void expand(char s1[], char s2[]) {

  size_t i, length = strlen(s1), index = 0;

  if (s1[length - 1] == '-') {
    length--;
  }

  if (s1[0] == '-') {
    i = 1;
  } else {
    i = 0;
  }

  for (; i < length; i++) {
    if (isalnum(s1[i]) && s1[i + 1] == '-' && isalnum(s1[i + 2])) {
      for (int z = s1[i]; z <= s1[i + 2]; z++) {
        s2[index++] = z;
      }
    }
  }

  s2[index] = '\0';
}
