#include <stdio.h>

void main() {
  int year, month, day;

  printf("Enter with a year:");
  scanf("%d", &year);

  printf("Enter with a month number:");
  scanf("%d", &month);

  printf("Enter with a day number:");
  scanf("%d", &day);

  printf("You enter the date %d-%2d-%2d\n", year, month, day);
  printf("The date in brazilian format %2d/%2d/%d\n", day, month, year);
}
