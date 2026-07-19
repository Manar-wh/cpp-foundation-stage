#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsBankClient.h"
#include "clsInputValidate.h"

void DeleteClient() {
	string AccountNumber = "";
	cout << "Please Enter Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!(clsBankClient::IsClientExist(AccountNumber)))
	{
		cout << "Acc. Number not Exsist, Enter Another Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1= clsBankClient::Find(AccountNumber);

	Client1.Print();

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

int main()
{
	DeleteClient();
}
