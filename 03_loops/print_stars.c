/*
  Program takes a number and print such lines as stars than the taken number.
  Author: @maiconvos
*/
#include <stdio.h>

void main() {
  int number_of_stars = 0;

  printf("Enter a number:");
  scanf("%d", &number_of_stars);

  if (number_of_stars == 0) {
    printf("There's no stars to print.\n");
  } else {
    for (int x = 1; x <= number_of_stars; x++) {
      for (int y = 1; y <= x; y++)
        printf("*");

      putchar('\n'); //After print a line it puts a break.
    }
  }
}
