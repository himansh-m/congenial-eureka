#include <ctype.h>
#include <stdio.h>

int main() {

  int count[26];

  int c;

  for (int i = 0; i < 26; i++) {
    count[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    c = tolower(c);
    if (c <= 'z' && c >= 'a') {
      count[c - 'a']++;
    }
  }

  int max = 0;

  for (int i = 0; i < 26; i++) {
    if (max < count[i]) {
      max = count[i];
    }
  }

  printf("\nCharacter distribution histogram\n");

  while (max != 0) {
    for (int i = 0; i < 26; i++) {
      if (count[i] >= max) {
        printf(" # ");
      } else {
        printf("   ");
      }
    }
    max--;
    putchar('\n');
  }

  for (int i = 0; i < 26; i++) {
    printf("___");
  }

  putchar('\n');

  for (int i = 0; i < 26; i++) {
    putchar(' ');
    putchar(i + 'a');
    putchar(' ');
  }

  putchar('\n');
}
