/*
* FILE : mySourceFile.c
* PROJECT : PROG1345 - Assignment #1
* PROGRAMMER : Joe Student
* FIRST VERSION : 2025-01-28
* DESCRIPTION :
* The functions in this file are used to …
*/

//Libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Constants
#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100
#define KEYWORD_LENGTH 50

//structs
typedef struct 
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next; //(pointer to the next book in the list)
}Book;

//Prototypes
void addBook(Book** head, int id, const char* title, const char* author, int publication_year);
int isUniqueID(Book* head, int id);

int main(void)
{

	//words and stuff


	return 0;
}

//
// FUNCTION :
// DESCRIPTION :
// 
// PARAMETERS :
//
// RETURNS :
//
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
	//Book Title
	printf("Enter Book Title: ");
	fgets(newBook->title, MAX_TITLE_LENGTH, stdin);
	newBook->title[strcspn(newBook->title, "\n")] = '\0';
	//Book Author
	printf("Enter Book Author: ");
	fgets(newBook->author, MAX_AUTHOR_LENGTH, stdin);
	newBook->author[strcspn(newBook->author, "\n")] = '\0';
	//Book Publication Year
	printf("Enter Publication Year: ");
	scanf("%d", &newBook->publication_year);
	
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
// FUNCTION :
// DESCRIPTION :
// 
// PARAMETERS :
//
// RETURNS :
//
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
// FUNCTION :
// DESCRIPTION :
// 
// PARAMETERS :
//
// RETURNS :
//
void viewBooks(Book* head)
{
	//	Traverses the linked list and prints details of all books.
}

//
// FUNCTION :
// DESCRIPTION :
// 
// PARAMETERS :
//
// RETURNS :
//
void updateBook(Book* head, int id)
{
	//	Searches for a book by ID and updates its details.
}

//
// FUNCTION :
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
// FUNCTION :
// DESCRIPTION :
// 
// PARAMETERS :
//
// RETURNS :
//
void searchBooks(Book* head, const char* title)
{
	//	Searches for books containing the specified Title or partial Title.
}
//	Important Note
//	3. Ensure proper memory management with functions to free memory when books are deleted or the
//	program exits.