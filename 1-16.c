#include <stdio.h>
#define MAXLINE 1000

int rgetline(char line[]);
void copy(char to[], char from[]);

int main() {
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = rgetline(line)) > 0) {
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  }
  if (max > 0) {
    printf("%s\n", longest);
    printf("%d\n", max);
  }
  return 0;
}

int rgetline(char s[]) {
  int c, i;
  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < MAXLINE - 1) {
      s[i] = c;
    }
  }
  if (c == '\n') {
    if (i < MAXLINE - 1) {
      s[i] = c;
    }
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]) {
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
