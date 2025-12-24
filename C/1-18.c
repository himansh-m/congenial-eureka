#include <stdio.h>
#include <string.h>

void function(char line[]);

int main() {
  char line[10000];
  int c, index = 0;
  while ((c = getchar()) != EOF) {
    if (c != '\n') {
      line[index++] = c;
    } else {
      line[index] = '\0';
      function(line);
      index = 0;
    }
  }
}

void function(char line[]) {
  for (int i = strlen(line) - 1; i >= 0; i++) {
    if (line[i] != '\t' && line[i] != ' ') {
      break;
    } else {
      line[i] = '\0';
    }
  }
  if (strlen(line) != 0) {
    printf("%s\n", line);
  }
}
