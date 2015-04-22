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
void account::fileReader(){
//Reading in text file to add accounts to vector
    string line;
    ifstream inFile;
    inFile.open("accounts.txt");
    if(inFile.fail()){
        cerr<<"Error opening file"<<endl;
        exit(1);
    }
    while(inFile >> line){
        int seperator;
        string name;
        string balance;
        int b;
        seperator = line.find_first_of(",");
        name = line.substr(0,seperator);
        balance = line.substr(seperator+1,10000000);
        b = stoi(balance);
        initializeAccounts(name,b);
    }
    inFile.close();
}
void account::fileWriter(){
//Writes contents of vector to text file
    ofstream outFile;
    outFile.open("accounts.txt", std::ofstream::out | std::ofstream::trunc);
    for(int i=0; i<PlayerAccounts.size(); i++){
        outFile <<PlayerAccounts[i].AccountName<<","<<PlayerAccounts[i].AccountBalance<<endl;
    }
    outFile.close();
}

void account::initializeAccounts(string name,int balance){
    AccountInfo temp;
    temp.AccountName = name;
    temp.AccountBalance = balance;
    PlayerAccounts.push_back(temp);
}

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

void account::accountDeposit(){
    string name;
    int delta;
    bool found = false;
    cout<<"Enter the account name to deposit into"<<endl;
    cin>>name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(name==PlayerAccounts[i].AccountName){
            cout<<"Enter the amount to deposit"<<endl;
            cin>>delta;
            PlayerAccounts[i].AccountBalance += delta;
            found = true;
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }
}

void account::accountWithdrawl(){
    string name;
    int delta;
    bool found = false;
    cout<<"Enter the account name to withdraw from"<<endl;
    cin>>name;
    for(int i=0; i<PlayerAccounts.size(); i++){
        if(name==PlayerAccounts[i].AccountName){
            cout<<"Enter the amount to withdraw"<<endl;
            cin>>delta;
            if(delta > PlayerAccounts[i].AccountBalance){
                cout<<"Not enough funds to withdraw, you're bankrupt!"<<endl;
            }
            else{
                PlayerAccounts[i].AccountBalance -= delta;
                found = true;
            }
        }
    }
    if(found == false){
        cout<<"Account name not found"<<endl;
    }
}

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

void account::printAll(){
    for(int i=0; i<PlayerAccounts.size(); i++){
        cout<<"========================="<<endl;
        cout<<"Account Name: "<<PlayerAccounts[i].AccountName<<endl;
        cout<<"Account Balance: "<<PlayerAccounts[i].AccountBalance<<endl;
    }
    cout<<"========================="<<endl;
}
