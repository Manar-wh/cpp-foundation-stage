#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include <iomanip>

void PrintClientRecordBalanceLine(clsBankClient Client) {

	cout << "| "  << left << setw(16) << Client.AccountNumber ;
	cout << "| "  << left << setw(30) << Client.FullName() ;
	cout << "| "  << left << setw(12) << Client.AccountBalance ;
}

void ShowClientsBalancesList() {

	vector <clsBankClient> vAllClients;
	vAllClients = clsBankClient::GetClientsList();

	cout << "\t\t\t\t\tClients List (" << vAllClients.size() << ") Client(s)\n ";
	cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
	cout << "| " << left << setw(16) << " Account Number ";
	cout << "| " << left << setw(30) << " Client Name ";
	cout << "| " << left << setw(12) << " Balance ";
	cout << "\n-----------------------------------------------------------------------------------------------------------------\n";

	double TotalBalances = clsBankClient::GetTotalBalances();


	if (vAllClients.size() == 0)
	{
		cout << "\t\t\t\t\tNo Clients Available in the system. ";
	}
	else
	{
		for (clsBankClient& C : vAllClients)
		{
			PrintClientRecordBalanceLine(C);
			cout << "\n";

		}
	}
	cout << "\n-----------------------------------------------------------------------------------------------------------------\n";
	cout << "\t\t\t\t\tTotal Balances=  " << TotalBalances << endl;
	cout << "\t\t\t\t(" << clsUtil::NumberToText(TotalBalances) << ")" << endl;
}

int main()
{
	ShowClientsBalancesList();
}
