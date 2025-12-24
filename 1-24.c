#include <stdio.h>

// You know what fuck it I am not doing this. It is too fucking hard for me as
// of right now. I just am currently removing the comments the two types and not
// handling strings. I now have to start with handling the error. So maybe i
// will do it later when i become good enough to write a compiler. I mean who
// the fuck creates a book like this - "The book literally says here are the
// basics now let's build a rudimentary compiler for C in C". Yeah, well fuck
// you.

int main() {

  char program[10000];
  int c, index;
  index = 0;

  while ((c = getchar()) != EOF) {
    if (c != '/') {
      program[index++] = c;
    } else {
      int n;
      n = getchar();
      if (n == '/') {
        while ((n = getchar()) != EOF) {
          if (n == '\n') {
            break;
          }
        }
      } else if (n == '*') {
        while ((n = getchar()) != EOF) {
          if (n == '*' && (n = getchar()) == '/') {
            break;
          }
        }
      } else {
        program[index++] = c;
        program[index++] = n;
      }
    }
  }

  program[index] = '\0';
}
