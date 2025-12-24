#include <stdbool.h>
#include <stdio.h>
int main() {
  int c;
  bool status = false;

  while ((c = getchar()) != EOF) {
    if (c != ' ' && status == true) {
      putchar(c);
      status = false;
    } else if (c != ' ' && status == false) {
      putchar(c);
    } else {
      if (status == false) {
        status = true;
        putchar(c);
      }
    }
  }
}
