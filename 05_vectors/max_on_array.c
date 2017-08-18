/*
  Program receives an array with n elements and returns the maximum value found on it.
  Author: @maiconvos
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_LIMIT 250 //The max number wich can be generated.

// Initialize the array with random numbers.
void init_rand_array(int *numbers, int length) {
  long seed;

  time(&seed);
  srand( (unsigned) seed);

  for (int count = 0; count < length; count++) {
    numbers[count] = rand() % RAND_LIMIT;
  }
}

// Show the whole array with its elements.
void print_array(int numbers[], int length) {

  for (int count = 0; count < length; count++) {
    printf("%3d ", numbers[count]);

    if ( (count + 1) % 5 == 0) putchar('\n');
  }

  putchar('\n');
}

int find_max(int array[], int length) {

  int max = 0;

  for (int count = 0; count < length; count++) {
    if (max < array[count])
      max = array[count];
  }

  return max;
}

void main() {
  int size = 0;
  int max_value = 0;

  printf("Enter the array size: ");
  scanf("%d", &size);

  int array[size];

  init_rand_array(array, size);
  max_value = find_max(array, size);

  print_array(array, size);
  printf("The max value on the array above is: %d\n", max_value);
}
