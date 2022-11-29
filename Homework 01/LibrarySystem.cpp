#include <iostream>
#include "LibrarySystem.h"
#include "Student.h"
#include <iomanip>

using namespace std;
void returnBook(const int);

LibrarySystem::LibrarySystem()
{
    studentList = new Student[20];
    bookList = new Book[50];
    studentCount = 0;
    bookCount = 0;
    width = 25;
}
LibrarySystem::~LibrarySystem()
{


}
void LibrarySystem::addBook(const int id,const std::string name, const std::string authors,const int year)
{
    bool found = false;
    for(int i = 0; i < bookCount; i++)
    {
        if(bookList[i].getId() == id)
        {
            found = true;
            break;
        }
    }
    if(found)
    {
        cout << "Book " << id << " already exists" << endl;
    }
    else
    {
        bookList[bookCount++] = Book(id,name,authors,year);
        cout << "Book " << id << " has been added" << endl;
    }

}
void LibrarySystem::addStudent(const int id,const std::string name)
{
    bool found = false;
    for(int i = 0; i < studentCount; i++)
    {
        if(studentList[i].getStudentId() == id)
        {
            found = true;
            break;

        }
    }
    if(found)
    {
        cout << "Student " << id << " already exists " << endl;
    }
    else
    {
        studentList[studentCount++] = Student(id,name);
        cout << "Student " << id << " has been added " << endl;

    }



}
void LibrarySystem::checkoutBook(const int bookId, const int studentId)
{
    bool bookFound = false;
    bool studentFound = false;
    bool checkedOut = false;
    int foundLocation2 = 0;
    int foundLocation1 = 0;
    int number = 0;
    for(int i = 0; i < bookCount; i++)
    {
        if(bookList[i].getId() == bookId)
        {
            bookFound = true;
            foundLocation1 = i;
            break;
        }
    }
    for(int i = 0; i < studentCount; i++)
    {
        if(studentList[i].getStudentId() == studentId)
        {
            studentFound = true;
            foundLocation2 = i;
            break;
        }
    }
    if(bookFound)
    {
        if(studentFound)
        {

            if(bookList[foundLocation1].getStatus())
            {
                cout << "Book " << bookId << " has been already checked out by another student" << endl;
            }
            else
            {
                number = studentList[foundLocation2].getCheckedOutBookCount();
                studentList[foundLocation2].checkedOutBooksByStudent[number] = Book(bookList[foundLocation1].getId(),bookList[foundLocation1].getName(),bookList[foundLocation1].getAuthors(),bookList[foundLocation1].getYear());
                studentList[foundLocation2].checkedOutBooksByStudent[number].setStatus(true);
                bookList[foundLocation1].setStatus(true);
                bookList[foundLocation1].setOwnerId(studentId);
                studentList[foundLocation2].checkedOutBooksByStudent[number++].setOwnerId(studentId);
                //number++;
                studentList[foundLocation2].setCheckedOutBookCount(number);
                cout << "Book " << bookId << " has been checked out by student " << studentId << endl;
            }

        }
        else
        {
            cout << "Student " << studentId << " does not exist for checkout" << endl;
        }
    }
    else
    {
        cout << "Book " << bookId << " does not exist for checkout" << endl;

    }



}
void LibrarySystem::deleteBook(const int id)
{
    bool found = false;
    int foundLocation = 0;
    int number = 0;
    int studentIndex = 0;
    int checkedOutBookIndex = 0;
    for(int i = 0; i < bookCount; i++)
    {
        if(bookList[i].getId() == id)
        {
            found = true;
            foundLocation = i;
            break;
        }
    }
    if(found)
    {
        if(bookList[foundLocation].getStatus())
        {
            returnBook(id);
            Book* tempBookList = new Book[bookCount];
            for(int i = 0; i <= foundLocation-1;i++)
            {
                tempBookList[i] = bookList[i];
            }
            bookList[foundLocation] = Book();
            for(int i = foundLocation+1; i < bookCount; i++)
            {
                tempBookList[i-1] = bookList[i];
            }
            delete[] bookList;
            bookList = tempBookList;
            for(int i = 0; i < studentCount; i++)
            {
                for(int j = 0; j < studentList[i].getCheckedOutBookCount(); j++)
                {
                    if(studentList[i].checkedOutBooksByStudent[j].getId() == id)
                    {
                        checkedOutBookIndex = j;
                        studentIndex = i;
                        number = studentList[studentIndex].getCheckedOutBookCount();
                        Book* tempCheckedOutBooksList = new Book[number];
                        if( checkedOutBookIndex !=0 && number != 1)
                        {
                            for(int k = 0; k <= checkedOutBookIndex - 1;k++)
                            {
                                tempCheckedOutBooksList[k] = studentList[studentIndex].checkedOutBooksByStudent[k];
                                tempCheckedOutBooksList[k].setOwnerId(studentList[studentIndex].getStudentId());
                            }
                            tempCheckedOutBooksList[checkedOutBookIndex] = Book();
                            for(int k = checkedOutBookIndex+1; k < number; k++)
                            {

                                tempCheckedOutBooksList[k-1] = studentList[studentIndex].checkedOutBooksByStudent[k];
                                tempCheckedOutBooksList[k-1].setOwnerId(studentList[studentIndex].getStudentId());
                            }

                        }
                        else
                        {
                            tempCheckedOutBooksList[checkedOutBookIndex] = studentList[studentIndex].checkedOutBooksByStudent[checkedOutBookIndex+1];
                            studentList[studentIndex].checkedOutBooksByStudent[checkedOutBookIndex] = Book();
                            //tempCheckedOutBooksList[checkedOutBookIndex].setOwnerId(studentList[studentIndex].getStudentId());

                        }
                        delete[] studentList[studentIndex].checkedOutBooksByStudent;
                        studentList[studentIndex].checkedOutBooksByStudent = tempCheckedOutBooksList;
                        studentList[studentIndex].setCheckedOutBookCount(number);

                    }
                }
            }
            cout << "Book " << id << " has been deleted" << endl;
            bookCount--;
            number--;

        }
        else
        {
            Book* tempBookList = new Book[bookCount];
            for(int i = 0; i <= foundLocation-1;i++)
            {
                tempBookList[i] = bookList[i];
            }
            bookList[foundLocation] = Book();
            for(int i = foundLocation+1; i < bookCount; i++)
            {
                tempBookList[i-1] = bookList[i];
            }
            delete[] bookList;
            bookList = tempBookList;
            cout << "Book " << id << " has not been checked out " << endl;
            cout << "Book " << id << " has been deleted" << endl;
            bookCount--;


        }
    }
    else
    {
        cout << "Book " << id << " does not exist " << endl;

    }


}
void LibrarySystem::deleteStudent(const int id)
{
    bool found = false;
    int foundLocation = 0;
    for(int i = 0; i < studentCount; i++)
    {
        if(studentList[i].getStudentId() == id)
        {
            found = true;
            foundLocation = i;
        }
    }
    if(found)
    {
        if(studentList[foundLocation].getCheckedOutBookCount() != 0)
        {
            for(int i = 0; i < bookCount; i++)
            {
                if(bookList[i].getOwnerId() == id)
                {
                    returnBook(bookList[i].getId());
                }
            }
            Student* tempStudentList = new Student[studentCount];
            for(int i = 0; i <= foundLocation-1;i++)
            {
                tempStudentList[i] = studentList[i];
            }
            studentList[foundLocation] = Student();
            for(int i = foundLocation+1; i < studentCount; i++)
            {
                tempStudentList[i-1] = studentList[i];
            }
            delete[] studentList;
            studentList = tempStudentList;
            cout << "Student " << id << " has been deleted" << endl;
            studentCount--;

        }
        else
        {
            Student* tempStudentList = new Student[studentCount];
            for(int i = 0; i <= foundLocation-1;i++)
            {
                tempStudentList[i] = studentList[i];
            }
            studentList[foundLocation] = Student();
            for(int i = foundLocation+1; i < studentCount; i++)
            {
                tempStudentList[i-1] = studentList[i];
            }
            delete[] studentList;
            studentList = tempStudentList;
            cout << "Student " << id << " has been deleted" << endl;
            studentCount--;

        }

    }
    else
    {
        cout << "Student " << id << " does not exist " << endl;
    }

}
void LibrarySystem::returnBook(const int id)
{
    bool found = false;
    int foundLocation = 0;
    int ownerId = 0;
    int number = 0;
    bool found2 = false;
    int studentIndex = 0;
    int bookIndex = 0;
    for(int i = 0; i < bookCount; i++)
    {
        if(bookList[i].getId() == id)
        {
            found = true;
            foundLocation = i;
            break;
        }
    }
    if(found)
    {
        bool found2 = false;
        if(!bookList[foundLocation].getStatus())
        {
            cout << "Book " << id << " has not been checked out " << endl;
        }
        else
        {
            for(int i = 0; i < studentCount; i++)
            {
                if(bookList[foundLocation].getOwnerId() == studentList[i].getStudentId())
                {
                    for(int j = 0; j < studentList[i].getCheckedOutBookCount(); j++)
                    {
                        if(studentList[i].checkedOutBooksByStudent[j].getId() == id)
                        {
                            bookIndex = j;
                            //break;
                        }
                    }
                    found2 = true;
                    studentIndex = i;
                    break;
                }
            }
            if(found2)
            {
                studentList[studentIndex].checkedOutBooksByStudent[bookIndex] = Book(bookList[foundLocation].getId(),bookList[foundLocation].getName(),bookList[foundLocation].getAuthors(),bookList[foundLocation].getYear());
                bookList[foundLocation].setOwnerId(0);
                bookList[foundLocation].setStatus(false);
                studentList[studentIndex].checkedOutBooksByStudent[bookIndex].setOwnerId(0);
                studentList[studentIndex].checkedOutBooksByStudent[bookIndex].setStatus(0);
                studentList[studentIndex].setCheckedOutBookCount(studentList[studentIndex].getCheckedOutBookCount()-1);
                cout << "Book " << id << " has been returned" << endl;

            }
            else
            {
                cout << "Book " << id << " has not been checked out " << endl;
            }
        }

    }
    else
    {
        cout << "Book " << id << " does not exist" << endl;

    }

}
template<typename T> void printElement(T t, const int& width)
{
    cout << left << setw(width) << t <<  setfill(' ');
}
void LibrarySystem::showAllBooks()
{
    int ownerId = 0;
    printElement("Book ID",width);
    printElement(" Book Name", width);
    printElement(" Authors",width);
    printElement("Year",width);
    printElement("Status",width);
    cout << endl;
    for(int i = 0; i < bookCount; i++)
    {
         printElement(bookList[i].getId(),width);
         printElement(bookList[i].getName(),width);
         printElement(bookList[i].getAuthors(),width);
         printElement(bookList[i].getYear(),width);
         if(bookList[i].getStatus())
         {
             printElement("Checked out by student",width);
             printElement(bookList[i].getOwnerId(),8);
         }
         else
         {
             printElement("Not checked out ",width);

         }
         cout << endl;
    }

}
void LibrarySystem::showBook(const int id)
{
    bool found = false;
    int foundLocation = 0;
    int ownerId = 0;
    for(int i = 0; i < bookCount; i++)
    {
        if(bookList[i].getId() == id)
        {
            found = true;
            foundLocation = i;
            break;

        }
    }
    if(found)
    {
        for(int k = 0; k < studentCount; k++)
         {
             for(int j = 0; j < studentList[k].getCheckedOutBookCount(); j++)
             {
                 if(studentList[k].checkedOutBooksByStudent[j].getId() == id)
                 {
                     ownerId = studentList[k].getStudentId();
                     break;

                 }
             }
         }
        printElement(bookList[foundLocation].getId(),width);
        printElement(bookList[foundLocation].getName(), width);
        printElement(bookList[foundLocation].getAuthors(),width);
        printElement(bookList[foundLocation].getYear(),width);
        if(bookList[foundLocation].getStatus())
        {
            printElement("Checked out by student",width);
            printElement(ownerId,width);
        }
        else
        {
            printElement("Not checked out",width);
        }
        cout << endl;


    }
    else
    {
        cout << "Book " << id << " does not exist" << endl;
    }

}
void LibrarySystem::showStudent(const int id)
{
    bool found = false;
    int foundLocation = 0;
    for(int i = 0; i < studentCount; i++)
    {
        if(studentList[i].getStudentId() == id)
        {
            found = true;
            foundLocation = i;
            break;

        }
    }
    if(!found)
    {

        cout << "Student " << id << " does not exist" << endl;


    }
    else
    {

        cout << "Student id: " << id << "   " << "student name: " << studentList[foundLocation].getName() << endl;
        if(studentList[foundLocation].getCheckedOutBookCount()  != 0)
        {
            cout << "Student " << id << " has the following books: " << endl;
            printElement("Book ID",width);
            printElement(" Book Name", width);
            printElement(" Authors",width);
            printElement("Year",width);
            cout << endl;
            for(int i = 0; i < bookCount; i++)
            {
                if(bookList[i].getOwnerId() == studentList[foundLocation].getStudentId())
                {
                    printElement(bookList[i].getId(),width);
                    printElement(bookList[i].getName(),width);
                    printElement(bookList[i].getAuthors(),width);
                    printElement(bookList[i].getYear(),width);
                    cout << endl;
                }

            }
        }
        else
        {
            cout << "Student " << id << " has no books" << endl;
        }
    }

}


