#include <iostream>
#include "Student.h"
#include "Book.h"
#pragma once

class LibrarySystem
{
public:
    LibrarySystem () ;
    ~LibrarySystem () ;
    void addBook ( const int bookId , const std::string name , const std::string authors ,const int year ) ;
    void deleteBook ( const int bookId ) ;
    void addStudent ( const int studentId , const std::string name ) ;
    void deleteStudent ( const int studentId ) ;
    void checkoutBook ( const int bookId , const int studentId ) ;
    void returnBook ( const int bookId ) ;
    void showAllBooks () ;
    void showBook ( const int bookId ) ;
    void showStudent ( const int studentId ) ;


private:
    Student* studentList;
    Book* bookList;
    int studentCount;
    int bookCount;
    int width;
};
