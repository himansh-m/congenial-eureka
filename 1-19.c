#include <stdio.h>
#include <string.h>

void function(char line[]);

// int main()
// {
// 	int c, index = 0;
// 	char line[10000];
//
// 	while ((c = getchar()) != EOF) {
// 		if (c != '\n') {
// 			line[index++] = c;
// 		} else {
// 			line[index] = '\0';
// 			index = 0;
// 			function(line);
// 		}
// 	}
// }

void function(char line[]) {
  size_t length = strlen(line);
  for (int i = 0; i < (int)(length / 2); i++) {
    char temp = line[i];
    line[i] = line[length - 1 - i];
    line[length - 1 - i] = temp;
  }
  printf("%s\n", line);
}
