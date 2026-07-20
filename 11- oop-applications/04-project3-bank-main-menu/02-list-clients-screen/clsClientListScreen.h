#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
class clsClientListScreen : protected clsScreen
{

	static void PrintClientRecordLine(clsBankClient Client) {
		cout << setw(8) << left << "" << "| " << "" << left << setw(16) << Client.AccountNumber;
		cout << "| " << left << setw(25) << Client.FullName();
		cout << "| " << left << setw(15) << Client.Phone;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(12) << Client.PinCode;
		cout << "| " << left << setw(10) << Client.AccountBalance;
	}

public:
	static void ShowClientsList() {

		vector <clsBankClient> vAllClients;
		vAllClients = clsBankClient::GetClientsList();

		string Title = "\tClients List Screen";
		string SubTitle = "\t( " + to_string(vAllClients.size()) + " ) Client(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";	
    cout << setw(8) << left << "" <<"| " << left << setw(16) << " Account Number ";
		cout <<"| " << left << setw(25) << " Client Name ";
		cout <<"| " << left << setw(15) << " Phone ";
		cout <<"| " << left << setw(20) << " Email ";
		cout <<"| " << left << setw(12) << " Pin Code ";
		cout <<"| " << left << setw(10) << " Balance ";
		cout << "\n" << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		if (vAllClients.size() == 0)
		{
			cout << setw(8) << left << "" << "No Clients Available In the System!\n";
		}
		else
		{
			for (clsBankClient& C : vAllClients)
			{
				PrintClientRecordLine(C);
				cout << "\n";
			}
			cout << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		}
	}
};

