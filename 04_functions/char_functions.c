/*
  This file contains a lot of functions to work with type char.
  Author: @maiconvos.
*/
#include <stdio.h>

/* Function verifies if the character is digit or not */
int is_digit(char c) {
  if (c >= '0' && c <= '9')
    return c;

  return 0;
}

/* Function verifies if the character is part of alphabet or not */
int is_alpha(char c) {
  if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') )
    return c;

  return 0;
}

/* Function verifies if the character is part of alphabet or a digit. */
int is_alnum(char c) {
  if ( (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
    return c;

  return 0;
}

/* Function verifies if the character is lower. */
int is_lower(char c) {
  if (c >= 'a' && c <= 'z')
    return c;

  return 0;
}

/* Function verifies if the character is upper. */
int is_upper(char c) {
  if (c >= 'A' && c <= 'Z')
    return c;

  return 0;
}

/* Function verifies if the character is a blank space. */
int is_space(char c) {
  if (c == ' ')
    return c;

  return 0;
}

/* *Function returns the upper character. */
char to_upper(char c) {
  if (c >= 'a' && c <= 'z')
    return c + 'A' - 'a';
  else
    return c;
}

/* *Function returns the lower character. */
char to_lower(char c) {
  if (c >= 'A' && c <= 'Z')
    return c + 'a' - 'A';
  else
    return c;
}

void show_result(int result) {
  if (result) {
    printf("True.\n\n");
  } else {
    printf("False.\n\n");
  }
}

void main() {
  char c;
  int out = 0, option, result = 0;

  while (!out) {
    printf("*************************************\n");
    printf("\t WORKING WITH CHAR TYPE\n");
    printf("*************************************\n\n");

    printf("1- Check digit \t 2- Check alpha\n");
    printf("3- Check alnum \t 4- Check lower\n");
    printf("5- Check upper \t 6- Check space\n");
    printf("7- Convert lower 8- Convert upper\n");
    printf("Press Ctrl + C to exit.\n");

    printf("Choose an option: ");
    scanf("%d", &option);

    printf("Enter with one and only character: ");
    scanf(" %c", &c);

    switch (option) {
      case 1:
        result = is_digit(c);
        show_result(result);
        break;
      case 2:
        result = is_alpha(c);
        show_result(result);
        break;
      case 3:
        result = is_alnum(c);
        show_result(result);
        break;
      case 4:
        result = is_lower(c);
        show_result(result);
        break;
      case 5:
        result = is_upper(c);
        show_result(result);
        break;
      case 6:
        result = is_space(c);
        show_result(result);
        break;
      case 7:
        printf("To lower: %c\n", to_lower(c));
        break;
      case 8:
        printf("To upper: %c\n", to_upper(c));
        break;
      default:
        printf("Invalid operation. Choose another one on menu.\n\n");
    }
  }
}
