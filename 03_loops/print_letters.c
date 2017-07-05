/*
  Program takes a number and print the letters in order of the taken number.
  Author: @maiconvos
*/
#include <stdio.h>

void main() {
  int number_of_letters = 0;
  int letters_ascII = 97; // Represent the letters in asc II. Starting at the letter 'a'.

  printf("Enter a number:");
  scanf("%d", &number_of_letters);

  if (number_of_letters <= 0) {
    printf("There's no letters to print.\n");
  } else if (number_of_letters <= 26) {

    for (int row = 1; row <= number_of_letters; row++) {
      for (int column = 1; column <= row; column++)
        printf("%c", letters_ascII);

      letters_ascII++;
      putchar('\n'); //After print a line it puts a break.
    }
  } else {
    printf("The number is bigger than the whole alphabet\n");
  }

}
