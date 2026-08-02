#pragma once
#include <iostream>
#include"clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
#include "clsUser.h"
using namespace std;
class clsFindCurrencyScreen :protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency) {

		cout << "\nCurrency Card\n";
		cout << "----------------------------------\n";
		cout << "\nCountry    :" << Currency.Country() ;
		cout << "\nCode       :" << Currency.CurrencyCode() ;
		cout << "\nName       :" << Currency.CurrencyName() ;
		cout << "\nRate(1$) = :" << Currency.Rate();
		cout << "\n----------------------------------\n";

	}

	static void _ShowResult(clsCurrency Currency) {

		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency NOT Found :(\n";
		}
	}

public:

	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("\tFind Currency Screen");
		cout << "\nFind By: [1] Code or [2] Country? ";

		short Answer = clsInputValidate::ReadIntNumberBetween(1, 2);
		if (Answer == 1)
		{
			cout << "\nPlease Enter CurrencyCode: ";
			string CurrencyCode= clsInputValidate::ReadString();
			clsCurrency Cur = clsCurrency::FindByCode(CurrencyCode);
			_ShowResult(Cur);
		}
		else
		{
			cout << "\nPlease Enter Currency Country Name : ";
			string Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResult(Currency);
		}
	}
};

