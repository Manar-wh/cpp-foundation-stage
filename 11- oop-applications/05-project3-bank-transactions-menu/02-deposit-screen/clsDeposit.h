#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

class clsDeposit : protected clsScreen
{
	static string _ReadAccountNumber() {
		string AccountNumber = "";
		cout << "Please Enter Account Number? ";
		AccountNumber = clsInputValidate::ReadString();
		return AccountNumber;
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}


public:
	static void ShowDepositScreen() {
		_DrawScreenHeader("\t   Deposit Screen");
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient with " << AccountNumber << " Not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		cout << "\nPlease Enter Deposit Amount:  ";
		double Amount = clsInputValidate::ReadPositiveDblNumber();

		cout << "\nAre you sure you want to perform this transaction? ";

		bool Option = clsInputValidate::confirmation();

		if (Option)
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited successfully.\n";
			cout << "New Balance is : " << Client1.AccountBalance << "\n";

		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}
};

