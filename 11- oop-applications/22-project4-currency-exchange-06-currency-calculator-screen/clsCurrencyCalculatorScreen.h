#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{

	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "----------------------------------\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "----------------------------------\n";
	}

	static float _ReadAmount() {
		cout << "\nPlease Enter Amount to Exchange: ";
		float Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Message) {

		cout << Message ;
		string CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalculationsResults(clsCurrency CurrencyFrom, clsCurrency CurrencyTo , float Amount) {

		cout << "\nConvert From: \n";
		_PrintCurrencyCard(CurrencyFrom);
		float Resulte = CurrencyFrom.CurrencyCalculator(CurrencyTo, Amount);
		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << Resulte << " " << CurrencyTo.CurrencyCode() << "\n";

	}

public:
	static void _ShowCurrencyCalculatorScreen() {
		
		char Countinue = 'Y';

		do
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code:  ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code:  ");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(CurrencyFrom, CurrencyTo, Amount);

			cout << "\nDo you want to do another calculation? [Y or N]:  ";
			cin >> Countinue;

		} while (Countinue == 'Y' || Countinue == 'y');
	}
};

