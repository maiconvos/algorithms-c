/*
  Program takes a number and returns its absolute value. Example: Enter -5 and returns 5.
  Author: @maiconvos
*/
#include <stdio.h>

int abs(int number){
  if (number >= 0 )
    return number;
  else
    return -1 * number;
}

void main() {
  int value = 0;
  int out = 0;

  while(!out) {
    printf("Enter a number (press CTRL + C to exit): ");
    scanf("%d", &value);
    printf("Absolute value is: %d\n", abs(value));
  }
}
