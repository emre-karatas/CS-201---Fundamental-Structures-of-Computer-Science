#include <iostream>
using namespace std;
#include <string>
#pragma once
class Customer
{
public:
    Customer(const int customerId, const string firstName, const string lastName);
    ~Customer();
    Customer(const Customer &customer);
    void operator=(const Customer &customer);
    int getId() const;
    void deleteCustomerAccount(const int accountId);
    void setAccountCount(int number);
    void showAccounts();
    string getFirstName() const;
    string getLastName() const;
    int getAccountCount() const;
    struct AccountNode
    {
        double amount;
        int accountId;
        int ownerId;
        string ownerFirstName;
        string ownerLastName;
        AccountNode *next;
    };
    AccountNode *headAccount;


private:
    int customerId;
    string firstName;
    string lastName;
    int accountCount;
};
