/*
  Some coding problems with strings on C.
  Author: @maiconvos.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Remove the unique characters on string. Only keeping those repetead.
char *rmv_uniquec(char *s) {
  int position = 0;

  for (int count = 0; s[count] != '\0'; count++) {
    int times = 0;

    for (int next = 0; s[next] != '\0'; next++)
        if (s[count] == s[next] && s[count] != ' ')   times++;

    if (times > 1)  s[position++] = s[count];
  }

  s[position] = '\0';
  return s;
}

// Returns the nth character on array.
char nth_char(char *s, int n) {
  if (--n < strlen(s) ) return s[n];

  return '\0';
}

// Compacts all the repetead characters in only character on string.
char *strpack(char *s) {
  int current, next;
  for (next = current = 0; s[next] != '\0'; next++) {
    if (s[next] != s[current])
      s[++current] = s[next];
  }

  s[++current] = '\0';
  return s;
}

// Changes the sring s, only remaining the characters each n positions.
char *interweave(char *s, int n) {
  int position = 0;
  long len = strlen(s) - 1;

  for (int count = 0; count <= len; count = ++count + n)
      s[position++] = s[count];

  s[position] = '\0';
  return s;
}

// Puts one space after each character there is not a space.
char *xspace(char *s) {
  for (int count = 0; s[count] != '\0'; count++) {
    if (s[count] != ' ') {
      for (int size = strlen(s) - 1; size > count; size--) {
        s[size + 1] = s[size];
      }

      s[count + 1] = ' ';
    }
  }

  return s;
}

// Returns the character with the max asc II value.
char max_ascii(char *s) {
  char max = s[0];

  for (int count = 1; s[count] != '\0'; count++)
    if ( (int) s[count] > (int) max)
      max = s[count];

  return max;
}

// Changes the string replacing each character for the next on asc ii table.
char *next_char(char *s) {
  for (int count = 0; s[count] != '\0'; count++)
    s[count] = (char) s[count] + 1;

  return s;
}

// Changes the string putting letters in upper and others and down.
char *updown(char *s) {
  for (int count = 0; s[count] != '\0'; count++) {
    if (count % 2 == 0)
      s[count] = toupper(s[count]);
    else
      s[count] = tolower(s[count]);
  }

  return s;
}

// Receives an array and returns an integer according its value.
int atoi(char *s) {
  int value = 0;
  int reference_digit = 1; // Represents units, dozens, hundreds and so on.
  int count = strlen(s) - 1;

  while( isdigit(s[count]) ) {
    value += ( (int) s[count] - '0') * reference_digit;
    reference_digit *= 10;

    if (s[--count] == '-')  value *= -1; //Check minus and turns number in negative.
  }

  return value;
}

void main() {
  char p[] = "abc-1dd+-7234";
  printf("The string %s has %d as number in it\n", p, atoi(p));
}
