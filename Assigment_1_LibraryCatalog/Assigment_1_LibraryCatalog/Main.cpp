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
	struct Book* next; // (pointer to the next book in the list)
}Book;

// Function prototypes
void deleteBook(Book** head, int id);

int main(void)
{
    // To be inserted on the the call to delete book ID
    char bookID[20]; // Buffer to hold book ID inputted by the user
    printf("Enter book ID to delete: "); // Prompt the user to enter the book ID
    fgets(bookID, sizeof(bookID), stdin);
    int id = atoi(bookID);
    deleteBook(&head, id);

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
// FUNCTION : deleteBook()
// DESCRIPTION :
//      Deletes a book from the catalog after the book ID has been inputted by the user
// PARAMETERS :
//      Book** head, int id
// RETURNS :
//      void
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