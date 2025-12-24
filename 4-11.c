#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define MAXVAL 100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
double variables[26];
double last = 0.0;

static char buf[BUFSIZE];
static int bufp = 0;

int getop(char[]);
int getch(void);
void ungetch(int);
void push(double);
double pop(void);
void ungets(char[]);
int main(void) {
  int type;
  double op2;
  char s[MAXOP];

  printf("RPN Calculator (K&R 4-6)\n");

  while ((type = getop(s)) != EOF) {
    switch (type) {

    case NUMBER:
      push(atof(s));
      break;

    case NAME:
      if (strcmp(s, "sin") == 0)
        push(sin(pop()));
      else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
      else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
      } else
        printf("error: unknown command %s\n", s);
      break;

    case '+':
      push(pop() + pop());
      break;

    case '*':
      push(pop() * pop());
      break;

    case '-':
      op2 = pop();
      push(pop() - op2);
      break;

    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;

    case '_':
      push(last);
      break;

    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: zero divisor\n");
      break;

    case '=':
      variables[s[0] - 'a'] = pop();
      break;

    case '\n':
      last = pop();
      printf("\t%.8g\n", last);
      break;

    default:
      if (islower(type))
        push(variables[type - 'a']);
      else
        printf("error: unknown command %c\n", type);
      break;
    }
  }
  return 0;
}

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full\n");
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getop(char s[]) {
  int i = 0;
  int c, next;

  while ((c = getch()) == ' ' || c == '\t')
    ;

  s[i++] = c;
  s[i] = '\0';

  if (c == '_') {
    s[0] = '_';
    s[1] = '\0';
    return '_';
  }
  if (islower(c)) {
    while (islower(s[i++] = c = getch()))
      ;
    s[i - 1] = '\0';
    if (c != EOF)
      ungetch(c);
    return NAME;
  }

  if (c == '-') {
    next = getch();
    if (!isdigit(next) && next != '.') {
      ungetch(next);
      return '-';
    }
    s[i++] = next;
    c = next;
  }

  if (!isdigit(c) && c != '.')
    return c;

  while (isdigit(c = getch()))
    s[i++] = c;

  if (c == '.') {
    while (isdigit(c = getch()))
      s[i++] = c;
  }

  s[i] = '\0';
  if (c != EOF && bufp < BUFSIZE)
    buf[bufp++] = c;
  else
    printf("Error");

  return NUMBER;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (c == EOF) {
    return;
  }
  if (bufp < BUFSIZE)
    buf[bufp++] = c;
  else
    printf("ungetch: too many characters\n");
}

void ungets(char s[]) {
  size_t len = strlen(s);
  while (len) {
    ungetch(s[--len]);
  }
}
