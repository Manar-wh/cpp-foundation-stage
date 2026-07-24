#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
using namespace std;

class clsUsersListScreen : protected clsScreen
{
	static void _PrintUserRecordLine(clsUser User) {
		cout << setw(8) << left << "" << "| " << "" << left << setw(10) << User.UserName;
		cout << "| " << left << setw(25) << User.FullName();
		cout << "| " << left << setw(15) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(15) << User.Password;
		cout << "| " << left << setw(13) << User.Permissions;
	}


public:
	static void ShowUsersList() {

		vector <clsUser> vUsers;
		vUsers = clsUser::GetUsersList();

		string Title = "\tUsers List Screen";
		string SubTitle = "\t( " + to_string(vUsers.size()) + " ) User(s)";
		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		cout << setw(8) << left << "" << "| " << left << setw(10) << " UserName ";
		cout << "| " << left << setw(25) << " Full Name ";
		cout << "| " << left << setw(15) << " Phone ";
		cout << "| " << left << setw(20) << " Email ";
		cout << "| " << left << setw(15) << " Password ";
		cout << "| " << left << setw(13) << " Permissions ";
		cout << "\n" << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";

		if (vUsers.size() == 0)
		{
			cout << setw(8) << left << "" << "No Users Available In the System!\n";
		}
		else
		{
			for (clsUser& U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << "\n";
			}
			cout << setw(8) << left << "" << "------------------------------------------------------------------------------------------------------------\n";
		}
	}

};

