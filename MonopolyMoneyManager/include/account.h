#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <vector>
#include<iostream>
#include<fstream>
#include<cctype>
#include <string>
#include<iomanip>
#include <sstream>
#include <json/json.h>
using namespace std;

//Struct that defines information for each account
struct AccountInfo{
    std::string AccountName;
    int AccountBalance;
};

class account
{
    public:
        //Ctor/Dtor
        account();
        virtual ~account();

        //Initialize vector of accounts and information
        vector<AccountInfo> PlayerAccounts;
        //Function to initialize accounts that were read from txt file
        void initializeAccounts(string,int);
        //Function to add a new account (Not an account on the txt file)
        void addNewAccount();
        //Function to delete an account from the accounts vector
        void deleteAccount();
        //Adds delta to the balance of an account in the accounts vector
        void accountDeposit();
        //Removes delta from the balance of an account in the accounts vector
        void accountWithdrawl();
        //Transfers funds between 2 accounts in the accounts vector
        void accountTransfer();
        //Prints the balance of a selected account
        void accountBalance();
        //Prints the account names and balances of all accounts in the vector
        void printAll();
        //Reads in the account information from the text file to be added to accounts vector
        void fileReader();
        //Writes the account information from the vector to the accounts file
        void fileWriter();
    protected:
    private:
};

#endif // ACCOUNT_H
