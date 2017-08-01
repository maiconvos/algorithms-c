/*
  Program takes a number of hours and shows the number of seconds.
  Author: @maiconvos.
*/
#include <stdio.h>

long int hours_to_sec(long int hours) {
  return hours * 3600;
}

void main() {
  int hours = 0;
  int out = 0;

  while(!out) {
    printf("Enter the number of hours (Press Ctrl + C to exit):");
    scanf("%d", &hours);

    printf("%d hour(s) has (have) %ld second(s).\n", hours, hours_to_sec(hours));
  }
}
