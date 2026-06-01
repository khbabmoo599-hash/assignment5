#include "Functions.h"
#include <iostream>
#include <string>
using namespace std;

void addBook(LibraryBook books[], int &bookCount, int maxBooks) {
    if (bookCount >= maxBooks) {
        cout << "Library system is full!" << endl;
        return;
    }
    int id;
    string title, author;
    
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);

    books[bookCount] = LibraryBook(id, title, author);
    bookCount++;
    cout << "Book added successfully!" << endl;
}

void displayBooks(const LibraryBook books[], int bookCount) {
    if (bookCount == 0) {
        cout << "No books available in the library." << endl;
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        books[i].displayBookDetails();
    }
}

void borrowBookMenu(LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to borrow: ";
    cin >> id;
    
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (books[i].getIsBorrowed()) {
                cout << "Book is already borrowed." << endl;
                return;
            }
            string name;
            int days;
            cin.ignore();
            cout << "Enter Borrower Name: ";
            getline(cin, name);
            cout << "Enter Borrowing Days: ";
            cin >> days;

            books[i].setIsBorrowed(true);
            books[i].setBorrowerName(name);
            books[i].setDaysBorrowed(days);
            cout << "Book borrowed successfully." << endl;
            return;
        }
    }
    cout << "Book ID not found." << endl;
}

void returnBookMenu(LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            if (!books[i].getIsBorrowed()) {
                cout << "Book is already in the library." << endl;
                return;
            }
            books[i].setIsBorrowed(false);
            books[i].setBorrowerName("");
            books[i].setDaysBorrowed(0);
            cout << "Book returned successfully." << endl;
            return;
        }
    }
    cout << "Book ID not found." << endl;
}

void searchBook(const LibraryBook books[], int bookCount) {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    for (int i = 0; i < bookCount; i++) {
        if (books[i].getBookID() == id) {
            cout << "Book Found:" << endl;
            books[i].displayBookDetails();
            return;
        }
    }
    cout << "Book ID not found." << endl;
}

void displayOverdueBooks(const LibraryBook books[], int bookCount) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getIsBorrowed() && books[i].getDaysBorrowed() > 14) {
            books[i].displayBookDetails();
            cout << "-> Overdue by " << (books[i].getDaysBorrowed() - 14) << " days." << endl;
            found = true;
        }
    }
    if (!found) cout << "No overdue books." << endl;
}

void calculateTotalFines(const LibraryBook books[], int bookCount) {
    double totalFine = 0;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getIsBorrowed() && books[i].getDaysBorrowed() > 14) {
            totalFine += (books[i].getDaysBorrowed() - 14) * 1.0; 
        }
    }
    cout << "Total Fines: $" << totalFine << endl;
}
