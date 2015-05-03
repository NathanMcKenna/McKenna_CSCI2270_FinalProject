#include "account.h"
#include <iostream>
#include <vector>
#include<iostream>
#include<fstream>
#include<cctype>
#include <string>
#include<iomanip>
#include <sstream>

account::account()
{
    //ctor
}

account::~account()
{
    //dtor
}
/*
Function Description:
This function reads line by line by line through accounts.txt
and separates the name from the balance. The function then uses
the account name and account balance as inputs to the
initializeAccounts function which then adds the account name and
balance pair to the vector of accounts.

Example:
account ac;
ac.fileReader()

Pre-Conditions: Infile is open, no function arguments
Post-Conditions: Accounts from txt file written into function vector
*/
void account::fileReader(){
//Reading in text file to add accounts to vector
    string line;
    ifstream inFile;
    inFile.open("accounts.txt");
    //exits if the file can't be opened (Won't work without it)
    if(inFile.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    //While there are still lines in the file
    while(inFile >> line){
        //Separates the parts of the file line
        int seperator;
        string name;
        string balance;
        int b;
        seperator = line.find_first_of(",");
        name = line.substr(0,seperator);
        balance = line.substr(seperator+1,10000000);
        b = stoi(balance);
        //Calls the function to add the name:balance to the vector of accounts
        initializeAccounts(name,b);
    }
    inFile.close();
}

/*
Function Description:
This function takes the vector of altered accounts and then overwrites
the account names and balances to the accounts.txt file
The next time the program is ran the vector of accounts will reflect
the changes made in prior instances of the program.

Example:
account ac;
ac.fileWriter

Pre-Conditions: accounts exist in the vector of accounts
Post-Conditions: program exit, account from program written to text file
*/
void account::fileWriter(){
//Writes contents of vector to text file
    ofstream outFile;
    outFile.open("accounts.txt", std::ofstream::out | std::ofstream::trunc);
    //Writes the information for each account to accounts.txt
    for(int i=0; i<PlayerAccounts.size(); i++){
        outFile <<PlayerAccounts[i].AccountName<<","<<PlayerAccounts[i].AccountBalance<<endl;
    }
    outFile.close();
}
/*
Function Description:
This function adds the accounts from the accounts.txt file to the vector of accounts
It is called in the above function fileReader.

Example:
initializeAccounts(string,int)

Pre-Conditions: txt file has been read in
Post-Conditions: All accounts from txt file are written into the vector of accounts

*/
void account::initializeAccounts(string name,int balance){
    AccountInfo temp;
    temp.AccountName = name;
    temp.AccountBalance = balance;
    PlayerAccounts.push_back(temp);
}
/*
Function Description:
This function adds a new account to the vector of accounts that
is not present already (ie. no duplicate accounts)

Example:
account ac;
ac.addNewAccount();

Pre-Conditions: accounts have been read in from txt, the account name isn't already taken by another account
Post-Conditions: the new account is added to the vector of accounts (Base monopoly balance is $1,500)
*/
void account::addNewAccount(){
    AccountInfo temp;
    string name;
    bool duplicate = false;
    cout<<"Enter the name for the account "<<endl;
    cin >> name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(PlayerAccounts[i].AccountName == name){
            cout<<"That name is already taken"<<endl;
            duplicate = true;
        }
    }
    if(duplicate != true){
        temp.AccountName = name;
        temp.AccountBalance = 1500;
        PlayerAccounts.push_back(temp);
    }
}
/*
Function Description:
This function deletes an account present in the vector of accounts
This change will be reflected in the accounts.txt at the end
of the program

Example:
account ac;
ac.deleteAccount();

Pre-Conditions: the account to be deleted actually exists in the vector of accounts
Post-Conditions: the account is deleted from the vector of accounts
*/
void account::deleteAccount(){
    bool found = false;
    string name;
    cout<<"Enter the name of the account to be deleted"<<endl;
    cin >> name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(PlayerAccounts[i].AccountName == name){
            PlayerAccounts.erase (PlayerAccounts.begin()+(i));
            found = true;
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }
}

