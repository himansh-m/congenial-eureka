#include <stdio.h>

int main() {
  printf("hello, world!\n");
  return 0;
}

// List of errors:
// 1) On removing the last curly brace :
// 	1-1.c: In function ‘main’:
// 	1-1.c:6:9: error: expected declaration or statement at end of input
// 	    6 |         return 0;
// 	      |         ^~~~~~
//
// 2) On removing a semi-colon :
// 	1-1.c: In function ‘main’:
// 	1-1.c:6:17: error: expected ‘;’ before ‘}’ token
// 	    6 |         return 0
// 	      |                 ^
// 	      |                 ;
// 	    7 | }
// 	      | ~
//
// 3) On removing printf function's bracket:
// 	1-1.c: In function ‘main’:
// 	1-1.c:5:15: error: expected ‘;’ before string constant
// 	    5 |         printf"hello, world!\n");
// 	      |               ^~~~~~~~~~~~~~~~~
// 	      |               ;
// 	1-1.c:5:32: error: expected statement before ‘)’ token
// 	    5 |         printf"hello, world!\n");
// 	      |
