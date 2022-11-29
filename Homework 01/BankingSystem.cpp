#include "BankingSystem.h"
#include <iostream>
#include <string>
#include "Customer.h"
using namespace std;


BankingSystem::BankingSystem()
{
    head = NULL;
    totalAccounts = 1;

}
BankingSystem::~BankingSystem()
{
    customerNode *current = head;
    customerNode *previous = NULL;
    while(current!=NULL)
    {
        customerNode *temp = current;
        if(current == head)
        {
            current=current->next;
            head = current;
            delete temp->customer;
            delete temp;
            return;

        }
        else
        {
            previous->next = current->next;
            current=current->next;
            delete temp->customer;
            delete temp;
            return;



        }
        previous = current;
        current = current->next;
    }

}

void BankingSystem::addCustomer(const int customerId,const string firstName, const string lastName)
{
    Customer *newCustomer = new Customer(customerId,firstName,lastName);
    if(head == NULL)
    {
        BankingSystem::customerNode *customerNode= new BankingSystem::customerNode;
        customerNode->customer = newCustomer;
        head = customerNode;
        customerNode->next = NULL;
        cout << "Customer " << customerId << " has been added " << endl;
    }
    else
    {
        customerNode *current = head;
        while(current != NULL)
        {
            if(current->customer->getId() == customerId)
            {
                if(current->customer->getFirstName() == firstName && current->customer->getLastName() == lastName)
                {
                    cout << "Customer " << firstName << " " << lastName << " already exists " << endl;
                }
                else
                {
                    cout << "Customer " << customerId << " already exists" << endl;
                }
                delete newCustomer;
                newCustomer = NULL;
                return;
            }
            else
            {
                if(current->customer->getFirstName() == firstName && current->customer->getLastName() == lastName)
                {
                    cout << "Customer " << firstName << " " << lastName << " already exists " << endl;
                }
            }
            current = current->next;
        }
        current = head;
        while(current != NULL)
        {
            if ( current->customer->getLastName() != lastName)
            {
                if( (current->next!= NULL) && (lastName > current->customer->getLastName()) && (current->next->customer->getLastName() > lastName) )
                {
                    customerNode *node = new customerNode;
                    node->customer = newCustomer;
                    node->next = current->next;
                    current->next = node;
                    cout << "Customer " << customerId << " has been added"   << endl;
                    return;
                }
                else if( current->next == NULL && lastName > current->customer->getLastName())
                {
                    customerNode *node = new customerNode;
                    node->customer = newCustomer;
                    current->next = node;
                    node->next = NULL;
                    cout << "Customer " << customerId << " has been added " << endl;
                    return;
                }
                else if(current == head && lastName < current->customer->getLastName())
                {
                    customerNode *node = new customerNode;
                    node->customer = newCustomer;
                    node->next =head;
                    head = node;
                    cout << "Customer " << customerId << " has been added " << endl;
                    return;
                }
            }
            else if(current->customer->getLastName() == lastName)
            {
                if( (current->next!= NULL) && (firstName > current->customer->getFirstName()) && (current->next->customer->getFirstName() > firstName) )
                {
                    customerNode *node = new customerNode;
                    node->customer = newCustomer;
                    node->next = current->next;
                    current->next = node;
                    cout << "Customer " << customerId << " has been added"   << endl;
                    return;
                }
                else if( current->next == NULL && firstName > current->customer->getFirstName())
                {
                    customerNode *node = new customerNode;
                    node->customer = newCustomer;
                    current->next = node;
                    node->next = NULL;
                    cout << "Customer " << customerId << " has been added " << endl;
                    return;
                }
                else if(current == head && firstName < current->customer->getFirstName())
                {
                    customerNode *node = new customerNode;
                    node->customer = newCustomer;
                    node->next =head;
                    head = node;
                    cout << "Customer " << customerId << " has been added " << endl;
                    return;
                }

            }
            current = current->next;
        }

    }

}
void BankingSystem::deleteCustomer(const int customerId)
{
    customerNode *current = head;
    customerNode *previous = NULL;
    while(current != NULL)
    {
        if(current->customer->getId() == customerId)
        {
            customerNode *temp = current;
            Customer::AccountNode *accounts = current->customer->headAccount;
            while(accounts!= NULL)
            {
                current->customer->deleteCustomerAccount(accounts->accountId);
                accounts = accounts->next;

            }
            if(current == head)
            {
                current = current->next;
                head = current;
                delete temp->customer;
                delete temp;
                cout << "Customer " << customerId << " has been deleted " << endl;
                return;

            }
            else
            {
                previous->next = current->next;
                delete temp->customer;
                delete temp;
                cout << "Customer " << customerId << " has been deleted " << endl;
                return;
            }
        }
        previous = current;
        current = current->next;

    }
    cout << "Customer " << customerId << " does not exists" << endl;


}
int BankingSystem::addAccount(const int customerId,const double amount)
{
    customerNode *current = head;
    bool found = false;
    customerNode *foundOwner = NULL;
    while(current != NULL)
    {
        if(current->customer->getId() == customerId )
        {
            found = true;
            foundOwner = current;
            break;
        }
        current = current->next;
    }
    if(!found)
    {
        cout << "Customer " << customerId << " does not exists" << endl;
        return -1;
    }
    else
    {
        Customer::AccountNode *currentAccount = current->customer->headAccount;
        Customer::AccountNode *newAccount = new Customer::AccountNode;
        newAccount->amount = amount;
        newAccount->ownerId = customerId;
        newAccount->ownerFirstName = foundOwner->customer->getFirstName();
        newAccount->ownerLastName = foundOwner->customer->getLastName();
        if(currentAccount == NULL)
        {
            current->customer->headAccount = newAccount;
            newAccount->next = NULL;
            newAccount->accountId = totalAccounts++;
            current->customer->setAccountCount(current->customer->getAccountCount()+1);
            cout << "Account " << newAccount->accountId << " added for customer " << customerId << endl;
            return newAccount->accountId;
        }
        else
        {
            while(currentAccount!=NULL)
            {
                if(currentAccount->next==NULL)
                {
                    currentAccount->next = newAccount;
                    newAccount->next = NULL;
                    newAccount->accountId = totalAccounts++;
                    current->customer->setAccountCount(current->customer->getAccountCount()+1);
                    cout << "Account " << newAccount->accountId << " added for customer " << customerId << endl;
                    return newAccount->accountId;

                }
                else
                {
                    currentAccount=currentAccount->next;
                }
            }
        }

    }

}

