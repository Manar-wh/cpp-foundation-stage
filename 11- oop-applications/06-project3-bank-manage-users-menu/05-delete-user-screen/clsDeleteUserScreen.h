#pragma once
#include <iostream>
using namespace std;
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
{

	static void _PrintUser(clsUser User)
	{
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
	static void ShowDeleteUserScreen() {
		_DrawScreenHeader("\tDelete User Screen");
		string AccountNumber = "";
		cout << "Please Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();

		while (!(clsUser::IsUserExist(AccountNumber)))
		{
			cout << "Acc. Number not Exsist, Enter Another Account Number: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(AccountNumber);

		_PrintUser(User1);

		char Answer;
		cout << "\nAre you sure you want to delete this User? Y/N:  ";
		Answer = clsInputValidate::confirmation();
		if (Answer)
		{

			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfully :-)\n";
				_PrintUser(User1);
			}
			else
			{
				cout << "\nError: User was not deleted.\n";
			}
		}
		else
		{
			cout << "\nOperation Was Cancelled.\n";
		}
	}

};


