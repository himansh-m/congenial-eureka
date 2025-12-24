#include <stdio.h>

int main() {
  printf("%d\n", getchar() != EOF);
  printf("%d\n", getchar() != EOF);
}

// On entering a newline character and ctrl+D to signal EOF, the result was 0 1.
// On all else occurences and character input it will be 1 1. So, we get that
// getchar() != EOF is either 0 or 1. This has been confirmed.
