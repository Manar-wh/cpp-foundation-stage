#pragma once
#include <iostream>
using namespace std;
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsFindClientScreen : protected clsScreen
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
	static void ShowFindClientScreen() {
		_DrawScreenHeader("\tFind Client Screen");
		cout << "\nPlease Enter Account Number: ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient not found enter another account number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}
		_PrintClient(Client1);
	}
};

