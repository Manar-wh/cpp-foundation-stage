#pragma once
#include <iostream>
using namespace std;
#include "clsDate.h"
#include <limits>
class clsInputValidate
{
public:

	template <typename T>
	static bool IsNumberBetween(T NumberToCheck, T from, T to) {
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

	template <typename T>
	static T ReadNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		T x = 0;
		while (!(cin >> x))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage << endl;
		}
		return x;
	}

	template <typename T>
	static T ReadPositiveNumber(string ErrorMessage = "Invalid Number, Enter again\n") {
		T x = 0;
		while (!(cin >> x) || x <= 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return x;
	}

	template <typename T>
	static T ReadNumberBetween(T From, T To, string ErrorMessage = "Invalid Number, Enter again\n") {

		T Number = ReadNumber <T> ();

		while (!IsNumberBetween(Number, From, To)) {

			cout << ErrorMessage << endl;
			Number = ReadNumber <T>();
		}
		return Number;
	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static string ReadString() {
		string S;
		getline(cin >> ws, S);
		return S;
	}

	static bool confirmation() {
		char answer = ' ';
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			return true;
		}

		return false;

	}
};

