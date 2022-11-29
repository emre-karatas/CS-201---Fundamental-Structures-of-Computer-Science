#include <iostream>
#include "Book.h"

Book::Book()
{
    this->id = 0;
    this->name = "";
    this->authors = "";
    this->year = 0;
    this->status = false;
    this->ownerId = 0;

}
Book::Book(int id, std::string name, std::string authors, int year)
{
    this -> id = id;
    this->name = name;
    this->authors = authors;
    this->year = year;
    this->status = false;
    this->ownerId = 0;
}
int Book::getId()
{
    return this->id;
}
std::string Book::getName()
{
    return this->name;
}
std::string Book::getAuthors()
{
    return this->authors;
}
int Book::getYear()
{
    return this->year;
}
void Book::setStatus(bool status)
{
    this->status = status;
}
bool Book::getStatus()
{
    return this->status;
}
void Book::operator=(const Book& right)
{
    this->id = right.id;
    this->name = right.name;
    this->authors = right.authors;
    this->year = right.year;
    this->status = right.status;
    this->ownerId = right.ownerId;
}
void Book::setOwnerId(int ownerId)
{
    this->ownerId = ownerId;
}
int Book::getOwnerId()
{
    return this->ownerId;
}
