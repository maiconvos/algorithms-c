/*
  Program returns a liquid value based on calculation.
  Author: @maiconvos
*/
#include <stdio.h>

int pot(int base, int expo) {
  float res = 1.0;

  for (int i = 1; i <= expo; i++)
    res *= base;

  return res;
}

float val(float x, float t, int n) {
  float value = 0;

  for (int i = 1; i <= n; i++)
    value += x / ( pot( (1 + t ), i) ) ;

  return value;
}

void main() {
  float x, t;
  int n, out = 0;

  while(!out) {
    printf("Enter the value to x (Press Ctrl + C to exit): ");
    scanf("%f", &x);

    printf("Enter the value to t (Press Ctrl + C to exit): ");
    scanf("%f", &t);

    printf("Enter the value to n (Press Ctrl + C to exit): ");
    scanf("%d", &n);

    printf("The liquid value is: %.3f\n", val(x, t, n) );
  }
}
