#include "ATM.h"
#include <iostream>

/*
--basics are done rework code to shrink the lines of code
--add pin code 
--polish
*/

//the start of the class
void ATM::StartUp()
{

	//reset the variables
	exit = false;
	choice = 0;

	//keep the user in the class until ready to leave
	while (!exit)
	{

		//allows the user to pick their options
		std::cout << "Saving(1), Checking(2), ShowInformation(3), Deposit or Withdraw(4), AddAccount(5), DeleteAccount(6), Logout(7)\n";

		std::cin >> choice;

		//on choice gives them a pick
		switch (choice)
		{

		case 1:

			PrintSavings();

			break;

		case 2:

			PrintChecking();

			break;

		case 3:

			PrintInfo();

			break;

		case 4:

			DepositWithdraw();

			break;

		case 5:

			AddAccount();

			break;

		case 6:

			DeleteAccount();

			break;

		case 7:

			std::cout << "Are you sure you want to leave No(0)/yes(1)\n";

			std::cin >> exit;

			break;

		}

	}

}

//Combine saving and checking accounts as one
//prints all of the saving account
void ATM::PrintSavings()
{


	std::cout << "==========SAVING============\n";

	//gets the size of the list and if its not zero it will prints out the information otherwise let the user know their is no account
	if (savingAccountList.size() != 0) {

		for (int i = 0; i < savingAccountList.size(); i++) {

			std::cout << savingAccountList[i].accountName << '\t' << (i + 1) << '\n';

		}

	}
	else {

		std::cout << "No SavingAccounts\n";

	}

	std::cout << "============================\n";

}

//prints all checking accounts
void ATM::PrintChecking()
{

	std::cout << "==========CHECKING============\n";

	//gets the size of the list and if its not zero it will prints out the information otherwise let the user know their is no account
	if (checkingAccountList.size() != 0) {

		for (int i = 0; i < checkingAccountList.size(); i++) {

			std::cout << checkingAccountList[i].accountName << '\t' << (i + 1) << '\n';

		}

	}
	else {

		std::cout << "No CheckingAccounts\n";

	}

	std::cout << "==============================\n";

}

//adds struct saving acounts into the struct array 
void ATM::AddAccount()
{

	//reset the variables
	choice = 0;
	leave = false;

	//Will keep running until true
	while (!leave)
	{

		//gives the user the choice on what to add
		std::cout << "What Account Would you like to add Saving(1), Checking(2), Exit(3)\n";

		std::cin >> choice;

		switch (choice)
		{
		
			//user presses 1 they add one and this code gets the name and amount and adds it to the savinglist
			case 1:

				std::cout << "Enter Account Name\n";

				std::cin >> savingAccount.accountName;

				std::cout << "Enter Amount\n";

				std::cin >> savingAccount.amount;

				std::cout << "==========SAVING============\n";

				std::cout << savingAccount.accountName << '\t' << savingAccount.amount << '\n';

				std::cout << "============================\n";

				savingAccountList.push_back(savingAccount);

				break;

			//user presses 2 they add one and this code gets the name and amount and adds it to the Checkinglist
			case 2:

				std::cout << "Enter Account Name\n";

				std::cin >> checkingAcconts.accountName;

				std::cout << "Enter Amount\n";

				std::cin >> checkingAcconts.amount;

				std::cout << "==========CHECKING============\n";

				std::cout << checkingAcconts.accountName << '\t' << checkingAcconts.amount << '\n';

				std::cout << "==============================\n";

				checkingAccountList.push_back(checkingAcconts);

				break;

			case 3:

				leave = true;

				break;

		}

	}

}

void ATM::DeleteAccount()
{

	//reset the variables
	choice = 0;
	location = 0;
	leave = false;

	//Will keep running until true
	while (!leave)
	{

		//gives the user the choice on what to delete
		std::cout << "What Account Would you like to Delete Saving(1), Checking(2), Exit(3)\n";

		std::cin >> choice;

		switch (choice)
		{

			//user presses 1 they add one and this code gets the name and amount and adds it to the savinglist
			case 1:

				PrintSavings();
	
				std::cout << "Which account would you like to delete from location\n";

				std::cin >> location;

				savingAccountList.erase(savingAccountList.begin() + (location - 1));

				std::cout << "account deleted\n";

				PrintSavings();

				break;

			//user presses 2 they add one and this code gets the name and amount and adds it to the Checkinglist
			case 2:

				PrintChecking();

				std::cout << "Which account would you like to delete from location\n";

				std::cin >> location;

				checkingAccountList.erase(checkingAccountList.begin() + (location - 1));

				std::cout << "account deleted\n";

				PrintChecking();
	
				break;

			case 3:

				leave = true;

				break;

		}

	}

}

