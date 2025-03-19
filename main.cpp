#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

class Book {
private:
    string title;
    string author;
    string ISBN;

public:
    Book() {}
    Book(const string& t, const string& a, const string& i)
        : title(t), author(a), ISBN(i) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return ISBN; }

    void setTitle(const string& t) { title = t; }
    void setAuthor(const string& a) { author = a; }
    void setISBN(const string& i) { ISBN = i; }
};

// Function to add a book to the file
void addBook() {
    Book newBook;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer

    cout << "Enter Book Title: ";
    string title;
    getline(cin, title);
    newBook.setTitle(title);

    cout << "Enter Book Author: ";
    string author;
    getline(cin, author);
    newBook.setAuthor(author);

    cout << "Enter Book ISBN: ";
    string isbn;
    getline(cin, isbn);
    newBook.setISBN(isbn);

    ofstream outFile("Books.txt", ios::app);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing." << endl;
        return;
    }
    outFile << newBook.getTitle() << " : "
            << newBook.getAuthor() << " : "
            << newBook.getISBN() << endl;
    outFile.close();

    cout << "Book added successfully!" << endl;
}

// Function to search for a book by title
void searchBook() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
    cout << "Enter the title of the book to search: ";
    string searchTitle;
    getline(cin, searchTitle);

    ifstream inFile("Books.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    bool found = false;
    string line;
    while (getline(inFile, line)) {
        // Each line format: Title : Author : ISBN
        // We can check if the line starts with or contains the title.
        size_t pos = line.find(searchTitle);
        if (pos != string::npos) {
            cout << "Book found: " << line << endl;
            found = true;
        }
    }
    inFile.close();

    if (!found) {
        cout << "No book with the title \"" << searchTitle << "\" was found." << endl;
    }
}

// Function to display all books
void displayAllBooks() {
    ifstream inFile("Books.txt");
    if (!inFile) {
        cerr << "Error: Unable to open file for reading." << endl;
        return;
    }

    cout << "\n--- List of All Books ---\n";
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();
}

int main() {
    int choice;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\n=== Book Management System ===" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Search for a Book" << endl;
        cout << "3. Display All Books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            // Clear error state and discard invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBook();
                break;
            case 3:
                displayAllBooks();
                break;
            case 4:
                exitProgram = true;
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
