#include "account.h"
#include <iostream>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <json/json.h>
using namespace std;

int main()
{
    //Initialize variables, print intro menu
	string choice;
	cout<<"======================"<<endl;
	cout<<"Monopoly Money Manager"<<endl;
	cout<<"======================\n"<<endl;
	//Initialize instance of class
	account ac;
	//Calls class function to read in data from accounts.txt file
    ac.fileReader();

    //Loop continually until the user selects quit
    while(true)
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
		getline(cin, choice);

        //Conditionals for the different menu choices
		if(atoi(choice.c_str()) == 1){
            ac.addNewAccount();
		}
        else if(atoi(choice.c_str()) == 2){
            ac.accountDeposit();
        }
        else if(atoi(choice.c_str()) == 3){
            ac.accountWithdrawl();
		}
		else if(atoi(choice.c_str()) == 4){
            ac.accountTransfer();
		}
		else if(atoi(choice.c_str()) == 5){
            ac.accountBalance();
		}
		else if(atoi(choice.c_str()) == 6){
            ac.printAll();
		}
		else if(atoi(choice.c_str()) == 7){
            ac.deleteAccount();
        }
        else if(atoi(choice.c_str()) == 8){
            cout<<"Goodbye!"<<endl;
            break;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
		//cin.ignore();
		//cin.get();
    }
    //Calls class function to write account vector to the text file
    ac.fileWriter();

	return 0;
}

