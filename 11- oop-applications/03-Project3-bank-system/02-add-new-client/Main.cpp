#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client) {
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

void AddNewClient() {
	string AccountNumber = "";
	cout << "Please Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while ((clsBankClient::IsClientExist(AccountNumber)))
	{
		cout << "Acc. Number Already Exsist, Enter Anothe Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	cout << "\n\nAdd New Client Info:";
	cout << "\n____________________\n";

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResult SaveResult;

	SaveResult = NewClient.Save();

	switch (SaveResult)
	{
	case clsBankClient::svFailedEmptyObject:
		cout << "\nError account was not saved because it's Empty";
		break;

	case clsBankClient::svSucceeded:
		cout << "\nAccount Addeded Successfully :-)\n";
		NewClient.Print();
	break;

	case clsBankClient::svFailedAccountNumberExist:
		cout << "\nError account was not saved because account number is used!\n";
		break;
	default:
		break;
	}
}

int main()
{
	AddNewClient();
}
