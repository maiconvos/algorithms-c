/*
  Program takes an array n x m and returns its transpost (m x n)
  Author: @maiconvos
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_LIMIT 250
#define MAX 4

// Initialize the array with random values.
void init_array(int v[MAX][MAX]) {
  long seed;
  time(&seed);

  srand( (unsigned) seed);

  for (int row = 0; row < MAX; row++) {
    for (int column = 0; column < MAX; column++)
      v[row][column] = rand() % RAND_LIMIT;
  }
}

// Show the array on the screen
void print_array(int v[MAX][MAX]) {
  for (int row = 0; row < MAX; row++) {
    for (int column = 0; column < MAX; column++) {
      printf("%3d ", v[row][column]);

      if ( (column + 1) % MAX == 0) putchar('\n');
    }
  }

  putchar('\n');
}

// Transpor an array m X m
void transpor(int v[MAX][MAX]) {
  int aux = 0;

  for (int row = 0; row < MAX; row++) {
    for (int column = row + 1; column < MAX; column++) {
        if (row != column) {
          aux = v[row][column];
          v[row][column] = v[column][row];
          v[column][row] = aux;
        }
    }
  }

  printf("The transposted array is:\n");
  print_array(v);
}

void main() {
  int array[MAX][MAX];

  init_array(array);
  printf("The array is:\n");
  print_array(array);

  transpor(array);
}
