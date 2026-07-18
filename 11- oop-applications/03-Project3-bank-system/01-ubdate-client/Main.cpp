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

void UbdateClient() {
	string AccountNumber = "";
	cout << "Please Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!(clsBankClient::IsClientExsist(AccountNumber)))
	{
		cout << "Invalid Acc. Number, Enter Anothe Number: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\n\nUpdate Client Info:";
	cout << "\n____________________\n";
	ReadClientInfo(Client1);

	clsBankClient::enSaveResult SaveResult;
	SaveResult = Client1.Save();
	switch (SaveResult)
	{
	case clsBankClient::svSucceeded:
		cout << "\nAccount Updated Successfully :-)\n";
		Client1.Print();

		break;
	case clsBankClient::svFailedEmptyObject:
		cout << "\nError account was not saved because it's Empty";
		break;
	}
}

int main()
{
	UbdateClient();
}
