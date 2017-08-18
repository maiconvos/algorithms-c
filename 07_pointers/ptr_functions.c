/*
  Implementation of functions to work with pointers.
  Author: @maiconvos
*/
#define FALSE 0
#define TRUE 1

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Returns the position in memory of the first ocurrence from ch. Returns NULL case ch is not on the string.
char *stringchar(char *s, char ch) {
  for (int count = 0; s[count] != '\0'; count++) {
    if (s[count] == ch) return &s[count];
  }

  return NULL;
}

// Returns the position in memory of the last ocurrence from ch. Returns NULL case ch is not on the string
char *stringrchr(char *s, char ch) {
  for (int count = strlen(s) - 1; count >= 0; count--) {
    if (s[count] == ch) return &s[count];
  }

  return NULL;
}

// Returns the position in memory of the first ocurrence from substring s2
// on s1. Returns NULL case ch is not on the string.
char *stringsub(char *s1, char *s2) {
  int issub = FALSE;

  for (int count = 0; s1[count] != '\0'; s1++) {
    if (s1[count] == s2[0]) {

      for (int sub = 1; s2[sub] != '\0'; sub++) {
        if (s1[count + sub] == s2[sub]) issub = TRUE;
        else issub = FALSE;
      }

      if (issub) return &s1[count];
    }
  }

  return NULL;
}

// Returns the position in memory of the first vowal on string s. Returns NULL case not.
char *firstvowal(char *s) {
  for (int count = 0; s[count] != '\0'; count++) {
    if (tolower(s[count]) == 'a' || tolower(s[count]) == 'e' || tolower(s[count]) == 'i'
      || tolower(s[count]) == 'o' || tolower(s[count]) == 'u')
        return &s[count];
  }

  return NULL;
}

// Puts the string orig at the beginning of dest and returns dest.
char *strings(char *dest, char *orig) {
  strcpy(dest + strlen(orig), dest);
  memcpy(dest, orig, strlen(orig) );
  return dest;
}

// Removes all upper characters from a string.
char *str_del_upper(char *s) {
  int new = 0;

  for (int count = 0; s[count] != '\0'; count++) {
    if ( islower(s[count]) )
      s[new++] = s[count];
  }

  s[new] = '\0';
  return s;
}

// Removes a substring s2 from string s1.
char *str_del_str(char *s1, char *s2) {
  char *location = stringsub(s1, s2);

  while (location != NULL) {
    strcpy(location, location + strlen(s2) );
    location = stringsub(s1, s2);
  }

  return s1;
}

void main() {
  char s[100] = "My name is isis";
  str_del_str(s, "is");
  printf("%s\n", s);
}
