#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* FILE : LibraryCatalog.c
* PROJECT : SENG1050 - A01_Singly_Linked_List_Implementation
* PROGRAMMER : Eric Moutoux, Nick Porter, Hunter Wakely, ...
* FIRST VERSION : 2025-01-28
* DESCRIPTION :
* The functions in this file are used to …
*/


typedef struct Book
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next; //(pointer to the next book in the list)
}Book;

//prototypes/operation functions
void searchBooks(Book* head, const char* title);
void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
void viewBooks(Book* head);
void updateBook(Book* head, int id);
void deleteBook(Book** head, int id);
void freeList(Book** head);


//prototypes/input/output functions
int getUserNumber();
int getUserBookId();
int getUserBookPublicationYear();
int isUniqueID(Book* head, int id);
void displayMenu();
void getbookTitleOrAuthor(char titleAuthor[], int titleAuthorSize, char authorOrTitle[]);

typedef enum {
	AddABook = 1,
	ViewAllBooks,
	UpdateABook,
	DeleteABook,
	SearchForABook,
	ExitProgram,
};

int main(void)
{
	//head and list start point creation 
	Book* head = NULL;

	//chars and strings
	char bookTitleUI[] = "title";
	char bookAuthorUI[] = "author";

	//string holders
	char bookTitle[50] = "";
	char bookAuthor[50] = "";
	char bookSearchTitle[50] = "";

	//integer creation
	int userPickedId = 0;
	int yesNoChecker = 0;
	int bookTitleSize = sizeof(bookTitle);
	int bookAuthorSize = sizeof(bookAuthor);

	//booleans 
	bool runTimer = true;

	while (runTimer)
	{
		//displays user input and allows for navigation
		displayMenu();
		int userInput = getUserNumber();
		switch (userInput)
		{
		case AddABook:
			printf("To add a book you must have a Id, title, Author, and publication year.\n");
			printf("Do you have this data \n 1. Yes \n 2. No\n");
			yesNoChecker = getUserNumber();
			if (yesNoChecker == 1)
			{
				//id checker and user validation
				int bookId = getUserBookId();
				int idChecker = isUniqueID(head, bookId);
				if (idChecker == 0)
				{
					printf("Id is not unique, returning to main menu");
					break;
				}

				getbookTitleOrAuthor(bookTitle, bookTitleSize, bookTitleUI);
				getbookTitleOrAuthor(bookAuthor, bookAuthorSize, bookAuthorUI);
				int bookPublicationYear = getUserBookPublicationYear();

				//calls the addbook function.
				addBook(&head, bookId, bookTitle, bookAuthor, bookPublicationYear);
				printf("Book successfully added.");

			}
			//validation checker
			else if (yesNoChecker == 2)
			{
				printf("lack of effective data returning to main menu");
			}
			else
			{
				printf("Invalid input returning to menu.");
			}
			break;
		case ViewAllBooks:
			viewBooks(head);
			break;
		case UpdateABook:
			printf("Please insert book id number : ");
			userPickedId = getUserNumber();
			if (userPickedId < 0)
			{
				printf("invalid id number returning to main menu");
			}
			else
			{
				deleteBook(&head, userPickedId);
			}
			break;
		case DeleteABook:
			printf("Please insert book id number : ");
			userPickedId = getUserNumber();
			if (userPickedId < 0)
			{
				printf("invalid id number returning to main menu");
			}
			else
			{
				deleteBook(&head, userPickedId);
			}
			break;
		case SearchForABook:
			getbookTitleOrAuthor(bookTitle, bookTitleSize, bookTitleUI);
			searchBooks(head, bookTitle);
			break;
		case ExitProgram:
			printf("Exiting Program");
			userInput = false;
			break;
		default:
			printf("Invalid input, please select 1-6");
			break;
		}
	}
	freeList(&head);
	return 0;
}

//
// FUNCTION : displayMenu
// DESCRIPTION :
// holds the menu that the user will interact with
// PARAMETERS :
// takes no parameters 
// RETURNS :
// has no return parameters
void displayMenu()
{
	printf("Book Library\n");
	printf("1. Add a book to list.\n");
	printf("2. View all currently added books.\n");
	printf("3. Update a already added book.\n");
	printf("4. Delete a existing book.\n");
	printf("5. Search for a book in the list.\n");
	printf("6. Exit the program\n");
	return;
}

