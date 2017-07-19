/*
  Implementation of functions to work with strings.
  Author: @maiconvos
*/
#include <stdio.h>
#include <ctype.h>

// Receives an string and returns its length.
int strlen(char *s) {
  int len = 0;

  while (s[len] != '\0')
    len++;

  return len;
}

// Checks if an string is null.
int isnull(char *s) {
  return (s[0] == '\0');
}

// Copies an string orig to string dest.
char *strcpy(char *orig, char *dest) {
  int count;

  for (count = 0; count != '\0'; count++)
    dest[count] = orig[count];

  dest[count] = '\0';
  return dest;
}

// Concats the string orig with the dest.
char *strcat(char *orig, char *dest) {
  int len = 0;

  for (int count = 0, len = strlen(dest); orig[count] != '\0'; count++, len++)
    dest[len] = orig[count];

  dest[len] = '\0';
  return dest;
}

// Counts how many times the character ch appears on string s.
int strcountc(char *s, char ch) {
  int times = 0;

  for (int count = 0; count != '\0'; count++) {
    if (s[count] == ch)
      times++;
  }

  return times;
}

// Counts the number of digits on given string.
int strcountd(char *s) {
  int times = 0;

  for (int count = 0; count != '\0'; count++) {
    if (isdigit(s[count]))
      times++;
  }

  return times;
}

// Returns the first position on array where the character is found. -1 when is not found.
int indchar(char *s, char ch) {
  for (int count = 0; s != '\0'; count++) {
    if (s[count] == ch)
      return count;
  }

  return -1;
}

// Checks if the string is a palidromn.
int strpal(char *s) {
  int begin, end;

  for (begin = 0, end = strlen(s) - 1; begin < end; begin++, end--) {
    if (s[begin] != s[end])
      return 0; // False
  }

  return 1;
}

// Reverts the string and returns it reverted.
char *strrev(char *s) {
  int len = strlen(s) - 1;
  char aux;

  for (int count = 0; count < len; count++, len--) {
    aux = s[count];
    s[count] = s[len];
    s[len] = aux;
  }

  return s;
}

// Compares two strings. Returns zero if both are equals.
int strcmp(char *s1, char *s2) {
  int count = 0;

  while (s1[count] == s2[count] && s1[count] != '\0')
    count++;

  return ( (unsigned char) s1[count] - (unsigned char) s2[count] );
}

// Compares two strings. Returns zero if both are equals, ignoring case letters.
int stricmp(char *s1, char *s2) {
  int count = 0;

  while (tolower(s1[count]) == tolower(s2[count]) && s1[count] != '\0')
    count++;

  return ( (unsigned char) s1[count] - (unsigned char) s2[count] );
}

// Puts a padding after each letter on the string.
char *strpad(char *s) {
  int len = strlen(s);
  s[2 * len] = s[len];

  for (len--; len >= 0; len--) {
    s[2 * len] = s[len];
    s[2 * len + 1] = ' ';
  }

  return s;
}

// Deletes all ocurrences of an char on string.
char *strdelc(char *s, char ch) {
  int new = 0;

  for (int len = 0; s[len] != '\0'; len++) {
    if (s[len] != ch)
      s[new++] = s[len];
  }

  s[new] = '\0';
  return s;
}

// Sets the char ch for all positions on array.
char *strset(char *s, char ch) {
  for (int count = 0; s[count] != '\0'; count++)
    s[count] = ch;

  return s;
}

// Sets the first n positions of array with letter ch
char *strnset(char *s, char ch, int n) {
  if (n > strlen(s) - 1) {
    n = strlen(s) - 1;
  }

  for(int count = 0; count <= n; count++)
    s[count] = ch;

  return s;
}

// Turns caps letter all letters on array.
char *strupr(char *s) {
  for (int count = 0; s[count] != '\0'; count++)
    s[count] = toupper(s[count]);

  return s;
}

// Turns all letter in low letter on array.
char *strlwr(char *s) {
  for (int count = 0; s[count] != '\0'; count++)
    s[count] = tolower(s[count]);

  return s;
}

// Counts the number of alphabetic characters on array.
int strcounta(char *s) {
  int quant = 0;

  for (int count = 0; s[count] != '\0'; count++) {
    if (isalpha(s[count]) )
      quant++;
  }

  return quant;
}

// Turns the string s empty.
char *init_str(char *s) {
  s[0] = '\0';
  return s;
}

// Searchs for char ch on array and returns the last position where ch was found.
int ult_ind_char(char *s, char ch) {
  int position;

  for (int len = strlen(s) - 1; len >= 0; len--) {
    if (s[len] == ch) {
      position = len;
      return position;
    }
  }

  return -1;
}

void main() {
  char p[] = "MAicon D";
  char p2[] = "MAicon";

  printf("String natural: %s\n", p);
  printf("String after first set: %s\n", strnset(p, 'a', 5));
  printf("String after first set: %s\n", strnset(p, 'x', 32));
}
