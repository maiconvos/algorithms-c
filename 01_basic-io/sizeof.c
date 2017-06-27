/*
  A simple example how to use the sizeof operator to know the size in bytes a type.
  Author: @maiconvos
*/
#include <stdio.h>

void main() {
  printf("The size in bytes of int type is: %ld\n", sizeof(int));
  printf("The size in bytes of float type is: %ld\n", sizeof(float));
  printf("The size in bytes of double type is: %ld\n", sizeof(double));
  printf("The size in bytes of char type is: %ld\n", sizeof(char));
}
