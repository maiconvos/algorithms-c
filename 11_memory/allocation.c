/*
  Functions that use memory allocation.
  Author: @maiconvos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a new string containing the string repeated n times.
char * repeat(char *string, int times) {
  char * repeated;
  repeated = (char *) malloc( (strlen(string) * times) + times);

  for (int count = 1; count <= times; count++) {
    strcat(repeated, string);

    if (count != times) strcat(repeated, " ");
  }

  return repeated;
}

// Create a string containing string's half.
char * cut_in_half(char * string) {
  char * new;
  int half = strlen(string) / 2;
  new = (char *) malloc(half);

  for (int count = 0; count <= half; count++) new[count] = string[count];

  return new;
}

// Create a string dynamically containing the reverse string
char * reverse(char * string) {
  char * new;
  int size = strlen(string) - 1;
  new = (char *) malloc(size + 1);

  for (int count = 0; count <= size; count++)
    new[count] = string[size - count];

  new[size + 1] = '\0';
  return new;
}

void main() {
  char name[] = "Work hard", *ptr;

  ptr = repeat(name, 3);
  printf("%s\n", ptr);

  ptr = cut_in_half(name);
  printf("%s\n", ptr);

  ptr = reverse(name);
  printf("%s\n", ptr);
}
