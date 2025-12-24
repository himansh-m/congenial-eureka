#include <stdbool.h>
#include <stdio.h>

int any(char s1[], char s2[]);
bool present(char c, char s2[], int length);

int main() {
  char s1[1000], s2[1000];
  int i = 0, j = 0, c;
  printf("Enter s1: ");
  while ((c = getchar()) != '\n') {
    s1[i++] = c;
  }
  printf("Enter s2: ");
  while ((c = getchar()) != '\n') {
    s2[j++] = c;
  }
  printf("Index returned by function any: %d\n", any(s1, s2));
  return 0;
}

int any(char s1[], char s2[]) {

  int s2length, s1length;
  int i = 0, j = 0;
  while (s1[i++] != '\0')
    ;
  while (s2[j++] != '\0')
    ;
  s1length = i + 1;
  s2length = j + 1;

  for (int k = 0; k < s2length; k++) {
    if (present(s2[k], s1, s1length)) {
      for (int l = 0; l < s1length; l++) {
        if (s1[l] == s2[k]) {
          return l;
        }
      }
    }
  }

  return -1;
}

bool present(char c, char s2[], int length) {
  for (int i = 0; i < length; i++) {
    if (c == s2[i]) {
      return true;
    }
  }
  return false;
}
