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


void displayBooks() {
    cout << "\nLibrary Books:\n";
    for (const auto& b : library) {
        b.display();
    }
}


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

// Search books by author name
void searchBooksByAuthor() {
    cout << "Enter author name to search: ";
    string authorName;
    cin.ignore();
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


void displayIssuedAndAvailableCount() {
    int issuedCount = 0;
    int availableCount = 0;

    for (const auto& b : library) {
        if (b.isIssued) issuedCount++;
        else availableCount++;
    }

    cout << "\nTotal books issued: " << issuedCount << endl;
    cout << "Total books available: " << availableCount << endl;
}

// Delete a book by ID
void deleteBook() {
    int id;
    cout << "Enter book ID to delete: ";
    cin >> id;
    cin.ignore();

    auto it = remove_if(library.begin(), library.end(),
                        [id](const Book& b) { return b.id == id; });
    if (it != library.end()) {
        library.erase(it, library.end());
        cout << "Book deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
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
        cout << "8. Display Issued and Available Book Count\n";  // Prajwal's contribution
        cout << "9. Delete a Book\n";  // Sudharshan's contribution
        cout << "10. Exit\n";
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
            case 8: displayIssuedAndAvailableCount(); break;
            case 9: deleteBook(); break;
            case 10: cout << "Exiting...\n"; return;
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

int main() {
    cout << "Welcome to Library Management System\n";
    mainMenu();
    return 0;
}
