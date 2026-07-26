#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsGlobal.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
using namespace std;
class clsLoginScreen : protected clsScreen
{
	static bool _Login() {

		 bool FailedLogin = false;
		 short FaildLoginCount = 0;

		 do
		 {
			 if (FailedLogin)
			 {
				 FaildLoginCount++;
				 cout << "\nInvalid Username/Password!\n";
				 cout << "You have " << 3-FaildLoginCount << " Trials to login.\n\n";
			 }

			 if (FaildLoginCount == 3)

			 {
				 cout << "\nYour are Locked after 3 faild trails \n\n";
				 return false;
			 }

			 cout << "Enter Username: ";
			 string Username = clsInputValidate::ReadString();
			 cout << "Enter Password: ";
			 string Password = clsInputValidate::ReadString();

			 CurrentUser = clsUser::Find(Username, Password);

			 FailedLogin = CurrentUser.IsEmpty();

		 } while (FailedLogin);

		system("cls");
		CurrentUser.LoginRegister();
		clsMainScreen::ShowMainMenuScreen();
		return true;
	}
public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("\t    Login Screen");
		return _Login();
	}

};

