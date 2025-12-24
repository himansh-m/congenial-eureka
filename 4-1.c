// This is fucking unsafe and the logic is hard to guess, that is what the ai is
// telling me, but i say fuck the ai and i will code like this.

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool check(char s[], char t[]);

int strrindex(char s[], char t[]);

int main() {
  int c = 0, i = 0;
  char s[1000];
  printf("Enter s: ");
  while ((c = getchar()) != '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  i = 0;
  char t[1000];
  printf("Enter t: ");
  while ((c = getchar()) != '\n') {
    t[i++] = c;
  }
  t[i] = '\0';
  printf("Result: %d\n", strrindex(s, t));
  return 0;
}

int strrindex(char s[], char t[]) {
  size_t slen = strlen(s), tlen = strlen(t), i = 0;
  if (tlen > slen) {
    return -1;
  } else if (tlen == slen && check(s, t)) {
    return 0;
  } else if (tlen == slen) {
    return -1;
  }
  int result = -1;
label:
  for (; i <= slen - tlen; i++) {
    int n = i + tlen;
    for (int j = i; j < n; j++) {
      if (s[j] == t[j - i]) {
        ;
      } else {
        i++;
        goto label;
      }
    }
    result = i;
  }
  return result;
}

bool check(char s[], char t[]) {
  size_t r = strlen(s);
  for (size_t i = 0; i < r; i++) {
    if (s[i] != t[i]) {
      return false;
    }
  }
  return true;
}
