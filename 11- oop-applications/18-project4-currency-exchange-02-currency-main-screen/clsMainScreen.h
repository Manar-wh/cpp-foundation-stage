#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsGlobal.h"
#include "clsLoginRegister.h"
#include "clsShowCurrencyExchangeScreen.h"

class clsMainScreen: protected clsScreen
{
	enum enMainMenue{ ShowClientListOp = 1, AddNewClientOp = 2, DeleteClientOp = 3, UpdateClientOp = 4,
		FindClientOp = 5, TransactionsOp = 6, ManageUsersOp = 7, LoginRegisterOp = 8, CurrencyExchangeOp = 9 ,LogoutOp = 10 };

	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose what you want [1 to 10]: ";
		short Option = clsInputValidate::ReadShortNumberBetween(1, 10);
		return Option;
	}

	void static _performeMainMenuoptions(enMainMenue Option) {

		switch (Option)
		{
		case clsMainScreen::ShowClientListOp:
			system("cls");
			_ShowClientsListScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::AddNewClientOp:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::DeleteClientOp:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::UpdateClientOp:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::FindClientOp:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::TransactionsOp:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenu();
			break;

		case clsMainScreen::ManageUsersOp:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenu();
			break;

			case clsMainScreen::LoginRegisterOp:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenu();
			break;

			case clsMainScreen::CurrencyExchangeOp:
				system("cls");
				_ShowCurrencyExchangeScreen();
				_GoBackToMainMenu();
				break;

		case clsMainScreen::LogoutOp:
			system("cls");
			_Logout();
			break;

		default:
			break;
		}
	}

	static void _Logout() {
		CurrentUser = clsUser::Find("", "");
	}

	static void _ShowClientsListScreen() {
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen() {
		clsAddNewClientScreen::AddNewClient();

	}

	static void _ShowDeleteClientScreen() {
		clsDeleteClientScreen::DeleteClient();
	}

	static void _ShowUpdateClientScreen() {
		clsUpdateClientScreen::UpdateClient();
	}

	static void _ShowFindClientScreen() {

		clsFindClientScreen::ShowFindClientScreen();
	}

	static void _ShowTransactionsScreen() {
		clsTransactionsScreen::ShowTransactionsMenuScreen();
	}

	static void _ShowManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersMenu();
	}


	static void _ShowLoginRegisterScreen() {

		clsLoginRegister::ShowLoginRegisterList();
	}

	static void _ShowCurrencyExchangeScreen() {

		clsShowCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
	}

protected:

	static void _GoBackToMainMenu() {
		system("pause");
		system("cls");
		ShowMainMenuScreen();
	}


public:
	static void ShowMainMenuScreen() {

		_DrawScreenHeader("\t Main Menu Screen");

		cout << setw(37) << left << "" <<"==============================================\n";
		cout << setw(37) << left << "" <<"\t\t\tMain Menu\n";
		cout << setw(37) << left << "" <<"==============================================\n";
		cout << setw(37) << left << "" <<"\t[1] Show Clients List\n";
		cout << setw(37) << left << "" <<"\t[2] Add New Client \n";
		cout << setw(37) << left << "" <<"\t[3] Delete Client \n";
		cout << setw(37) << left << "" <<"\t[4] Update Client Info\n";
		cout << setw(37) << left << "" <<"\t[5] Find Client\n";
		cout << setw(37) << left << "" <<"\t[6] Transactions\n";
		cout << setw(37) << left << "" <<"\t[7] Manage Users\n";
		cout << setw(37) << left << "" << "\t[8] Login Register\n";
		cout << setw(37) << left << "" <<"\t[9] Currency Exchange\n";
		cout << setw(37) << left << "" << "\t[10] Logout\n";
		cout << setw(37) << left << "" <<"==============================================\n";

		_performeMainMenuoptions((enMainMenue)_ReadMainMenuOption());
	}

	static void GoBackToMainMenu() {
		_GoBackToMainMenu();
	}
};

