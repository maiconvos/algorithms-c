/*
  A contact list application
  Author: @maiconvos.
*/
#include <stdio.h>
#include <string.h>

// Flags to application options.
#define ADD 1
#define UPDATE 2
#define DELETE 3
#define LIST 4
#define SEARCH 5
#define EXIT 0

// Flags to search types
#define SEARCH_BY_AGE 1
#define SEARCH_BY_NAME 2

// Flags to boolean values
#define TRUE 1
#define FALSE 0

#define LIST_SIZE 100

// Struct to contact
typedef struct {
  char name[30];
  char lastname[30];
  int age;
  char email[50];
  int status; // Flag if a contatc is deleted.
} CONTACT;

// Print the main application menu.
void show_menu() {
  printf("\n======================================\n");
  printf("          GUEST APPLICATION           \n");
  printf("======================================\n");
  printf("1- Add contact       2- Update contact\n");
  printf("3- Delete contact    4- List contacts\n");
  printf("5- Search contact    0- Exit\n");
}

// Print the submenu existent for search option.
void show_search_options() {
  printf("\n------------------------------------\n");
  printf("           SEARCH OPTIONS             \n");
  printf("------------------------------------\n");
  printf("1- By age       2- By name     0- Back\n");
}

// Read and return the user choice.
int read_option() {
  int option;

  printf("\nEnter the option: ");
  scanf("%d", &option);

  return option;
}

// Add a contact to list.
void add_contact(CONTACT *c, int p) {
  if (p < LIST_SIZE) {
    printf("\nEnter the name: ");
    scanf("%s", c[p].name);

    printf("Enter the lastname: ");
    scanf(" %s", c[p].lastname);

    printf("Enter the age: ");
    scanf("%d", &c[p].age);

    printf("Enter the e-mail: ");
    scanf(" %s", c[p].email);

    c[p].status = TRUE;
    printf("Contact added.\n\n");
    fflush(stdin);
  } else {
    printf("The list is full\n");
  }
}

// Update the contact, finding by its id.
void update_contact(CONTACT *c, int total) {
  int id;

  printf("Enter the contact id: ");
  scanf("%d", &id);

  if (total == 0 ) {
    printf("There's no contacts on the list.");
  } else if (id > total) {
    printf("There's no contact with this id.");
  } else {
    id--; // to access the correct position on the array.

    printf("\nEnter the new name to %s: ", c[id].name);
    scanf("%s", c[id].name);

    printf("Enter the new lastname [current: %s]: ", c[id].lastname);
    scanf(" %s", c[id].lastname);

    printf("Enter the new age [current: %d]: ", c[id].age);
    scanf("%d", &c[id].age);

    printf("Enter the e-mail [current: %s]: ", c[id].email);
    scanf(" %s", c[id].email);

    printf("Contact %s was updated!\n\n", c[id].name);
  }
}

// Change the contact status to false.
void delete_contact(CONTACT *c, int total) {
  int id;

  printf("Enter the contact id: ");
  scanf("%d", &id);

  if (total == 0 ) {
    printf("There's no contacts on the list.");
  } else if (id > total) {
    printf("There's no contact with this id.");
  } else {
    id--; // to access the correct position on the array.
    int answer;

    printf("Are you sure you want to remove %s? (0- No   >=1 Yes)", c[id].name);
    scanf("%d", &answer);

    if (answer) c[id].status = FALSE;
    printf("The contact was removed\n");
  }
}

// Show all contacts.
void list_all(CONTACT c[], int total) {
  if (total == 0) {
    printf("\nYou don't have contacts on the list. Please add some.\n");
  } else {
    printf("\nListing all contacts...\n");
    printf("------------------------------------------------------------------------\n");

    for (int count = 0; count < total; count++)
      if (c[count].status)
        printf("%d\t%s\t%s\t%d\t%s\n", count + 1, c[count].name, c[count].lastname,
          c[count].age, c[count].email);

    printf("-------------------------------------------------------------------------\n\n");
  }
}

// Search all contacts by age.
void search_by_age(CONTACT c[], int total) {
  if (total == 0) {
    printf("You don't have contacts on the list.\n");
  } else {
    int age;

    printf("Enter the age: ");
    scanf("%d", &age);

    printf("\nListing contacts with the age %d...\n", age);
    printf("------------------------------------------------------------------------\n");
    for (int count = 0; count < total; count++) {
      if (c[count].status && c[count].age == age)
        printf("%d\t%s\t%s\t%d\t%s\n", count + 1, c[count].name, c[count].lastname,
          c[count].age, c[count].email);
    }
    printf("-------------------------------------------------------------------------\n\n");
  }
}

// Search all contacts by name.
void search_by_name(CONTACT c[], int total) {
  if (total == 0) {
    printf("You don't have contacts on the list.\n");
  } else {
    char name[30];

    printf("Enter the name: ");
    scanf("%s", name);

    printf("\nListing contacts with the name %s...\n", name);
    printf("------------------------------------------------------------------------\n");
    for (int count = 0; count < total; count++) {
      if (c[count].status && strcmp(c[count].name, name) == 0)
        printf("%d\t%s\t%s\t%d\t%s\n", count + 1, c[count].name, c[count].lastname,
          c[count].age, c[count].email);
    }
    printf("-------------------------------------------------------------------------\n\n");
  }
}

void main() {
  int run = TRUE;
  int option;

  CONTACT contacts[100]; // array of contacts.
  int total = 0;

  while (run) {
    show_menu();
    option = read_option();

    switch (option) {
      case EXIT:
        run = FALSE;
        break;
      case ADD:
        add_contact(contacts, total);
        total++;
        break;
      case UPDATE:
        update_contact(contacts, total);
        break;
      case DELETE:
        delete_contact(contacts, total);
        break;
      case LIST:
        list_all(contacts, total);
        break;
      case SEARCH:
        show_search_options();
        option = read_option();

        if (option == SEARCH_BY_AGE) search_by_age(contacts, total);
        if (option == SEARCH_BY_NAME) search_by_name(contacts, total);
        break;
      default:
        printf("\nThere's no option with this value. Please, choose another one on the menu.\n");
    }

  }// end while(run)

  printf("\nEND.\n");
}
