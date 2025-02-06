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

//protoypes/input/output functions
int getUserNumber();
int getUserBookId();
char getUserBookTitle();
char getUserbookAuthor();
int getUserBookPublicationYear();
int isUniqueID(Book* head, int id);
void displayMenu();

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
	Book* head = NULL;
	int userPickedId = 0;
	int yesNoChecker = 0;
	//words and stuff
	char bookSearchTitle[50] = "";
	bool runTimer = true;
	while (runTimer)
	{
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
					int bookId = getUserBookId();
					char bookTitle[50] = getUserBookTitle();
					char bookAuthor[50] = getUserbookAuthor();
					int bookPublicationYear = getUserBookPublicationYear();
					//check if id is already in use NICK!
					//calls the addbook function.
					addBook(&head, bookId, bookTitle, bookAuthor, bookPublicationYear);
					printf("Book successfully added.");
				}
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
				char bookTitle[50] = getUserBookTitle();
				searchBooks(head, bookTitle);
				break;
			case ExitProgram:
				userInput = false;
				break;
			default:
				printf("Invalid input, please select 1-6");
				break;
		}	
	}
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
	scanf("%d", &id);
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
	Book* iterator = head;
	if (iterator->id == id)
	{
		printf("The Book id matched too %s, is this correct? 1. Yes \n 2. No \n", iterator->title);
		int matchCheckertitle = 0;
		char newbooktitle[50] = 0;
		matchCheckertitle = getUserNumber();
		if (matchCheckertitle < 0 || matchCheckertitle > 2)
		{
			printf("Invalid user input");
		}
		else if (matchCheckertitle == 2)
		{
			printf("Please Change Title: ");
		}
		else
		{
			matchCheckertitle = false;
		}
	}
	else
	{
		iterator = iterator->next;
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
	// Removes a book by ID from the linked list and frees the memory.
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
//	Important Note
//	3. Ensure proper memory management with functions to free memory when books are deleted or the
//	program exits.

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
int getUserBookId()
{
	bool bookIDSelector = true;
	int bookId = 0;
	printf("Please enter a valid book Id: ");
	while (bookIDSelector)
	{
		//where user input is obtained
		bookId = getUserNumber();
		printf("Is %d the correct Id? \n1. Yes\n2. No\n", bookId);
		int bookIDUserChecker = 0;
		bookIDUserChecker = getUserNumber();
		if (bookIDUserChecker < 0 || bookIDUserChecker > 2)
		{
			printf("\nInvalid book id.");
		}
		else if (bookIDUserChecker == 2)
		{
			printf("Please reinput Id: ");
		}
		else
		{
			bookIDSelector = false;
		}
	}
	return bookId;
}
char getUserBookTitle()
{
	char bookTitle[50] = "";
	bool titleSelector = true;
	printf("Please enter a valid book title: ");
	while (titleSelector)
	{
		//where user input is obtained
		fgets(bookTitle, sizeof(bookTitle), stdin);
		int len = strlen(bookTitle);
		if (len > 0 && bookTitle[len - 1] == '\n')
		{
			bookTitle[len - 1] = '\0';
		}
		printf("Is %s the correct title? \n1. Yes\n2. No\n", bookTitle);
		int bookTitleUserChecker = 0;
		bookTitleUserChecker = getUserNumber();
		if (bookTitleUserChecker < 0 || bookTitleUserChecker > 2)
		{
			printf("Invalid user input");
		}
		else if (bookTitleUserChecker == 2)
		{
			printf("Please reinput Title: ");
		}
		else
		{
			titleSelector = false;
		}
	}
	return bookTitle;
}
char getUserbookAuthor()
{
	char bookAuthor[50] = "";
	printf("Please enter the books author: ");
	bool authorSelector = true;
	while (authorSelector)
	{
		//where user input is obtained
		fgets(bookAuthor, sizeof(bookAuthor), stdin);
		int len = strlen(bookAuthor);
		if (len > 0 && bookAuthor[len - 1] == '\n')
		{
			bookAuthor[len - 1] = '\0';
		}
		printf("Is %s the correct author? \n1. Yes\n2. No\n", bookAuthor);
		int bookAuthorUserChecker = 0;
		bookAuthorUserChecker = getUserNumber();
		if (bookAuthorUserChecker < 0 || bookAuthorUserChecker > 2)
		{
			printf("Invalid user input");
		}
		else if (bookAuthorUserChecker == 2)
		{
			printf("Please reinput Author: ");
		}
		else
		{
			authorSelector = false;
		}
	}
	return bookAuthor;
}
int getUserBookPublicationYear()
{
	bool bookYearSelector = true;
	int bookPublicationYear = 0;
	printf("Please enter a valid book Id: ");
	while (bookYearSelector)
	{
		//where user input is obtained
		bookPublicationYear = getUserNumber();
		printf("Is %d the correct Id? \n1. Yes\n2. No\n", bookPublicationYear);
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
			bookYearSelector = false;
		}
	}
<<<<<<< HEAD
	return bookPublicationYear;
}
=======
	return = bookPublicationYear;
}
>>>>>>> Development_Branch
