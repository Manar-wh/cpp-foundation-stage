#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
{

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
	static void DeleteClient() {
		_DrawScreenHeader("\tDelete Client Screen");
		string AccountNumber = "";
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "Acc. Number not Exsist, Enter Another Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		_PrintClient(Client1);

		char Answer;
		cout << "\nAre you sure you want to delete this client? Y/N:  ";
		Answer = clsInputValidate::confirmation();
		if (Answer)
		{

			if (Client1.Delete())
			{
				cout << "\nAccount Deleted Successfully :-)\n";
			}
			else
			{
				cout << "\nError: Account was not deleted.\n";
			}
		}
		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}
};
