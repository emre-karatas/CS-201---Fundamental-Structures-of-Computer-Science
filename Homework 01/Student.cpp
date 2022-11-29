#include <iostream>
#include "Student.h"
Student::Student()
{
    this->studentId = 0;
    this->name="";
    this->checkedOutBooksByStudent = new Book[20];
    this->checkedOutBookCount = 0;


}
Student::Student(const int studentId, const std::string name)
{
    this->studentId = studentId;
    this->name = name;
    this->checkedOutBooksByStudent = new Book[20];
    this->checkedOutBookCount = 0;
}
int Student::getStudentId()
{
    return this->studentId;
}
std::string Student::getName()
{
    return this->name;
}
Student& Student::operator=(const Student& right)
{
    this->studentId = right.studentId;
    this->name = right.name;
    this->checkedOutBooksByStudent = right.checkedOutBooksByStudent;
    this->checkedOutBookCount = right.checkedOutBookCount;

}
int Student::getCheckedOutBookCount()
{
    return this->checkedOutBookCount;
}
void Student::setCheckedOutBookCount(int number)
{
    this->checkedOutBookCount = number;
}
