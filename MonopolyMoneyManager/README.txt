README for MonopolyMoneyManager

___Phase 1___

*Project Summary*

My program is a virtual banking system to be used alongside the board game Monopoly.
The program functions by generating "bank" accounts for all players of the game that 
then stores their account balances. Within the function the user has many options like adding funds, 
subtracting funds, and transferring funds between accounts. Usually monopoly games take quite a long time, 
therefore my program stores the bank account information in a seperate file outside of the cpp files.
When the program is first ran, it reads the bank account information from the text file and writes them into
a vector inside the program. Once the user has finished making changes to the accounts (ie. the players want to take a break)
the account info is overwritten back into the text file. If the program is started again, it will now initialize the
accounts to reflect all the changes that were made to the accounts in the program. This preserves the balances in the accounts
between instances of running my program.

*How to Run*

To run the program, the main file needs to be linked to the account.h header file and the account.cpp class file.
Without the header and class files the program will not run. The program also needs to be in the same
directory as accounts.txt file, as the program reads and writes information to this text file.

*Dependencies*

The program has no additional dependencies beyond the additional c++ libraries added at the top of the 3
program files.

*System Requirements*

The program only needs a c++ compiler to run.

*Group Members*

Nathan McKenna (I worked by myself)

*Contributors*

Nathan McKenna
google searches

*Open Issues/Bugs*

There are no known bugs that I know of. The program could benefit from some enhancements however, as the
program has no method to protect the users' account balance. The program could benefit from an additional feature
that required the user account's pin number to make changes to the balance, protecting one player's account
from having their balanced changed or transfered to another account. Although this would add extra security,
the Monopoly game should be enjoyed in good fun and the players shouldn't have to worry about their friends cheating,
so I think this feature is not direly important.

