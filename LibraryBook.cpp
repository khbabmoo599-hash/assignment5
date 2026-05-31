#include "LibraryBook.h"
#include <iostream>
using namespace std;

LibraryBook::LibraryBook() {
    bookID = 0;
    title = "";
    author = "";
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

LibraryBook::LibraryBook(int id, string t, string a) {
    bookID = id;
    title = t;
    author = a;
    borrowerName = "";
    daysBorrowed = 0;
    isBorrowed = false;
}

// Destructor displaying a message when an object is destroyed
LibraryBook::~LibraryBook() {
    cout << "Book ID " << bookID << " (\"" << title << "\") object is destroyed." << endl;
}

int LibraryBook::getBookID() const { return bookID; }
string LibraryBook::getTitle() const { return title; }
string LibraryBook::getAuthor() const { return author; }
string LibraryBook::getBorrowerName() const { return borrowerName; }
int LibraryBook::getDaysBorrowed() const { return daysBorrowed; }
bool LibraryBook::getIsBorrowed() const { return isBorrowed; }

void LibraryBook::setBorrowerName(string name) { borrowerName = name; }
void LibraryBook::setDaysBorrowed(int days) { daysBorrowed = days; }
void LibraryBook::setIsBorrowed(bool status) { isBorrowed = status; }

void LibraryBook::displayBookDetails() const {
    cout << "ID: " << bookID << " | Title: " << title << " | Author: " << author;
    if (isBorrowed) {
        cout << " | Status: Borrowed by " << borrowerName << " (" << daysBorrowed << " days)";
    } else {
        cout << " | Status: Available";
    }
    cout << endl;
}
