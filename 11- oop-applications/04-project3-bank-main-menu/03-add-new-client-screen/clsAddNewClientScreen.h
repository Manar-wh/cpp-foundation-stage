#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsAddNewClientScreen : protected clsScreen
{

	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nFirst Name: ";
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

	static void AddNewClient() {

		clsScreen::_DrawScreenHeader("\tAdd New Clients Screen");

		string AccountNumber = "";
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while ((clsBankClient::IsClientExist(AccountNumber)))
		{
			cout << "Acc. Number Already Exsist, Enter Another Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		cout << "\n\nAdd New Client Info:";
		cout << "\n____________________\n";

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResult SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::svFailedEmptyObject:
			cout << "\nError account was not saved because it's Empty";
			break;

		case clsBankClient::svSucceeded:
			cout << "\nAccount Addeded Successfully :-)\n";
			_PrintClient(NewClient);
			break;

		case clsBankClient::svFailedAccountNumberExist:
			cout << "\nError account was not saved because account number is used!\n";
			break;
		default:
			break;
		}
	}

};