//
// FUNCTION : addBook
// DESCRIPTION :
// adds a new book to the end of the list 
// PARAMETERS :
// Book** head : Pointer to a pointer to the head of the list
// int id: the book ID
// const char* title : pointer to the title of the book
// const char* author : pointer to the author of the book
// int publication_year : the publication year of the book
// RETURNS :
// Has no return parameters
void addBook(Book** head, int id, const char* title, const char* author, int publication_year)
{
	char buffer[50];
	//Memory Allocation for newBook
	Book* newBook = (Book*)malloc(sizeof(Book));
	//Error message displayed if memory allocation failed
	if (newBook == NULL)
	{
		printf("Memory Allocation Failed.\n");
		return;
	}
	//Prompt to get all the book details
	printf("Enter the book details: \n");
	//Book ID
	printf("Enter Book ID:");
	//scanf("%d", &id);
	//Remove newline character
	getchar();
	//Check if the ID given by user is already taken
	if (isUniqueID(*head, id) == NULL)
	{
		printf("Error: Duplicate ID entered! Book not added.\n");
		free(newBook);
		return;
	}

	//If the list is empty, new book becomes the head
	if (*head == NULL)
	{
		*head = newBook;
	}
	else
	{
		//Iterate through list to find the end of the list and add newBook
		Book* current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newBook;
	}
	printf("Book added successfully!\n");
}

//
// FUNCTION : viewBooks
// DESCRIPTION :
// Checks if the book ID is used
// PARAMETERS :
// Book* head: Pointer to head element of the linked list
// int id : the ID of the book
// RETURNS :
// int : Returns a 1 if no duplicate ID, 0 if duplicate ID
int isUniqueID(Book* head, int id)
{
	Book* current = head;
	//Check through the list to see if there is a repeat ID
	while (current != NULL)
	{
		//if the ID is a duplicate, display error message
		if (current->id == id)
		{
			printf("ID is not unique.");
			return 0;
		}
		current = current->next;
	}
	//No duplicate ID
	return 1;
}

//
// FUNCTION : viewBooks
// DESCRIPTION :
// Iterates through a linked list of Book structs and prints their data.
// PARAMETERS :
// Book* head: Pointer to head element of the linked list
// RETURNS :
//
void viewBooks(Book* head)
{
	// Check if linked list is empty
	if (head == NULL) {
		printf("Error: List is empty.");
		return;
	}

	//Iterate until the current books next ptr is null
	Book* current = head;
	while (current != NULL) {
		printf("Book ID: %d\nBook Title: %s\nAuthor: %s\nPublication Year: %d\n\n", current->id, current->title, current->author, current->publication_year);
		current = current->next;
	}
	printf("End of data.");
}

//
// FUNCTION : updateBook
// DESCRIPTION :
// Updates the book
// PARAMETERS :
// Book* head : Pointer to the head of the list 
// int id : the ID of the book
// RETURNS :
// has no return parameters
void updateBook(Book* head, int id)
{
	//chars and strings
	char bookTitleUI[] = "title";
	char bookAuthorUI[] = "author";

	//used to run menu
	bool updateRun = true;
	bool validationCheck = true;

	//variable creation for validation check
	int matchChecker = 0;
	int menuOperation = 0;

	//creates a link to the list
	Book* iterator = head;
	//iterates through the linked list
	while (iterator != NULL && iterator->id != id)
	{
		iterator = iterator->next;
	}

	//if no book is found with given id the functions is not usable
	if (iterator == NULL)
	{
		printf("Book with ID %d not found. Returning to main menu.\n", id);
		return;
	}

	//validation check of the program
	while (validationCheck)
	{
		//checks if the correct book was found
		printf("The Book id matched too %s, written by %s, published %d is this correct? 1. Yes \n 2. No \n", iterator->title, iterator->author, iterator->publication_year);
		matchChecker = getUserNumber();
		if (matchChecker == 1)
		{
			validationCheck = false;
		}
		else if (matchChecker == 2)
		{
			printf("Unable to find book id. Returning to main menu\n");
			return;
		}
		else
		{
			printf("Invalid user input please enter 1 or 2\n");
		}
	}

	//book changer program
	while (updateRun)
	{
		printf("which would you like to change?\n");
		printf("1. Title\n 2. Author\n 3. Publication year\n 4. Return to Menu\n");
		menuOperation = getUserNumber();
		if (menuOperation != 1 && menuOperation != 4)
		{
			printf("Invalid input");
		}
		else if (menuOperation == 1)
		{
			//changes title
			getbookTitleOrAuthor(iterator->title, sizeof(iterator->title), bookTitleUI);
		}
		else if (menuOperation == 2)
		{
			//changes author
			getbookTitleOrAuthor(iterator->author, sizeof(iterator->author), bookAuthorUI);
		}
		else if (menuOperation == 3)
		{
			//changes publication year
			iterator->publication_year = getUserBookPublicationYear();
		}
		else
		{
			printf("returning to main menu");
			return;
		}
	}
	return;
}

