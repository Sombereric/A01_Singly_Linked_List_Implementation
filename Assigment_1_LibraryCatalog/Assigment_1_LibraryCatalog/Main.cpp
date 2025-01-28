/*
* FILE : mySourceFile.c
* PROJECT : PROG1345 - Assignment #1
* PROGRAMMER : Joe Student
* FIRST VERSION : 2025-01-28
* DESCRIPTION :
* The functions in this file are used to …
*/

typedef struct 
{
	int id;
	char title[100];
	char author[100];
	int publication_year;
	struct Book* next; //(pointer to the next book in the list)
}book;

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
	//	Adds a new book to the end of the linked list.
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