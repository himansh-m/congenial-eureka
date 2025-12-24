#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);
void reverse(char t[], char s[]);

int main() {}

void escape(char s[], char t[]) {
  int index = 0;
  size_t i, z = strlen(s);
  for (i = 0; i < z; i++) {
    switch (s[i]) {
    case '\n':
      t[index++] = '\\';
      t[index++] = 'n';
      break;
    case '\t':
      t[index++] = '\\';
      t[index++] = 't';
      break;
    default:
      t[index++] = s[i];
      break;
    }
  }
  t[index] = '\0';
}

void reverse(char t[], char s[]) {
  int index = 0;
  size_t i, z = strlen(t);
  for (i = 0; i < z; i++) {
    switch (t[i]) {
    case '\\':
      if (t[i + 1] == 'n') {
        s[index++] = '\n';
        i++;
      } else if (t[i + 1] == 't') {
        s[index++] = '\t';
        i++;
      } else {
        s[index++] = '\\';
      }
      break;
    default:
      s[index++] = t[i];
      break;
    }
  }
  s[index] = '\0';
}
