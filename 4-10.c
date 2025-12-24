#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define getline getlinesecond

double stack[100];
int ptrstack = 0;
double variable[26];

bool getline(char line[100]);
size_t splittokens(char line[100], char tokens[100][10]);
void push(double value);
double pop(void);

int main() {
  char line[100];
  char tokens[100][10];
  bool proceed = true;
  size_t ntokens;
  char last = 0;
  while (proceed) {
    proceed = getline(line);
    ntokens = splittokens(line, tokens);
    for (size_t i = 0; i < ntokens; i++) {
      if (isdigit(tokens[i][0]) ||
          (tokens[i][0] == '-' && isdigit(tokens[i][1]))) {
        push(atof(tokens[i]));
      } else if (isalpha(tokens[i][0])) {
        if (strlen(tokens[i]) > 1) {
          if (strcmp(tokens[i], "sin") == 0) {
            push(sin(pop()));
          } else if (strcmp(tokens[i], "exp") == 0) {
            push(exp(pop()));
          } else if (strcmp(tokens[i], "pow") == 0) {
            double op2 = pop();
            push(pow(pop(), op2));
          } else {
            printf("Unknown Command");
          }

        } else {
          push(variable[(int)(tokens[i][0] - 'a')]);
          last = tokens[i][0];
        }
      } else {
        if (strlen(tokens[i]) == 1) {
          if (strcmp(tokens[i], "+") == 0) {
            push(pop() + pop());
          } else if (strcmp(tokens[i], "-") == 0) {
            double op2 = pop();
            push(pop() - op2);
          } else if (strcmp(tokens[i], "/") == 0) {
            double op2 = pop();
            push(pop() / op2);
          } else if (strcmp(tokens[i], "*") == 0) {
            push(pop() * pop());
          } else if (strcmp(tokens[i], "=") == 0) {
            if (last) {
              double op = pop();
              variable[(int)(last - 'a')] = op;
              push(op);
            } else {
              printf("No variable to assign\n");
            }
          }

        } else {
          printf("Not a valid operation");
        }
      }
    }
    printf("Ans: \t%.8g\n", stack[ptrstack - 1]);
  }
  return 0;
}

double pop(void) {
  if (ptrstack > 0) {
    return stack[--ptrstack];
  } else {
    printf("Underflow\n");
    return 0.0;
  }
}

void push(double value) {
  if (ptrstack < 100) {
    stack[ptrstack++] = value;
  } else {
    printf("Overflow\n");
  }
}

bool getline(char line[100]) {
  int index = 0, c;
  while (((c = getchar()) != EOF) && (c != '\n')) {
    line[index++] = c;
  }
  line[index] = '\0';
  return c != EOF;
}

size_t splittokens(char line[100], char tokens[100][10]) {
  size_t len = strlen(line), i = 0, index = 0, tnum = 0;
  char temp[10];
  while (i < len) {
    if (line[i] == ' ' || line[i] == '\t') {
      temp[index] = '\0';
      index = 0;
      if (strlen(temp) > 0) {
        strcpy(tokens[tnum++], temp);
      }
    } else {
      temp[index++] = line[i];
    }
    i++;
  }
  if (index > 0) {
    temp[index] = '\0';
    strcpy(tokens[tnum++], temp);
  }

  return tnum;
}
