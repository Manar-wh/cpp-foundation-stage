#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsTransferLogScreen : protected clsScreen
{

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransLog) {
		cout << setw(8) << left << "" << "| " << "" << left << setw(35) << TransLog.DateTime;
		cout << "| " << left << setw(8) << TransLog.SourceAccNum;
		cout << "| " << left << setw(8) << TransLog.DestinationAccNum;
		cout << "| " << left << setw(10) << TransLog.Amount;
		cout << "| " << left << setw(12) << TransLog.SourceBalance;
		cout << "| " << left << setw(12) << TransLog.DestinationBalance;
		cout << "| " << left << setw(15) << TransLog.Username;
	}

public:
	static void ShowTransferLogScreen() {

		vector <clsBankClient::stTransferLogRecord> vTransferRecord;
		vTransferRecord = clsBankClient::GetTransferLogRecord();

		string SubTitle = "\t       " + to_string(vTransferRecord.size()) + " Record(s)";
		_DrawScreenHeader("\t   Transfer Log Screen", SubTitle);

		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------------------------\n";
		cout << setw(8) << left << "" << "| " << "" << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(15) << "Username";
		cout << "\n";
		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------------------------\n";

		if (vTransferRecord.size() == 0)
		{
			cout << "\t\t\t\tNo Transfers Available In the System!\n";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord& T : vTransferRecord)
			{
				_PrintTransferLogRecordLine(T);
				cout << "\n";
			}
		}	
		cout << setw(8) << left << "" << "--------------------------------------------------------------------------------------------------------------\n";

	}
};