/*
Function Description:
This functions adds delta to the balance of an account in the accounts vector. It does this by searching the vector of
accounts for the given account name

Example:
account ac;
ac.accountDeposit;

Pre-Conditions: the txt of accounts has been read into the vector of accounts, the account exists in the vector
Post-Conditions: delta is added to the account that is chosen

*/
void account::accountDeposit(){
    string name;
    int delta,alpha;
    bool found = false;
    cout<<"Enter the account name to deposit into"<<endl;
    cin>>name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(name==PlayerAccounts[i].AccountName){
            cout << "Enter the 4-digit pin" << endl;
            cin>>alpha;
            if(alpha==PlayerAccounts[i].pin){
                cout<<"Enter the amount to deposit"<<endl;
                cin>>delta;
                PlayerAccounts[i].AccountBalance += delta;
                found = true;
            } else {
                cout<< "incorrect pin" << endl;
                found = true;
            }
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }
}
/*
Function Description:
This functions makes a withdrawl from one of the accounts
 in the vector of accounts

 Example:
 account ac;
 ac.accountWithdrawl();

 Pre-Conditions: the accounts have been read in, the account exists in the vector
 Post-Conditions: delta is subtracted from the account balance selected
*/
void account::accountWithdrawl(){
    string name;
    int delta,alpha;
    bool found = false;
    cout<<"Enter the account name to withdraw from"<<endl;
    cin>>name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(name==PlayerAccounts[i].AccountName){
            cout << "Enter the 4-digit pin" << endl;
            cin>>alpha;
            if(alpha==PlayerAccounts[i].pin){
            cout<<"Enter the amount to withdraw"<<endl;
            cin>>delta;
            if(delta > PlayerAccounts[i].AccountBalance){
                cout<<"Not enough funds to withdraw, you're bankrupt!"<<endl;
            }
            else{
                PlayerAccounts[i].AccountBalance -= delta;
                found = true;
            }
        } else {
            cout << "Wrong pin" << endl;
        }
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }
}

/*
Function Description:
This function transfers delta funds between two accounts in the accounts vector.
It does this by searching the vector for the deposit account and withdrawl
account. It then subtracts delta from the withdrawl account balance
and then adds delta to the deposit account balance.

Example:
account ac;
ac.accountTransfer();

Pre-Conditions: accounts have been read in, both accounts exist in vector
Post-Conditions: money transfered from the withdrawl account to the deposit account
*/
void account::accountTransfer(){
    string depositName, withdrawlName;
    int delta;
    bool found1 = false;
    bool found2 = false;
    AccountInfo *deposit;
    AccountInfo *withdrawl;
    cout<<"Enter the account name to withdraw from"<<endl;
    cin>>withdrawlName;
    cout<<"Enter the account name to deposit to"<<endl;
    cin>>depositName;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(PlayerAccounts[i].AccountName == withdrawlName){
            withdrawl = &PlayerAccounts[i];
            found1 = true;
        }
        if(PlayerAccounts[i].AccountName == depositName){
            deposit = &PlayerAccounts[i];
            found2 = true;
        }
    }
    if(found1 == true && found2 == true){
        cout<<"Enter the amount to transfer"<<endl;
        cin >> delta;
        withdrawl->AccountBalance-=delta;
        deposit->AccountBalance+=delta;

    }


}
/*
Function Description:
This function reports the balance of the selected account
by searching the vector of accounts for the account name

Example:
account ac;
ac.accountBalance();

Pre-Conditions: the accounts have been read in, the account exists in the vector
Post-Conditions: the balance is reported to the user
*/
void account::accountBalance(){
    string name;
    bool found = false;
    cout<<"Enter the account name to view balance"<<endl;
    cin>>name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(name==PlayerAccounts[i].AccountName){
            cout<<"Account Balance: "<<PlayerAccounts[i].AccountBalance<<endl;
            found = true;
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }

}
/*
Function Description:
This function cycles through all the accounts in the account vector
and then prints their respective account name and balances pairs

Example:
account ac;
ac.printAll();

Pre-Conditions: accounts have been read in
Post-Conditions: all account names and balance pairs are reported to the user
*/
void account::printAll(){
    for(int i=0; i<PlayerAccounts.size(); i++){
        cout<<"========================="<<endl;
        cout<<"Account Name: "<<PlayerAccounts[i].AccountName<<endl;
        cout<<"Account Balance: "<<PlayerAccounts[i].AccountBalance<<endl;
    }
    cout<<"========================="<<endl;
}

void account::assignpin(){
    string name;
    int delta;
    bool found = false;
    cout<<"Enter the account name to assign a pin"<<endl;
    cin>>name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(name==PlayerAccounts[i].AccountName){
            cout<<"Enter the 4 digit pin"<<endl;
            cin>>delta;
            PlayerAccounts[i].pin = delta;
            found = true;
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }
}
