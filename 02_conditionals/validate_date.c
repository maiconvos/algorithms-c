/*
  Program takes a date and validates it.
  In C, all value equals to 0 (zero) is considered false. So any value diffent of zero is true.
  Author: @maiconvos
*/
#include <stdio.h>

void main() {
  int day = 0, month = 0, year = 0;
  int isValidDay = 0, isValidMonth = 0, isValidYear = 0;
  int isLeapYear = 0;

  printf("Enter the day:");
  scanf("%d", &day);

  printf("Enter the month:");
  scanf("%d", &month);

  printf("Enter the year:");
  scanf("%d", &year);

  if (year > 0) {
    isValidYear = 1; // true
  }

  if (year % 4 == 0 || (year % 100 == 0 && year % 400 == 0) ) {
    isLeapYear = 1; // true
  }

  if (month >= 1 && month <= 12) {
    isValidMonth = 1;
  }

  if (day >= 1 && day <= 31) {

    if ( (month == 1 || month == 3 || month == 5 || month == 7
       || month == 8 || month == 10 || month == 12) && day <= 31)
      isValidDay = 1;

    if ( (month == 4 || month == 6 || month == 9 || month == 11) && day <= 30)
      isValidDay = 1;

    if ( ( (month == 2 && isLeapYear) && day <= 29) || (month == 2 && day <= 28))
      isValidDay = 1;
  }

  if (isValidDay && isValidMonth && isValidYear) {
    printf("%d-%d-%d is a valid date.\n", year, month, day);
  } else {
    printf("%d-%d-%d is not a valid date.\n", year, month, day);
  }
}