void ATM::PrintInfo() {

	//reset the variables
	choice = 0;
	location = 0;
	leave = false;

	while (!leave)
	{

		//askes them what account they would like to see
		std::cout << "What information would you like to see Saving(1), Checking(2), Exit(3)\n";

		std::cin >> choice;

		//they choose either saving or checking giving them the option to select the index number which shows them the account information
		switch (choice)
		{
		
			case 1:

				PrintSavings();

				std::cout << "which saving account did you want to print its information\n";

				std::cin >> location;

				std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

				break;

			case 2:

				PrintSavings();

				std::cout << "which saving account did you want to print its information\n";

				std::cin >> location;

				std::cout << checkingAccountList[location - 1].accountName << "\t" << checkingAccountList[location - 1].amount << '\n';

				break;

			case 3:

				leave = true;

				break;

		}

	}

}

void ATM::DepositWithdraw() {

	//reset the variables
	choice = 0;
	location = 0;
	leave = false;

	while (!leave)
	{

		std::cout << "Which account would you like to diposit/withdraw Saving(1), Checking(2), Exit(3)\n";

		std::cin >> choice;

		//lets the user pick between depositing or withdrawing for both account types
		switch (choice)
		{

			case 1:

				std::cout << "would you like to deposit(1) or withdraw(2)\n";

				std::cin >> choice;

				//ask if they are depositing or withdrawing allow them to change the valuew of the ammount in the account
				switch (choice)
				{
				
					case 1:

						amount = 0;

						PrintSavings();

						std::cout << "which saving account did you want to Deposit Money\n";

						std::cin >> location;

						std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

						std::cout << "Enter the amount to deposit\n";

						std::cin >> amount;

						savingAccountList[location - 1].amount = amount + savingAccountList[location - 1].amount;

						std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

						break;

					case 2:

						amount = 0;

						PrintSavings();

						std::cout << "which saving account did you want to Withdraw money\n";

						std::cin >> location;

						std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

						std::cout << "Enter Amount to withdraw\n";

						std::cin >> amount;

						if (amount > savingAccountList[location - 1].amount) {

							std::cout << "amount greater then in account\n";

						}
						else {

							savingAccountList[location - 1].amount = savingAccountList[location - 1].amount - amount;

						}

						std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

						break;

				}

				break;

			case 2:

				std::cout << "would you like to deposit(1) or withdraw(2)\n";

				std::cin >> choice;

				switch (choice)
				{

					//ask if they are depositing or withdrawing allow them to change the valuew of the ammount in the account
					case 1:

						amount = 0;
	
						PrintSavings();

						std::cout << "which saving account did you want to Deposit Money\n";

						std::cin >> location;

						std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

						std::cout << "Enter the amount to deposit\n";

						std::cin >> amount;

						savingAccountList[location - 1].amount = amount + savingAccountList[location - 1].amount;

						std::cout << savingAccountList[location - 1].accountName << "\t" << savingAccountList[location - 1].amount << '\n';

						break;

					case 2:

						amount = 0;

						PrintChecking();

						std::cout << "which saving account did you want to Withdraw money\n";

						std::cin >> location;

						std::cout << checkingAccountList[location - 1].accountName << "\t" << checkingAccountList[location - 1].amount << '\n';

						std::cout << "Enter Amount to withdraw\n";

						std::cin >> amount;

						if (amount > checkingAccountList[location - 1].amount) {

							std::cout << "amount greater then in account\n";

						}
						else {

							checkingAccountList[location - 1].amount = checkingAccountList[location - 1].amount - amount;

						}

						std::cout << checkingAccountList[location - 1].accountName << "\t" << checkingAccountList[location - 1].amount << '\n';
	
						break;

				}

				break;

			case 3:

				leave = true;

				break;

		}

	}

}
