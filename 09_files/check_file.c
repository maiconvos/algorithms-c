/*
  Program checks if it is possible to open the specified file.
  Author: @maiconvos
*/
#include <stdio.h>

void main() {
  FILE *fp;
  char s[100];

  puts("Enter the file name to open:");
  gets(s);

  fp = fopen(s, "r");

  if (fp = NULL)
    printf("It's impossible to open the file\n");
  else
    printf("The %s file was open\n", s);

  fclose(fp);
}
