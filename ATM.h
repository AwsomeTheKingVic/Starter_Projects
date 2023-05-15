#pragma once
#include <string>
#include <vector>

struct SavingsAcconts
{

	//variables
	std::string accountName = "";
	double amount = 0.0;

};

struct CheckingAcconts
{

	//variables
	std::string accountName = "";
	double amount = 0.0;

};

class ATM
{

	//values
	SavingsAcconts savingAccount;
	CheckingAcconts checkingAcconts;
	std::vector<SavingsAcconts> savingAccountList;
	std::vector<CheckingAcconts> checkingAccountList;
	std::string passKey = "";
	int choice = 0, location = 0, amount = 0;
	bool exit = false, leave = false;

public:

	//function
	void StartUp();
	void PrintSavings();
	void PrintChecking();
	void AddAccount();
	void DeleteAccount();

	//functions involving structsinfo
	void PrintInfo();
	void DepositWithdraw();

};

