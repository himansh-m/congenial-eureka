#include <stdio.h>

int main() {
  printf("\c");
  return 0;
}

// It only gives a warning as mentioned below:
//
// 	1-2.c: In function ‘main’:
// 	1-2.c:5:20: warning: unknown escape sequence: '\c'
// 	    5 |         printf("\c");
// 	      |
//
// The output is:
//
// 	c
//
// Result:
//
// 	The program runs but it generates a warning of unknown escape sequence
// and then prints the string omitting the backslash("\").       ^
