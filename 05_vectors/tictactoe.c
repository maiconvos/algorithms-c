/*
  Tic tac toe game on shell mode.
  Author: @maiconvos
*/
#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define DIM 3
#define SPACE ' '

// Initialize the fields
void init(char s[][DIM]) {
  for (int row = 0; row < DIM; row++) {
    for (int column = 0; column < DIM; column++) {
      s[row][column] = SPACE;
    }
  }
}

// Print the fields on the screen.
void show(char s[DIM][DIM]) {
  for (int row = 0; row < DIM; row++) {
    for (int column = 0; column < DIM; column++)
      printf("%c %c", s[row][column], column == DIM - 1 ? ' ' : '|');

    if (row == DIM - 1) printf("\n-----------");
    putchar('\n');
  }
}

// Check the fields on a diagonal.
int check_dig(char s[][DIM]) {
  if (s[0][0] != SPACE) {
    if ( (s[0][0] == s[1][1]) && (s[1][1] == s[2][2]) ) return TRUE;
  }

  if (s[0][2] != SPACE) {
    if ( (s[0][2] == s[1][1]) && (s[1][1] == s[2][0]) ) return TRUE;
  }

  return FALSE;
}

// Check the fields on a row.
int check_row(char s[][DIM]) {

  for (int row = 0; row < DIM; row++) {
    if (s[row][0] != SPACE) {
      if ( (s[row][0] == s[row][1]) && (s[row][1] == s[row][2]) ) return TRUE;
    }
  }

  return FALSE;
}

// Check the fields on a column.
int check_col(char s[][DIM]) {

  for (int column = 0; column < DIM; column++) {
    if (s[0][column] != SPACE) {
      if ( (s[0][column] == s[1][column]) && (s[1][column] == s[2][column]) ) return TRUE;
    }
  }

  return FALSE;
}

// Check if there is a winner
int check_winner(char s[][DIM]) {
  int is_winner = FALSE;

  if ( check_dig(s) || check_row(s) || check_col(s) )
    is_winner = TRUE;

  return is_winner;
}

void main() {
  char tictac[DIM][DIM];
  int posX, posY;
  char ch = 'O';
  int play = TRUE;
  int number_of_plays = 0;
  int is_winner = FALSE;

  printf("\t WELCOME TO TIC-TAC-TOE GAME\n");
  printf("================================================\n");
  printf("Press Ctrl + C to exit game.\n");

  init(tictac);

  while (play) {
      show(tictac);

      printf("\nEnter the number of row and column to insert your play: ");
      scanf("%d %d", &posX, &posY);

      posX--;
      posY--;

      if (tictac[posX][posY] == SPACE) {
        tictac[posX][posY] = ch = (ch == 'O') ? 'X' : 'O';
        number_of_plays++;
        is_winner = check_winner(tictac);
      } else {
        printf("Position is not empty! Try another one.\n");
      }

      if (number_of_plays == DIM * DIM) break;
      if (is_winner) break;
  }

  show(tictac);

  if (is_winner)
    printf("\nThe winner was who played with %c\n", ch);
  else
    printf("Game over! No one won!\n");
}
