#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
using namespace std;

class LibraryBook {
private:
    int bookID;
    string title;
    string author;
    string borrowerName;
    int daysBorrowed;
    bool isBorrowed;

public:
    // Constructors & Destructor
    LibraryBook();
    LibraryBook(int id, string t, string a);
    ~LibraryBook();

    // Getters
    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getIsBorrowed() const;

    // Setters
    void setBorrowerName(string name);
    void setDaysBorrowed(int days);
    void setIsBorrowed(bool status);

    // Helper Method
    void displayBookDetails() const;
};

#endif