void BankingSystem::deleteAccount(const int accountId)
{
    customerNode *current = head;
    bool found = false;
    int number = 0;
    customerNode *foundCustomer = NULL;
    while(current!=NULL)
    {
        for(int i = 0; i < current->customer->getAccountCount(); i++)
        {
            Customer::AccountNode *currentAccount = current->customer->headAccount;
            while(currentAccount!=NULL)
            {
                if(currentAccount->accountId == accountId)
                {
                    found = true;
                    number = accountId;
                    foundCustomer = current;
                    break;
                }
                currentAccount = currentAccount->next;
            }
        }
        current = current->next;
    }
    if(found)
    {
            foundCustomer->customer->deleteCustomerAccount(accountId);
            cout << "Account " << number  << " has been deleted" << endl;

    }
    else
    {
        cout << "Account " << number  << " does not exists" << endl;
    }


}
void BankingSystem::showAllAccounts()
{
    if(totalAccounts == 0)
    {
        cout << "There is no account to show!" << endl;

    }
    else
    {
        customerNode *current = head;
        cout<< "Account id"<< "\t\t";
        cout<< "Customer id" << "\t\t";
        cout << "Customer name " << "\t\t\t";
        cout << "Balance " << endl;
        while(current!=NULL)
        {
            current->customer->showAccounts();
            current = current->next;
        }

    }
}
void BankingSystem::showAllCustomers()
{

    customerNode *current = head;
    if(current== NULL)
    {
        cout<<"There is no customer to show!"<<endl;
    }

    else
    {
        cout<<"Customer id"<< "\t\t";
        cout<<"Customer name"<<endl;
        while(current!=NULL)
        {
            cout<<current->customer->getId()<<"\t\t\t";
            cout<<current->customer->getFirstName()<<" ";
            cout<<current->customer->getLastName()<<endl;
            current = current->next;
        }
    }

}
void BankingSystem::showCustomer(const int customerId)
{
    customerNode *current = head;
    bool found = false;
    while(current!=NULL)
    {
        if(current->customer->getId() == customerId)
        {
            cout << "Customer id: " << customerId << "\t" << "Customer name: " << current->customer->getFirstName() << " " << current->customer->getLastName() << "\t" << "Number of Accounts: " << current->customer->getAccountCount() << endl;
            found = true;
            if(current->customer->getAccountCount() != 0)
            {
                Customer::AccountNode *currentAccount = current->customer->headAccount;
                cout << "Accounts of this customer: " << endl;
                cout << "Account id " << "\t\t" << "Balance " << endl;
                while(currentAccount!=NULL)
                {
                    cout << currentAccount->accountId << "\t\t\t" << currentAccount->amount << endl;
                    currentAccount = currentAccount->next;

                }
            }

        }
        current = current->next;
    }
    if(!found)
    {
        cout << "Customer " << customerId << " does not exists" << endl;
    }

}

