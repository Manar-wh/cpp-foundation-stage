#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransferScreen : protected clsScreen
{
	static void _PrintClientCard(clsBankClient Client) {
		cout << "\nClient Card :";
		cout << "\n------------------------";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n------------------------\n";

	}

	static string _ReadAccountNumber(string Message) {

		cout << Message << "\n";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Not Found, enter another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}

	static double _ReadAmountNumber(clsBankClient SourceClient) {
		cout << "\nEnter Transfer Amount: ";
		double Amount = clsInputValidate::ReadDblNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
			Amount = clsInputValidate::ReadDblNumber();
		}
		return Amount;
	}


public:

	static void ShowTransferScreen() {

		_DrawScreenHeader("\t   Transfer Screen");
		string AccountNumber = _ReadAccountNumber("\nPlease Enter Account Number to transfer from: ");
		clsBankClient SourceClient = clsBankClient::Find(AccountNumber);
		_PrintClientCard(SourceClient);

		AccountNumber = _ReadAccountNumber("\nPlease Enter Account Number to transfer to: ");
		clsBankClient DestinationClient = clsBankClient::Find(AccountNumber);
		_PrintClientCard(DestinationClient);

		double Amount = _ReadAmountNumber(SourceClient);

		cout << "\nAre you sure you want to perform this operation? y/n? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
			{
				cout << "\nTransfer Failed \n";
			}

		}
		_PrintClientCard(SourceClient);
		_PrintClientCard(DestinationClient);
	}
};

