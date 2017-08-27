/*
  A simple struct list that can be saved to or loaded from a file.
  Author: @maiconvos
*/
#include <stdio.h>
#include <string.h>

#define MAX 10 // the list limit

// Program options
#define ADD 1
#define SAVE 2
#define LOAD 3
#define SHOW 4

// Boolean values
#define TRUE 1
#define FALSE 0

typedef struct {
  int number;
  char name[40];
} LIST;

// Print the application menu.
void show_menu() {
  printf("\n***********************************\n");
  printf("1- Add element     2- Save to file\n");
  printf("3- Load from file  4- Show on screen\n");
  printf("************************************\n");
}

// Read and return the user choice.
int read_option() {
  int option;

  printf("\nEnter the option (CTRL + c to quit): ");
  scanf("%d", &option);

  return option;
}

// Initialize the list.
void init(LIST l[]) {
  for (int count = 0; count < MAX; count++) {
    l[count].number = 0;
    strcpy(l[count].name, "\0");
  }
}

// Add an element to list and return the position where it was added.
int add(LIST l[], int position) {
  if (position < MAX) {
    int number;
    char name[40];

    printf("Enter the number: ");
    scanf("%d", &l[position].number);

    printf("Enter the name: ");
    scanf(" %s", l[position].name);

    fflush(stdin);

    return position + 1;
  }

  printf("The list is full\n");
  return -1;
}

// Save the list into a file.
int save(LIST l[], int elements) {
  char file_name[] = "bckup";
  FILE *file;
  int total_saved = 0;

  if ( (file = fopen(file_name, "wb") ) == NULL) {
    printf("The file can't be opened.\n");
    return -1;
  }

  for (int count = 0; count < elements; count++)
    if ( fwrite(&l[count], sizeof(LIST), 1, file) ) total_saved++;

  fclose(file);
  return total_saved;
}

// Load the list from a file.
int load(LIST l[], int elements) {
  char file_name[] = "bckup";
  FILE *file;
  int loaded = 0;
  LIST new;

  if ( (file = fopen(file_name, "rb") ) == NULL) {
    printf("The file can't be opened.\n");
    return -1;
  }

  while ( fread(&new, sizeof(new), 1, file) )
    l[loaded++] = new;

  fclose(file);
  return loaded;
}

// Show all elements from l on the screen.
void show(LIST l[]) {
  printf("\nShowing the list...\n");
  printf("NUMBER\t\t NAME\n");

  for (int count = 0; count < MAX; count++)
    printf("%6d\t\t %s\n", l[count].number, l[count].name);
}

void main() {
  LIST list[MAX];
  int position = 0, elements, option;
  int run = TRUE;

  init(list);

  while (run) {
    show_menu();
    option = read_option();

    switch (option) {
      case ADD:
        position = add(list, position);
        printf("Element added %d position.\n", position);
        break;
      case SAVE:
        elements = save(list, position);
        printf("%d elements have been saved.\n", elements);
        break;
      case LOAD:
        elements = load(list, position);
        printf("%d elements have been loaded.\n", elements);
        break;
      case SHOW:
        show(list);
        break;
      default:
        printf("Wrong option! Choose one on the menu\n");
    }
  }
}
