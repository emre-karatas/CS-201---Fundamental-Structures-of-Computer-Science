#include <iostream>
#include "Book.h"
#pragma once
class Student
{
public:
    int getStudentId();
    std::string getName();
    Student();
    Student(const int studentId, const std::string name);
    Student& operator=(const Student& right);
    int getCheckedOutBookCount();
    Book* checkedOutBooksByStudent;
    void setCheckedOutBookCount(int number);


private:
    int studentId;
    std::string name;
    int checkedOutBookCount;

};
