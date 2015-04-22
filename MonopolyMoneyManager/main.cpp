#include "account.h"
#include <iostream>
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

int main()
{
    //Initialize variables, print intro menu
	int choice = 0;
	cout<<"======================"<<endl;
	cout<<"Monopoly Money Manager"<<endl;
	cout<<"======================\n"<<endl;
	account ac;
    ac.fileReader();

    while(choice != '8')
	{
        //Menu of different banking options
		cout<<"\nMain Menu\n";
		cout<<"1). Open New Account\n";
		cout<<"2). Make a Deposit\n";
		cout<<"3). Make a Withdrawal\n";
		cout<<"4). Transfer funds\n";
		cout<<"5). Balance Enquiry\n";
		cout<<"6). List All Account Holders and Balances\n";
		cout<<"7). Close an Account\n";
		cout<<"8). Quit\n";
		cout<<"Select Your Option (1-8) \n";
		cin>>choice;

		if(choice == 1){
            ac.addNewAccount();
		}
        if(choice == 2){
            ac.accountDeposit();
        }
		if(choice == 3){
            ac.accountWithdrawl();
		}
		if(choice == 4){
            ac.accountTransfer();
		}
		if(choice == 5){
            ac.accountBalance();
		}
		if(choice == 6){
            ac.printAll();
		}
		if(choice == 7){
            ac.deleteAccount();
        }
        if(choice == 8){
            cout<<"Goodbye!"<<endl;
            break;
        }
		cin.ignore();
		cin.get();
    }
    ac.fileWriter();

	return 0;
}

