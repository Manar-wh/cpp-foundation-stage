#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
	static void _Login() {

		 bool FailedLogin = false;

		 do
		 {
			 if (FailedLogin)
			 {
				 cout << "\nInvalid Username/Password!\n\n";
			 }

			 cout << "Enter Username: ";
			 string Username = clsInputValidate::ReadString();
			 cout << "Enter Password: ";
			 string Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(Username, Password);

			 FailedLogin = CurrentUser.IsEmpty();

		 } while (FailedLogin);
		 system("cls");
		 clsMainScreen::ShowMainMenuScreen();
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t    Login Screen");
		_Login();
	}

};

