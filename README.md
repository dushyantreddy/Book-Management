# Book-Management

A C++ program to demonstrate **file handling** by managing a collection of books. This project allows you to add new books to a file, search for existing books, and display all stored books. It is an example of how to perform basic read/write operations on text files in C++.

---

## Table of Contents
1. [Description](#description)  
2. [Features](#features)  
3. [Files Used](#files-used)  
4. [Requirements](#requirements)  
5. [How to Compile and Run](#how-to-compile-and-run)  
6. [Usage Instructions](#usage-instructions)  
7. [Troubleshooting](#troubleshooting)  
8. [Future Enhancements](#future-enhancements)  
9. [Author](#author)

---

## Description
The **Book Management** system is a command-line program that demonstrates how to:
- Write book information to a text file.
- Search and retrieve book data from the file.
- Display all records stored in the file.

This system shows how to handle persistent data storage (via text files) in C++, ensuring that data is preserved even after the program terminates.

---

## Features
1. **Add a New Book**  
   Prompts you for the title, author, and ISBN, then stores these details in a file.

2. **Search for a Book**  
   Searches the file based on a user-input title and displays the matching book record(s).

3. **Display All Books**  
   Reads all book entries from the file and displays them on the console.

---

## Files Used
- **`Books.txt`**  
  Stores book information in the format:  
  ```
  Title : Author : ISBN
  ```

---

## Requirements
- A C++ compiler (GCC, Clang, or MSVC).
- Permission to create and modify files in the working directory.
- Basic knowledge of compiling and running C++ programs.

---

## How to Compile and Run
1. **Open a terminal or command prompt** in the project directory.  
2. **Compile** the code using:
   ```bash
   g++ book_management.cpp -o books
   ```
3. **Run** the resulting program:
   - On Linux/Mac:
     ```bash
     ./books
     ```
   - On Windows:
     ```bash
     books.exe
     ```

---

## Usage Instructions
After running the executable:
1. You will see a **menu** with four options:
   - **Add a Book**  
     Enter the book’s details (title, author, ISBN). The program will store them in `Books.txt`.
   - **Search for a Book**  
     Enter the title of the book you want to find. If found, the matching record(s) will be shown.
   - **Display All Books**  
     Lists every book currently in `Books.txt`.
   - **Exit**  
     Exits the application.

2. **Repeat** any of these actions as needed. Each time you add a book, it will be **appended** to the existing file.

---

## Troubleshooting
1. **Error: Unable to open file for reading/writing**  
   - Ensure that `Books.txt` is not open in another program (e.g., a text editor).  
   - Check that you have read/write **permissions** to the directory.  
   - Verify the **file path** if you have moved or renamed the file.

2. **Unexpected behavior or crashes**  
   - Make sure you **enter valid input**.  
   - Clear or delete the `Books.txt` file if it becomes corrupted or has invalid content.

---


## Author
Developed by Dushyant Reddy
