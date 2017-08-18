/*
  Program that shows if a enter year is or not a leap year.
  Author: @maiconvos
*/
#include <stdio.h>

void main() {

  int year;

  printf("Enter with a year value: ");
  scanf("%d", &year);

  if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0)) {
    printf("The %d is (was) a leap year\n", year);
  } else {
    printf("The %d is not a leap year\n", year);
  }
}
