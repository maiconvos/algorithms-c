/*
  Program receives a file and put its content on screen showing the number of each line.
  Author: @maiconvos.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGUMENT 2 // The number of arguments necessary to run the program.
#define MAX_STR 1000

#define ERR_ARGUMENT 10
#define ERR_FILE 11

void stop(int err) {
    switch (err) {
        case ERR_ARGUMENT:
            printf("It's necessary pass a file path to run the program. Try again passing a file path.\n");
            break;
        case ERR_FILE:
            printf("The file doesn't exist or you don't have permission to open it.\n");
            break;
    }

    exit(err);
}

void main(int argc, char *argv[]) {
    FILE *fin;
    int lines = 0;
    char s[500];

    if (argc != MAX_ARGUMENT) stop(ERR_ARGUMENT);

    if ( (fin = fopen(argv[1], "r") ) == NULL) stop(ERR_FILE);

    while( fgets(s, MAX_STR + 1, fin) != NULL) {
        fprintf(stdout, "%d: %s", ++lines, s);
    }

    fclose(fin);
}