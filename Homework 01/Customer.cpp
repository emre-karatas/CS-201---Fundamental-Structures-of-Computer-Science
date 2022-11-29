#include "Customer.h"

Customer::Customer(const int customerId,const string firstName, const string lastName)
{
    this->customerId = customerId;
    this->firstName = firstName;
    this->lastName = lastName;
    accountCount = 0;
    headAccount = NULL;

}

Customer::~Customer()
{
    AccountNode *cur = headAccount;
    while(cur!=NULL)
    {
        AccountNode *temp = cur;
        cur = cur->next;
        delete temp;
        headAccount = cur;
    }

}

void Customer::operator=(const Customer &customer)
{
    this->customerId = customer.getId();
    this->firstName = customer.getFirstName();
    this->lastName = customer.getLastName();
    this->accountCount = customer.accountCount;
    if(customer.headAccount == NULL)
    {
        headAccount = NULL;
    }
    else
    {
        headAccount = new AccountNode;
        headAccount->amount = customer.headAccount->amount;
        headAccount->accountId = customer.headAccount->accountId;
        AccountNode *ptr = headAccount;
         for (AccountNode *origPtr = customer.headAccount->next;origPtr != NULL; origPtr= origPtr->next)
        {
            ptr->next = new AccountNode;
            ptr = ptr->next;
            ptr->amount = origPtr->amount;
            ptr->accountId = origPtr->accountId;
        }
        ptr->next = NULL;
    }
}

int Customer::getId() const
{
    return customerId;
}
string Customer::getFirstName() const
{
    return firstName;
}
string Customer::getLastName() const
{
    return lastName;
}
void Customer::deleteCustomerAccount(const int accountId)
{
    AccountNode *currentAccount = headAccount;
    AccountNode *previous = NULL;
    while(currentAccount!=NULL)
    {
        if(currentAccount->accountId == accountId)
        {
            AccountNode *temp = currentAccount;
            if(currentAccount == headAccount)
            {
                currentAccount= currentAccount->next;
                headAccount = currentAccount;
                delete temp;
                accountCount--;
                return;
            }
            else
            {
                previous->next = currentAccount->next;
                currentAccount=currentAccount->next;
                delete temp;
                accountCount--;
                return;

            }
        }
        previous = currentAccount;
        currentAccount = currentAccount->next;
    }
}
void Customer::showAccounts()
{
    AccountNode *currentAccount = headAccount;
    while(currentAccount!=NULL)
    {
        cout << currentAccount->accountId << "\t\t\t";
        cout << currentAccount->ownerId << "\t\t\t";
        cout << currentAccount->ownerFirstName << " " << currentAccount->ownerLastName << "\t\t\t";
        cout << currentAccount->amount << endl;
        currentAccount=currentAccount->next;
    }
}
int Customer::getAccountCount() const
{
    return accountCount;
}
void Customer::setAccountCount(int number)
{
    accountCount = number;
}
