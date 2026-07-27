#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsUser.h"
#include <iomanip>
#include "clsDate.h"
using namespace std;

class clsLoginRegister : protected clsScreen
{

	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord User) {
		cout << setw(8) << left << "" << "| " << "" << left << setw(35) << User.DateTime ;
		cout << "| " << left << setw(25) << User.UserName;
		cout << "| " << left << setw(15) << User.Password;
		cout << "| " << left << setw(20) << User.Permissions;
	}

public:

	static void ShowLoginRegisterList() {

		vector <clsUser::stLoginRegisterRecord> vRegisterRecords;
		vRegisterRecords = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List";
		string SubTitle = "\t( " + to_string(vRegisterRecords.size()) + " ) User(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		cout << setw(8) << left << "" << "| " << left << setw(35) << " Date/Time ";
		cout << "| " << left << setw(25) << "  UserName ";
		cout << "| " << left << setw(15) << " Password ";
		cout << "| " << left << setw(20) << " Permissions ";
		cout << "\n" << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		if (vRegisterRecords.size() == 0)
		{
			cout << setw(8) << left << "" << "No Users Available In the System!\n";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord& C : vRegisterRecords)
			{
				_PrintLoginRegisterRecordLine(C);
				cout << "\n";
			}
			cout << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		}
	}
};