//
// FUNCTION : deleteBook
// DESCRIPTION :
// 
// PARAMETERS :
//
// RETURNS :
//
void deleteBook(Book** head, int id)
{
	Book* catalog = *head;
	Book* prevElem = NULL; // Pointer to keep track of the element before the one being deleted

	if (*head == NULL) {
		printf("No books found in the catalog.\n"); // Feedback on empty catalog list
		return; // Stops execution if no books exist
	}



	// Update head after deletion if the book to delete is the first in the catalog
	if (catalog != NULL && catalog->id == id) {
		*head = catalog->next; // Change head to next element after deletion
		free(catalog); // Free the memory of the deleted element after deletion
		printf("Book with ID %d deleted successfully.\n", id);
		return; // Stops execution since deletion is done
	}

	// Update head after deletion if the code  to delete is somewhere in the middle or end
	while (catalog != NULL && catalog->id != id) {
		prevElem = catalog; // Update previous element
		catalog = catalog->next; // Move catalog list forward by one step after deletion
	}

	// If the book was not found
	if (catalog == NULL) {
		printf("Book ID not found.\n");
		return; // Stops execution since no book was deleted
	}

	// Unlink the node from the list
	prevElem->next = catalog->next;
	free(catalog);
	printf("Book with ID %d deleted successfully.\n", id);
}

//
// FUNCTION : searchBooks
// DESCRIPTION :
// Searches for books with partial/full matches of an inputted string, and prints them to the screen
// PARAMETERS :
// Book* head: Pointer to head element of the list
// const char* title: Pointer to inputted string
// RETURNS :
// void
void searchBooks(Book* head, const char* title)
{
	// Check if linked list is empty
	if (head == NULL) {
		printf("Error: List is empty.");
		return;
	}

	//Set current to the head element
	Book* current = head;

	//Iterate until current->next is null
	while (current != NULL) {

		//Checks if the inputted string is in the current title. If not, strstr returns a null pointer, so iterate to next book
		if (strstr(current->title, title) == NULL) {
			current = current->next;
		}
		else {
			// If a valid pointer is returned from strstr, print the current books title and iterate to next book
			printf("\nMatch found for '%s' in book '%s'\n", title, current->title);
			current = current->next;
		}
	}
	return;
	//	Searches for books containing the specified Title or partial Title.
}

//
// FUNCTION : freeList
// DESCRIPTION :
// empties out the linked list and frees all memory
// PARAMETERS :
// Book* head: Pointer to head element of the list
// RETURNS :
// void
void freeList(Book** head)
{
	//sets the pointers to the linked list
	Book* current = *head;
	Book* temp;

	//sorts through the linked list emptying out each item within
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	//removes the final pointer
	*head = NULL;
	return;
}

//
// FUNCTION : getUserNumber
// DESCRIPTION :
// gets user input and attempts to turn it into a readable number
// PARAMETERS :
//	N/A
// RETURNS :
// int userInput: returns the user input number or a -1 for error to allow menu to fail
//
int getUserNumber()
{
	int userInput;
	char buffer[50];
	//where user input is obtained
	fgets(buffer, sizeof(buffer), stdin);
	//checks if the input is a number anything higher than the highest case number is already handled
	//deal with decimal numbers
	if (sscanf_s(buffer, "%d", &userInput) < 0)
	{
		//sets the number to an error
		userInput = -1;
	}

	return userInput;
}

