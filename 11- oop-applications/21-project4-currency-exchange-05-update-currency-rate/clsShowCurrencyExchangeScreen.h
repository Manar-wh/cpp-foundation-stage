#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"

using namespace std;
class clsShowCurrencyExchangeScreen : protected clsScreen
{

	enum enCurrencyExchange { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenu = 5 };

	static short _ReadChoice() {
		cout << setw(37) << left << "" << "Choose What do you want to do? [1 to 5]:  ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 5);
		return choice;
	}

	static void _performCurrencyExchangMenu(enCurrencyExchange Choice) {

		switch (Choice)
		{
		case clsShowCurrencyExchangeScreen::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsShowCurrencyExchangeScreen::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsShowCurrencyExchangeScreen::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsShowCurrencyExchangeScreen::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExchangeScreen();
			break;
		case clsShowCurrencyExchangeScreen::eMainMenu:
			break;
		default:
			break;
		}
	}

	static void _ShowListCurrenciesScreen() {
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrencyScreen() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen(); 
	}

	static void _ShowUpdateRateScreen() {
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen() {
		cout << "\n\t\t[ Currency Calculator Screen Will Be Added Later... ]\n\n";
	}

	static void _GoBackToCurrencyExchangeScreen() {
		system("pause");
		system("cls");
		ShowCurrencyExchangeScreen();
	}


public:

	static void ShowCurrencyExchangeScreen() {
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Screen");

		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "==============================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate \n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu\n";
		cout << setw(37) << left << "" << "==============================================\n";
		_performCurrencyExchangMenu((enCurrencyExchange)_ReadChoice());
	}
};

