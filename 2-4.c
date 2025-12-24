#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void squeeze(char s1[], char s2[]);
bool find(char c, const char s2[]);

int main() {
  char s1[1000], s2[1000];
  int i = 0, c;
  printf("Enter s1: ");
  while ((c = getchar()) != '\n') {
    s1[i++] = c;
  }
  s1[i] = '\0';
  i = 0;
  printf("Enter s2: ");
  while ((c = getchar()) != '\n') {
    s2[i++] = c;
  }
  s2[i] = '\0';
  squeeze(s1, s2);
  printf("Resultant s1: %s\n", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!(find(s1[i], s2))) {
      s1[j++] = s1[i];
    }
    s1[j] = '\0';
  }
}

bool find(char c, const char s2[]) {
  for (size_t i = 0; i < strlen(s2); i++) {
    if (s2[i] == c) {
      return true;
    }
  }
  return false;
}
