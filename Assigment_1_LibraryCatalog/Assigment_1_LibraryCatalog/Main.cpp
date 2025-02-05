/*
* FILE : mySourceFile.c
* PROJECT : PROG1345 - Assignment #1
* PROGRAMMER : Joe Student
* FIRST VERSION : 2025-01-28
* DESCRIPTION :
* The functions in this file are used to …
*/

#include <stdio.h>

typedef struct Book
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next; //(pointer to the next book in the list)
} Book;


void viewBooks(Book*);

int main(void)
{
	// Statically defining books
	Book book1;
	Book book2 = { 2, "Clean Code", "Robert C. Martin", 2008, NULL };
	Book book3 = { 3, "Introduction to Algorithms", "Thomas H. Cormen", 1990, NULL };

	// Linking books to form a linked list
	book1.next = &book2;
	book2.next = &book3;
	book3.next = NULL;  // Last book points to NULL

	viewBooks(&book1);
	
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
	// asidknfoasdfl
}

//
// FUNCTION : viewBooks
// DESCRIPTION :
// Iterates through a linked list of Book structs and prints their data.
// PARAMETERS :
// Book* head: Pointer to head element of the linked list
// RETURNS :
// void
void viewBooks(Book* head)
{
	// Check if linked list is empty
	if (head == NULL) {
		printf("Error: List is empty.");
		return;
	}

	//Iterate until next ptr is null
	Book* current = head;
	while (current != NULL) {
		printf("Book ID: %d\nBook Title: %s\nAuthor: %s\nPublication Year: %d\n\n", current->id, current->title, current->author, current->publication_year);
		current = current->next;
	}
	printf("End of data.");
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