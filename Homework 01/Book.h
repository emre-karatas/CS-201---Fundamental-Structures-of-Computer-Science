#include <iostream>
using namespace std;
#pragma once
class Book
{
public:
    Book();
    Book(int id,std::string name, std::string authors,int year);
    int getId();
    int getYear();
    std::string getName();
    std::string getAuthors();
    void operator=(const Book& right);
    void setStatus(bool status);
    bool getStatus();
    void setOwnerId(int id);
    int getOwnerId();



private:
    int id;
    int year;
    std::string name;
    std::string authors;
    bool status;
    int ownerId;
};
