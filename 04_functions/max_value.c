/*
  Program takes three values and returns the maximum.
  Author: @maiconvos
*/
#include <stdio.h>

int max(int x, int y, int z) {
  if (x > y && x > z)
    return x;

  if (y > x && y > z)
    return y;

  if (z > x && z > y)
    return z;
}

void main() {
  int x, y, z;
  int out = 0;

  while (!out) {
    printf("Enter the first value (Press Ctrl + C to exit):");
    scanf("%d", &x);

    printf("Enter the second value (Press Ctrl + C to exit):");
    scanf("%d", &y);

    printf("Enter the third value (Press Ctrl + C to exit):");
    scanf("%d", &z);

    printf("The max value between %d, %d and %d is: %d.\n", x, y, z, max(x, y, z) );
  }
}
