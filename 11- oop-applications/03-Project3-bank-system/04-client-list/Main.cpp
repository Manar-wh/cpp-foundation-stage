#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>

void PrintClientRecordLine(clsBankClient Client) {

	cout << "| "  << left << setw(16) << Client.AccountNumber ;
	cout << "| "  << left << setw(30) << Client.FullName() ;
	cout << "| "  << left << setw(15) << Client.Phone ;
	cout << "| "  << left << setw(20) << Client.Email ;
	cout << "| "  << left << setw(12) << Client.PinCode ;
	cout << "| "  << left << setw(10) << Client.AccountBalance ;
}


void ShowClientsList() {
	vector <clsBankClient> vAllClients;
	vAllClients = clsBankClient::GetClientsList();
	cout << "\t\t\t\t\tClients List (" << vAllClients.size() << ") Client(s)\n ";
	cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
	cout << "| " << left << setw(16) << " Account Number ";
	cout << "| " << left << setw(30) << " Client Name ";
	cout << "| " << left << setw(15) << " Phone ";
	cout << "| " << left << setw(20) << " Email ";
	cout << "| " << left << setw(12) << " Pin Code ";
	cout << "| " << left << setw(10) << " Balance ";
	cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

	if (vAllClients.size() == 0)
	{
		cout << "\t\t\t\t\tNo Clients Available in the system. ";
	}
	else
	{
		for (clsBankClient& C : vAllClients)
		{
			PrintClientRecordLine(C);
			cout << "\n";
		}
		cout << "-----------------------------------------------------------------------------------------------------------------\n";
	}
}

int main()
{
	ShowClientsList();
}
