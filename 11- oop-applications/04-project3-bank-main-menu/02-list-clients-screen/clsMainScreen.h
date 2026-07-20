#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsClientListScreen.h"

class clsMainScreen: protected clsScreen
{
	enum enMainMenue{ ShowClientListOp = 1, AddNewClientOp = 2, DeleteClientOp = 3, UpdateClientOp = 4,
		FindClientOp = 5, TransactionsOp = 6, ManageUsersOp = 7, LogoutOp = 8 };

	static short _ReadMainMenuOption() {
		cout << setw(37) << left << "" << "Choose what you want [1 to 8]: ";
		short Option = clsInputValidate::ReadShortNumberBetween(1, 8);
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

		case clsMainScreen::LogoutOp:
			system("cls");
			_ShowEndScreen();
			_GoBackToMainMenu();
			break;

		default:
			break;
		}
	}

	static void _GoBackToMainMenu() {
		system("pause");
		system("cls");
		ShowMainMenuScreen();
	}

	static void _ShowClientsListScreen() {
		clsClientListScreen::ShowClientsList();
	}

	static void _ShowAddNewClientScreen() {
		cout << "\t\t\t--- Add New Client Screen Will Be Here Soon ---\n";
	}

	static void _ShowDeleteClientScreen() {
		cout << "\t\t\t--- Delete Client Screen Will Be Here Soon ---\n";
	}

	static void _ShowUpdateClientScreen() {
		cout << "\t\t\t--- Update Client Screen Will Be Here Soon ---\n";
	}

	static void _ShowFindClientScreen() {
		cout << "\t\t\t--- Find Client Screen Will Be Here Soon ---\n";
	}

	static void _ShowTransactionsScreen() {
		cout << "\t\t\t--- Transactions Screen Will Be Here Soon ---\n";
	}

	static void _ShowManageUsersScreen() {
		cout << "\t\t\t--- Manage Users Screen Will Be Here Soon ---\n";
	}

	static void _ShowEndScreen() {
		cout << "\t\t\t--- End Screen Will Be Here Soon ---\n";
	}

public:
	static void ShowMainMenuScreen() {

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
		cout << setw(37) << left << "" <<"\t[8] Logout\n";
		cout << setw(37) << left << "" <<"==============================================\n";
		_performeMainMenuoptions((enMainMenue)_ReadMainMenuOption());
	}
};

