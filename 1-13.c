#include <stdio.h>

#define IN 1
#define OUT 0

// This program has a missing functionality. It counts punctuations marks as
// either words or counts them into word length. Please take into account that
// error. It would be really helpful, if you can remove that bug (not exactly a
// bug but a feature).

int main() {

  int wlength[30];

  printf("Please don't enter a word longer than 30 characters long.\n");

  for (int i = 0; i < 30; i++) {
    wlength[i] = 0;
  }

  int c, state, length;

  length = 0;

  state = IN;

  while ((c = getchar()) != EOF) {
    if (c == '\t' || c == '\n' || c == ' ') {
      if (state == IN) {
        state = OUT;
        if (length > 0 && length < 31) {
          wlength[length - 1]++;
        }
        length = 0;
      }
    } else {
      state = IN;
      length++;
    }
  }

  int max = 0;

  for (int i = 0; i < 30; i++) {
    if (wlength[i] > max) {
      max = wlength[i];
    }
  }

  putchar('\n');

  printf("Word length distribution histogram.\n");

  while (max != 0) {
    for (int i = 0; i < 30; i++) {
      if (i < 10) {
        if (wlength[i] >= max) {
          printf(" # ");
        } else {
          printf("   ");
        }
      } else {
        if (wlength[i] >= max) {
          printf("  # ");
        } else {
          printf("    ");
        }
      }
    }
    max--;
    putchar('\n');
  }

  for (int i = 0; i < 30; i++) {
    if (i < 10) {
      printf("___");
    } else {
      printf("____");
    }
  }

  putchar('\n');

  for (int i = 0; i < 30; i++) {
    printf(" %d ", i + 1);
  }

  putchar('\n');
}
