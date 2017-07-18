/*
  Implementation of functions of the mem.h library.
  Author: @maiconvos
*/
#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

// Copy n characters from orig array to dest array.
char * memcpy(char *dest, char *orig, int n) {
  for (int count  = 0; count <= n; count++)
    dest[count] = orig[count];
}

// Compare if the n positions between the arrays s1 and s2 are equals.
int memcmp(char *s1, char *s2, int n) {
  for (int count = 0; count < n; count++) {
    if (s1[count] != s2[count])
      return FALSE;
  }

  return TRUE;
}

// Compare if the n positions between the arrays s1 and s2 are equals, ignoring case sensitive.
int memicmp(char *s1, char *s2, int n) {
  for (int count = 0; count < n; count++) {
    if (toupper(s1[count]) != toupper(s2[count]) )
      return FALSE;
  }

  return TRUE;
}


void main() {
  char first[] = {'m','y',' ','n','a','m','e',' ','i','s',' ','C'};
  char second[10];
  int is_equal = 0;

  memcpy(second, first, 6);

  for (int n = 0; n <= 6; n++)
    printf("%c", second[n]);

  is_equal = memcmp(first, second, 6);

  if (is_equal)
    printf("\nThe positions compared between array first and second are equals.\n");
  else
    printf("\nThe positions compared between arrays aren't equals.\n");

  is_equal = memicmp(first, second, 6);

  if (is_equal)
    printf("\nThe positions compared between array first and second are equals. Ignoring case letters\n");
  else
    printf("\nThe positions compared between arrays aren't equals.\n");
}
