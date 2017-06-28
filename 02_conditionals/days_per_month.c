/*
  Program takes a month number and shows the number of days in that month.
  Author: @maiconvos
*/
#define JANUARY  1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#include <stdio.h>

void main() {

  int month, number_of_days = 0, leap_feb = 0;

  printf("Enter with the month number:");
  scanf("%d", &month);

  switch (month) {
    case JANUARY:
    case MARCH:
    case MAY:
    case JULY:
    case AUGUST:
    case OCTOBER:
    case DECEMBER:
      number_of_days = 31;
      break;
    case APRIL:
    case JUNE:
    case SEPTEMBER:
    case NOVEMBER:
      number_of_days = 30;
      break;
    case FEBRUARY:
      number_of_days = 28;
      leap_feb = 29;
      break;
    default:
      number_of_days = 0;
  }

  if (number_of_days) {
    printf("The month %d has %d days.\n", month, number_of_days);

    if (leap_feb) {
      printf("And %d days when is a leap year.\n", leap_feb);
    }
  } else {
    printf("You don't entered a valid month number.\n");
  }
}
