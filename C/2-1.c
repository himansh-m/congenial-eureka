#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

int main() {
  printf("From Header: \n");
  printf("signed char: (%d)-(%d)\n", SCHAR_MIN, SCHAR_MAX);
  printf("unsigned char: (%i)-(%i)\n", 0, UCHAR_MAX);
  printf("signed int: (%d)-(%d)\n", INT_MIN, INT_MAX);
  printf("unsigned int: (%i)-(%i)\n", 0, UINT_MAX);
  printf("signed long: (%ld)-(%ld)\n", LONG_MIN, LONG_MAX);
  printf("unsigned long: (%d)-(%lu)\n", 0, ULONG_MAX);
  printf("signed short: (%d)-(%d)\n", SHRT_MIN, SHRT_MAX);
  printf("unsigned short: (%i)-(%i)\n", 0, USHRT_MAX);
  printf("float: (%e)-(%e)\n", -FLT_MAX, FLT_MAX);
  printf("double: (%e)-(%e)\n\n", -DBL_MAX, DBL_MAX);

  printf("Direct Computation:\n");

  int scmin, scmax;
  scmin = -pow(2, (sizeof(char) * 8) - 1);
  scmax = pow(2, (sizeof(char) * 8) - 1) - 1;
  printf("signed char: (%d)-(%d)\n", scmin, scmax);

  unsigned ucmax;
  ucmax = pow(2, (sizeof(char) * 8)) - 1;
  printf("unsigned char: (%i)-(%u)\n", 0, ucmax);

  int simin, simax;
  simin = -pow(2, (sizeof(int) * 8) - 1);
  simax = pow(2, (sizeof(int) * 8) - 1) - 1;
  printf("signed int: (%d)-(%d)\n", simin, simax);

  unsigned int uimax;
  uimax = pow(2, (sizeof(int) * 8)) - 1;
  printf("unsigned int: (%i)-(%u)\n", 0, uimax);

  long slmin, slmax;
  slmin = -pow(2, (sizeof(long) * 8) - 1);
  slmax = pow(2, (sizeof(long) * 8) - 1) - 1;
  printf("signed long: (%ld)-(%ld)\n", slmin, slmax);

  unsigned long ulmax;
  ulmax = pow(2, (sizeof(long) * 8)) - 1;
  printf("unsigned long: (%d)-(%lu)\n", 0, ulmax);

  int ssmin, ssmax;
  ssmin = -pow(2, (sizeof(short) * 8) - 1);
  ssmax = pow(2, (sizeof(short) * 8) - 1) - 1;
  printf("signed short: (%d)-(%d)\n", ssmin, ssmax);

  int usmax;
  usmax = pow(2, (sizeof(short) * 8)) - 1;
  printf("unsigned short: (%i)-(%i)\n", 0, usmax);

  return 0;
}
