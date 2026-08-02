#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include <iomanip>
using namespace std;

class clsCurrenciesListScreen : protected clsScreen
{
	static void _PrintCurrencyRecordLine(clsCurrency Currency) {

		cout << setw(10) << left << "" << "| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(8) << Currency.CurrencyCode();
		cout << "| " << left << setw(40) << Currency.CurrencyName();
		cout << "| " << left << setw(12) << Currency.Rate();

	}

public:
	static void _ShowCurrenciesListScreen() {

		vector <clsCurrency> vCurrencies;
		vCurrencies = clsCurrency::GetCurrenciesList();

		string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency.";
		_DrawScreenHeader("\t    Currencies List", SubTitle);

		cout << setw(10) << left << "" << "--------------------------------------------------------------------------------------------------\n";
		cout << setw(10) << left << "" << "| " << left << setw(30) << " Country ";
		cout << "| " << left << setw(8) << " Code ";
		cout << "| " << left << setw(40) << " Name ";
		cout << "| " << left << setw(12) << " Rate/(1$) " << endl;
		cout << setw(10) << left << "" << "--------------------------------------------------------------------------------------------------\n";

		for (clsCurrency& C : vCurrencies)
		{
			_PrintCurrencyRecordLine(C);
			cout << "\n";
		}
		cout << setw(10) << left << "" << "--------------------------------------------------------------------------------------------------\n";
	}
};

