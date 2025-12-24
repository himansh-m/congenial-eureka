#include <stdio.h>
#include <string.h>
void reverse(char[]);
int main() {
  printf("Enter the string: ");
  char string[1000];
  scanf("%s", &string);
  reverse(string);
  printf("The reversed string: %s\n", string);
  return 0;
}
void reverse(char string[]) {
  size_t len = strlen(string);
  static size_t index = 0;
  if (index < len / 2) {
    char temp = string[index];
    string[index] = string[len - index - 1];
    string[len - index - 1] = temp;
    index++;
    reverse(string);
  }
}
