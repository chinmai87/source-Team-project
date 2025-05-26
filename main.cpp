#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int year;
    bool isIssued;

    void display() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Year: " << year << ", Issued: " << (isIssued ? "Yes" : "No") << endl;
    }
};

vector<Book> library;

// Add a new book
void addBook() {
    Book b;
    cout << "Enter book ID: ";
    cin >> b.id;
    cin.ignore();

    cout << "Enter title: ";
    getline(cin, b.title);

    cout << "Enter author: ";
    getline(cin, b.author);

    cout << "Enter publication year: ";
    cin >> b.year;
    cin.ignore();

    b.isIssued = false;
    library.push_back(b);
    cout << "Book added successfully.\n";
}

// Display all books
void displayBooks() {
    cout << "\nLibrary Books:\n";
    for (const auto& b : library) {
        b.display();
    }
}

// Search book by ID
void searchBook() {
    int id;
    cout << "Enter book ID to search: ";
    cin >> id;
    cin.ignore();

    for (const auto& b : library) {
        if (b.id == id) {
            b.display();
            return;
        }
    }
    cout << "Book not found.\n";
}

// Search books by author name (Suhas's contribution)
void searchBooksByAuthor() {
    cout << "Enter author name to search: ";
    string authorName;
    getline(cin, authorName);

    bool found = false;
    for (const auto& b : library) {
        if (b.author == authorName) {
            b.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by author: " << authorName << endl;
    }
}

// Issue a book
void issueBook() {
    int id;
    cout << "Enter book ID to issue: ";
    cin >> id;
    cin.ignore();

    for (auto& b : library) {
        if (b.id == id) {
            if (!b.isIssued) {
                b.isIssued = true;
                cout << "Book issued successfully.\n";
            } else {
                cout << "Book is already issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Return a book
void returnBook() {
    int id;
    cout << "Enter book ID to return: ";
    cin >> id;
    cin.ignore();

    for (auto& b : library) {
        if (b.id == id) {
            if (b.isIssued) {
                b.isIssued = false;
                cout << "Book returned successfully.\n";
            } else {
                cout << "Book was not issued.\n";
            }
            return;
        }
    }
    cout << "Book not found.\n";
}

// Shreyas's contribution: Display books sorted by publication year (descending)
void displayBooksSortedByYearDesc() {
    if (library.empty()) {
        cout << "No books in the library.\n";
        return;
    }
    vector<Book> sortedBooks = library;
    sort(sortedBooks.begin(), sortedBooks.end(),
         [](const Book& a, const Book& b) { return a.year > b.year; });

    cout << "\nBooks sorted by publication year (newest first):\n";
    for (const auto& b : sortedBooks) {
        b.display();
    }
}

void mainMenu() {
    int choice;
    while (true) {
        cout << "\nLibrary Management System Menu:\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book by ID\n";
        cout << "4. Search Books by Author\n";  // Suhas's contribution
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Display Books Sorted by Year (Descending)\n";  // Shreyas's contribution
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchBook(); break;
            case 4: searchBooksByAuthor(); break;
            case 5: issueBook(); break;
            case 6: returnBook(); break;
            case 7: displayBooksSortedByYearDesc(); break;
            case 8: cout << "Exiting...\n"; return;
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

int main() {
    cout << "Welcome to Library Management System\n";
    mainMenu();
    return 0;
}
