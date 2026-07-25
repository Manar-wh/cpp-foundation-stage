#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;

class clsFindUserScreen : clsScreen
{
	static void _PrintUser(clsUser User) {
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.FullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}

public:

	static void ShowFindUserScreen() {
		_DrawScreenHeader("\tFind User Screen");
		cout << "\nPlease Enter Username: ";
		string Username = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUser is not found, enter another one: ";
			Username = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(Username);

		if (!User1.IsEmpty())
		{
			cout << "\nUser found:)";
			_PrintUser(User1);
		}
		else
		{
			cout << "\nUser Not found:(";
		}

	}
};

