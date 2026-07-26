#pragma once
#include <iostream>
#include "clsGlobal.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  " << Title;
		if (SubTitle != "")
		{
			cout << "\n\t\t\t\t\t  " << SubTitle;
		}
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName;
		cout << "\n\t\t\t\t\tDate: " << clsDate::DateToString(clsDate()) << "\n";


	}

	static bool _CheckAccessRights(clsUser::enPermissions Permissions) {

		if (!CurrentUser.CheckAccessPermission(Permissions))
		{
			cout << "\t\t\t\t\t-----------------------------------";
			cout << "\n\t\t\t\t\tAccess Denied! Contact your Admin.";
			cout << "\n\t\t\t\t\t-----------------------------------\n";
			return false;
		}
		return true;
	}
};


