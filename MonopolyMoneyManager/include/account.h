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

struct AccountInfo{
    std::string AccountName;
    int AccountBalance;
};

class account
{
    public:
        account();
        virtual ~account();

        vector<AccountInfo> PlayerAccounts;
        void initializeAccounts(string,int);
        void addNewAccount();
        void deleteAccount();
        void accountDeposit();
        void accountWithdrawl();
        void accountTransfer();
        void accountBalance();
        void printAll();
        void fileReader();
        void fileWriter();
    protected:
    private:
};

#endif // ACCOUNT_H
