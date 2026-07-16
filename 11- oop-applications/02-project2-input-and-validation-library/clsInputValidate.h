#pragma once
#include <iostream>
using namespace std;
#include "clsDate.h"
#include <limits>

class clsInputValidate
{
public:

	static bool IsNumberBetween(int NumberToCheck, int from, int to) {
		return (NumberToCheck >= from && NumberToCheck <= to);
	}
	static bool IsNumberBetween(double NumberToCheck, double from, double to) {
		return (NumberToCheck >= from && NumberToCheck <= to);
	}
	static bool IsNumberBetween(float NumberToCheck, float from, float to) {
		return (NumberToCheck >= from && NumberToCheck <= to);
	}

	static bool IsDateBetween(clsDate D1, clsDate D2, clsDate D3) {
		
		if (clsDate::IsDate1AfterDate2(D2, D3))
		{
			clsDate::SwapDates(D2, D3);
		}

		if (clsDate::IsDate1BeforeDate2(D1, D2))
		{
			return false;
		}
		
		return (clsDate::IsDate1AfterDate2(D1, D2) || clsDate::IsDate1EqualDate2(D1, D2))
			&& (clsDate::IsDate1BeforeDate2(D1, D3) || clsDate::IsDate1EqualDate2(D1, D3));
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		int x = 0;
		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}	
		return x;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		double x = 0;
		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return x;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Invalid Number, Enter again\n") {
		
		int Number = ReadIntNumber();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMessage << endl;
			Number = ReadIntNumber();
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Invalid Number, Enter again\n") {

		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMessage << endl;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
};

