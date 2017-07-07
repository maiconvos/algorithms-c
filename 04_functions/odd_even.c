/*
  Program takes a number and show if it is odd or even.
  Author: @maiconvos
*/
#include <stdio.h>

void parity(int number) {
  if (number % 2 == 0) {
    printf("It is even.\n");
  } else {
    printf("It is odd.\n");
  }
}

void main() {
  int number;
  int out = 0;

  while(!out) {
    printf("Enter a number (Press Ctrl + C to exit):");
    scanf("%d", &number);
    parity(number);
  }
}
