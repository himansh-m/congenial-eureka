#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int v[100], x, n;

  printf("There is an array of values from 1 to 100.\n");

  for (int i = 0; i < 100; i++) {
    v[i] = i + 1;
  }

  n = 100; // FIXED

  printf("Now enter the value whose index you wish to find: ");
  scanf("%d", &x);

  printf("Index: %d\n", binsearch(x, v, n));
}

int binsearch(int x, int v[], int n) {

  int low = 0, high = n - 1, mid;

  while (low <= high) {
    mid = (low + high) / 2;

    if (x < v[mid])
      high = mid - 1;
    else if (x > v[mid])
      low = mid + 1;
    else
      return mid; // found
  }

  return -1; // not found
}
