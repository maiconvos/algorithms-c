/*
  Program calculates the factorial of n  (n!) on a recursive way.
  Author: @maiconvos.
*/
#include <stdio.h>

unsigned long fact(int n) {
  if (n == 0)
    return 1;
  else
    return n * fact(n-1);
}

void main() {
  int number;

  puts("Enter a number (enter any letter to exit): ");
  while (scanf("%d", &number) ) {
    printf("The %d! = %ld\n", number, fact(number));
    puts("Enter a number (enter any letter to exit):");
  }
}
