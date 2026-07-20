#pragma once
#include <iostream>
using namespace std;
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"

class clsUpdateClientScreen : protected clsScreen
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

	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "First Name: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "Last Name : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "Email     : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "Phone     : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "Pin Code  : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "Acc.Balance  : ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
public :
	static void UpdateClient() {
		_DrawScreenHeader("\tUpdate Client Info");
		string AccountNumber = "";
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "Invalid Acc. Number, Enter Another Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\n\nUpdate Client Info:";
		cout << "\n____________________\n";
		_ReadClientInfo(Client1);

		clsBankClient::enSaveResult SaveResult;
		SaveResult = Client1.Save();

		switch (SaveResult)
		{
		case clsBankClient::svSucceeded:
			cout << "\nAccount Updated Successfully :-)\n";
			_PrintClient(Client1);
			break;

		case clsBankClient::svFailedEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;
		}
	}
};

