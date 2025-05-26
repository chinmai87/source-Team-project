 //Library Management System 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool issued;

    void input() {
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        issued = false;
    }

    void display() const {
        cout << left << setw(10) << id << setw(30) << title << setw(20) << author << setw(10) << (issued ? "Yes" : "No") << endl;
    }
};

class Library {
private:
    vector<Book> books;
    const string filename = "books.dat";

    void loadFromFile() {
        ifstream fin(filename);
        Book b;
        while (fin >> b.id) {
            fin.ignore();
            getline(fin, b.title);
            getline(fin, b.author);
            fin >> b.issued;
            books.push_back(b);
        }
        fin.close();
    }

    void saveToFile() {
        ofstream fout(filename);
        for (const auto& b : books) {
            fout << b.id << endl
                 << b.title << endl
                 << b.author << endl
                 << b.issued << endl;
        }
        fout.close();
    }

public:
    Library() { loadFromFile(); }
    ~Library() { saveToFile(); }

    void addBook() {
        Book b;
        b.input();
        books.push_back(b);
        cout << "Book added successfully!\n";
    }

    void viewBooks() {
        cout << left << setw(10) << "ID" << setw(30) << "Title" << setw(20) << "Author" << setw(10) << "Issued" << endl;
        for (const auto& b : books)
            b.display();
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        for (auto& b : books) {
            if (b.id == id) {
                if (b.issued) {
                    cout << "Book is already issued.\n";
                } else {
                    b.issued = true;
                    cout << "Book issued successfully.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;
        for (auto& b : books) {
            if (b.id == id) {
                if (!b.issued) {
                    cout << "Book was not issued.\n";
                } else {
                    b.issued = false;
                    cout << "Book returned successfully.\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;
    do {
        cout << "\n--- Library Management Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. View All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lib.addBook();
            break;
        case 2:
            lib.viewBooks();
            break;
        case 3:
            lib.issueBook();
            break;
        case 4:
            lib.returnBook();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
