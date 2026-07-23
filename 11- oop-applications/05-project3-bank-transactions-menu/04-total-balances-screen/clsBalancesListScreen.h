#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;

class clsBalancesListScreen : protected clsScreen
{
private:
    static void _PrintClientBalanceRecordLine(clsBankClient Client) {
        cout << setw(25) << left << "" << "| " << left << setw(15) << Client.AccountNumber;
        cout << "| " << left << setw(40) << Client.FullName();
        cout << "| " << left << setw(12) << Client.AccountBalance;
    }

public:
    static void ShowBalancesListScreen() {
        vector <clsBankClient> vAllClients = clsBankClient::GetClientsList();

        string Title = "\t  Balances List Screen";
        string SubTitle = "\t    (" + to_string(vAllClients.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(25) << left << "" << "--------------------------------------------------------------------\n";
        cout << setw(25) << left << "" << "| " << left << setw(15) << "Account Number";
        cout << "| " << left << setw(40) << "Client Name";
        cout << "| " << left << setw(12) << "Balance" << endl ;
        cout << setw(25) << left << "" << "--------------------------------------------------------------------\n";

        if (vAllClients.size() == 0)
        {
            cout << "\t\t\t\tNo Clients Available In the System!\n";
        }
        else
        {
            for (clsBankClient& C : vAllClients)
            {
                _PrintClientBalanceRecordLine(C);
                cout << "\n";
            }
        }

        cout << setw(25) << left << "" << "--------------------------------------------------------------------\n";

        double TotalBalances = clsBankClient::GetTotalBalances();
        cout << setw(45) << left << "" << " Total Balance Is: " << TotalBalances << "\n";
        cout << setw(30) << left << "" << " ( " << clsUtil::NumberToText(TotalBalances) << " )\n";
    }
};
