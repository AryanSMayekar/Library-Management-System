#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book structure
struct Book {
    int id;
    string title;
    string author;
};

class Library {
private:
    vector<Book> books;

    // Function to sort books by ID (Simple Method)
    void sortBooksByID() {
        for (size_t i = 0; i < books.size(); i++) {
            for (size_t j = i + 1; j < books.size(); j++) {
                if (books[i].id > books[j].id) {
                    swap(books[i], books[j]); // Swap if out of order
                }
            }
        }
    }

public:
    // Function to add a book
    void addBook(int id, string title, string author) {
        books.push_back({id, title, author});
        cout << "Book added successfully!" << endl;
    }

    // Function to display books
    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        
        sortBooksByID(); // Sorting books before displaying
        
        cout << "\nLibrary Books:\n";
        for (const auto& book : books) {
            cout << "\nID: " << book.id << "\nTitle: " << book.title << "\nAuthor: " << book.author << endl;
        }
    }

    // Function to search for a book
    void searchBook(int id) {
        for (const auto& book : books) {
            if (book.id == id) {
                cout << "\nBook Found:" << book.title << "\n by " << book.author << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Function to delete a book
    void deleteBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book deleted successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library lib;
    int choice, id;
    string title, author;

    do {
        cout << "\nLibrary Management System";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Delete Book";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nEnter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "\nEnter Title: ";
                getline(cin, title);
                cout << "\nEnter Author: ";
                getline(cin, author);
                lib.addBook(id, title, author);
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                cout << "Enter Book ID to search: ";
                cin >> id;
                lib.searchBook(id);
                break;
            case 4:
                cout << "Enter Book ID to delete: ";
                cin >> id;
                lib.deleteBook(id);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