//
// FUNCTION : getUserBookId
// DESCRIPTION :
// used to gather the book id
// PARAMETERS :
// N/A
// RETURNS :
// void
int getUserBookId()
{
	bool bookIDSelector = true;
	bool validBookIdChecker = true;
	int bookId = 0;

	while (bookIDSelector)
	{
		int bookIDUserChecker = 0;
		while (validBookIdChecker)
		{
			printf("Please enter a valid book Id: ");
			//where user input is obtained
			bookId = getUserNumber();
			if (bookId < 0)
			{
				printf("\nInvalid book id.\n");
			}
			else
			{
				//exits loop
				validBookIdChecker = false;
			}
		}

		printf("Is %d the correct Id? \n1. Yes\n2. No\n", bookId);
		//user input validation on if they entered the correct data or not
		bookIDUserChecker = getUserNumber();
		if (bookIDUserChecker == 2)
		{
			//returns to the first loop to get correct user data
			validBookIdChecker = true;
		}
		else
		{
			//exits the loop
			bookIDSelector = false;
		}
	}
	return bookId;
}

//
// FUNCTION : getUserBookPublicationYear
// DESCRIPTION :
// used to gather the year the book was created
// PARAMETERS :
// N/A
// RETURNS :
// void
int getUserBookPublicationYear()
{
	int bookPublicationYear = 0;

	printf("Please enter a valid book Id: ");

	bool bookYearSelector = true;
	while (bookYearSelector)
	{
		//where user input is obtained
		bookPublicationYear = getUserNumber();
		//input validation
		printf("Is %d the correct Id? \n1. Yes\n2. No\n", bookPublicationYear);
		//used to determine if the user input the desired data
		int bookYearUserChecker = 0;
		bookYearUserChecker = getUserNumber();
		if (bookYearUserChecker < 0 || bookYearUserChecker > 2)
		{
			printf("\nInvalid book id.");
		}
		else if (bookYearUserChecker == 2)
		{
			printf("Please reinput Id: ");
		}
		else
		{
			//exits the loop
			bookYearSelector = false;
		}
	}
	return bookPublicationYear;
}

//
// FUNCTION : getUserbookTitleOrAuthor
// DESCRIPTION :
// used to gather both author and title of the function
// PARAMETERS :
// char titleAuthor[]: where the input for the title or author is stored
// int titleAuthorSize: used to limit user input
// int authorOrtitle: determines if the function is being used as a author or title gatherer
// RETURNS :
// void
void getbookTitleOrAuthor(char titleAuthor[], int titleAuthorSize, char authorOrTitle[])
{
	//authorortitle is used to determine what the funciton is used for as most the code is the same
	printf("Please enter the books %s: ", authorOrTitle);

	//used to keep loop going should the user fail to input the proper amount
	bool titleAuthorRun = true;
	while (titleAuthorRun)
	{
		//where user input is obtained
		fgets(titleAuthor, titleAuthorSize, stdin);
		//if the input string is full 
		if (strlen(titleAuthor) == titleAuthorSize - 1)
		{
			//used to gather all extra inputted data to contain function overflow
			int overflowCollector = getchar();
			while (overflowCollector != EOF && overflowCollector != '\n')
			{
				overflowCollector = getchar();
			}
		}
		//gets ride of the enter key press from the string
		int len = strlen(titleAuthor);
		if (len > 0 && titleAuthor[len - 1] == '\n')
		{
			titleAuthor[len - 1] = '\0';
		}

		//authorortitle is used to determine what the function is used for as most the code is the same
		printf("Is %s the correct %s? \n1. Yes\n2. No\n", titleAuthor, authorOrTitle);


		int booktitleAuthorChecker = 0;
		booktitleAuthorChecker = getUserNumber();

		//authorortitle is used to determine what the funciton is used for as most the code is the same
		if (booktitleAuthorChecker != 1 && booktitleAuthorChecker != 2)
		{
			printf("Invalid user input");
		}
		else if (booktitleAuthorChecker == 2)
		{
			printf("Please reinput %s: ", authorOrTitle);
		}
		else
		{
			titleAuthorRun = false;
		}
	}
	return;
}