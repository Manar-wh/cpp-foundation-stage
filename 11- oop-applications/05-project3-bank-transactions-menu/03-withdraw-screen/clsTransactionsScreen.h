#pragma once
#include <iostream>
using namespace std;
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsDeposit.h"
#include "clsWithdraw.h"

class clsTransactionsScreen : protected clsScreen
{
	enum enTransactions 
	{
		DepositOp = 1, WithdrawOp = 2, TotalBalancesOp = 3, MainMenuOp = 4
	};

	static short _ReadTransactionsOption() {
		cout << "\nPlease Choose What You Want To Do? [1 to 4]:  ";
		short Option = 0;
		Option = clsInputValidate::ReadShortNumberBetween(1, 4);
		return Option;
	}

	static void _performeMainMenuoptions(enTransactions Option) {

		switch (Option)
		{
		case clsTransactionsScreen::DepositOp:
			system("cls");
			_ShowDepositScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::WithdrawOp:
			system("cls");
			_ShowWithdrawScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::TotalBalancesOp:
			system("cls");
			_ShowTotalBalancesScreen();
			_GoBackToTransactionsMenu();
			break;

		case clsTransactionsScreen::MainMenuOp:
			system("cls");
			break;

		default:
			break;
		}
	}

	static void _ShowDepositScreen() {
		clsDeposit::ShowDepositScreen();
	}

	static void _ShowWithdrawScreen() {
		clsWithdraw::ShowWithdrawScreen();
	}

	static void _ShowTotalBalancesScreen() {
		cout << "\n\t\t\t--- Total Balances Screen Will Be Here Soon ---\n";
	}

	static void _GoBackToTransactionsMenu() {
		system("pause");
		system("cls");
		ShowTransactionsMenuScreen();
	}

public:

	static void ShowTransactionsMenuScreen() {

		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menu Screen\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw \n";
		cout << setw(37) << left << "" << "\t[3] Total Balances \n";
		cout << setw(37) << left << "" << "\t[4] Main Menu\n";
		cout << setw(37) << left << "" << "==============================================\n";
		_performeMainMenuoptions((enTransactions)_ReadTransactionsOption());
	}

};

