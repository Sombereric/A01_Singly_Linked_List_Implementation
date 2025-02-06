/*
* FILE : mySourceFile.c
* PROJECT : PROG1345 - Assignment #1
* PROGRAMMER : Joe Student
* FIRST VERSION : 2025-01-28
* DESCRIPTION :
* The functions in this file are used to …
*/

#include <stdio.h>
#include <string.h>

typedef struct Book
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next; //(pointer to the next book in the list)
} Book;


void viewBooks(Book*);
void searchBooks(Book*, const char*);

int main(void)
{
	// Statically defining books
	Book book1 = { 1, "asdf", "fuckface", 5000, NULL };
	Book book2 = { 2, "Clean Code", "Robert C. Martin", 2008, NULL };
	Book book3 = { 3, "Introduction to Algorithms", "Thomas H. Cormen", 1990, NULL };

	// Linking books to form a linked list
	book1.next = &book2;
	book2.next = &book3;
	book3.next = NULL;  // Last book points to NULL

	viewBooks(&book1);

	char hi[] = "o";
	searchBooks(&book1, hi);


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

	//Iterate until the current books next ptr is null
	Book* current = head;
	while (current != NULL) {
		printf("Book ID: %d\nBook Title: %s\nAuthor: %s\nPublication Year: %d\n\n", current->id, current->title, current->author, current->publication_year);
		current = current->next;
	}
	printf("End of data.");
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
	// Check if linked list is empty
	if (head == NULL) {
		printf("Error: List is empty.");
		return;
	}

	//Set current to the head element
	Book* current = head;

	//Iterate until current->next is null
	while (current != NULL) {

		//Checks if the inputted string is in the current title, if not, strstr returns a null pointer, so iterate to next book
		if (strstr(current->title, title) == NULL) {
			current = current->next;
		}
		else {
			// If a valid pointer is returned from strstr, print the current books title and iterate to next book
			printf("\nMatch found for %s in book %s\n", title, current->title);
			current = current->next;
		}
	}
	return;
	//	Searches for books containing the specified Title or partial Title.
}
//	Important Note
//	3. Ensure proper memory management with functions to free memory when books are deleted or the
//	program exits.