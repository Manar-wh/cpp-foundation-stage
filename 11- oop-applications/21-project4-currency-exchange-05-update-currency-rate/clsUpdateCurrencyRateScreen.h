#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\nCurrency Card\n";
		cout << "----------------------------------\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "----------------------------------\n";
	}

	static float _ReadNewRate() {
		cout << "\nUpdate Currency Rate";
		cout << "\n----------------------------\n";
		cout << "Enter New Rate: ";
		float Rate = clsInputValidate::ReadFloatNumber();
		return Rate;
	}

	static void _UpdateRate(clsCurrency& Currency) {
		_PrintCurrencyCard(Currency);

		char Answer;
		cout << "\nAre you sure you want to Update the rate of this Currency? [Y/N]: ";
		cin >> Answer;

		if (toupper(Answer) == 'Y')
		{
			float Rate = _ReadNewRate();
			Currency.UpdateRate(Rate);
			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrencyCard(Currency);
		}
	}

public:
	static void ShowUpdateCurrencyScreen() {
		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "\nPlease Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_UpdateRate(Currency);
	}
};
