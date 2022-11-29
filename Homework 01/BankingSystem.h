#ifndef HOMEWORK03_BANKINGSYSTEM_H
#define HOMEWORK03_BANKINGSYSTEM_H
using namespace std;
#include "string"
#include "Customer.h"
#pragma once
class BankingSystem
{
    public :
    BankingSystem () ;
    ~BankingSystem () ;
    void addCustomer ( const int customerId , const string firstName , const
    string lastName ) ;
    void deleteCustomer ( const int customerId ) ;
    int addAccount ( const int customerId , const double amount ) ;
    void deleteAccount ( const int accountId ) ;
    void showAllAccounts () ;
    void showAllCustomers () ;
    void showCustomer ( const int customerId ) ;
    int totalAccounts;
    private:
        struct customerNode
        {
            Customer *customer;
            customerNode *next;
        };
        customerNode *head;
        customerNode *find(int index) const;

};
#endif // HOMEWORK03_BANKINGSYSTEM_H

