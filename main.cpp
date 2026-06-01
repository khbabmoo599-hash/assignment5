#include <iostream>
#include "LibraryBook.h"
#include "Functions.h"
using namespace std;

int main() {
    const int MAX_BOOKS = 100;
    LibraryBook library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add New Book\n2. Display All Books\n3. Borrow Book\n4. Return Book\n";
        cout << "5. Search Book by ID\n6. Display Overdue Books\n7. Calculate Total Fines\n8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(library, bookCount, MAX_BOOKS); break;
            case 2: displayBooks(library, bookCount); break;
            case 3: borrowBookMenu(library, bookCount); break;
            case 4: returnBookMenu(library, bookCount); break;
            case 5: searchBook(library, bookCount); break;
            case 6: displayOverdueBooks(library, bookCount); break;
            case 7: calculateTotalFines(library, bookCount); break;
            case 8: cout << "Exiting system." << endl; break;
            default: cout << "Invalid choice!" << endl;
        }
    } while (choice != 8);

    return 0;
}
