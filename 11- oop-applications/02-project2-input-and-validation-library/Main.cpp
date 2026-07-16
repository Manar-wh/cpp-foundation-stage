#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsInputValidate.h"
#include "clsDate.h"
int main()
{
	cout << clsInputValidate::IsNumberBetween(500, 1, 1000) << endl;
	cout << clsInputValidate::IsNumberBetween(5.9, 1.0, 5.0) << endl;
	
	//Note: The comparison will be performed using today's date (17/07/2026).
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 7, 2026), clsDate(1, 7, 2027)) << endl;
	cout << clsInputValidate::IsDateBetween(clsDate(), clsDate(1, 7, 2027), clsDate(1, 7, 2026)) << endl;

	cout << "\nPlease enter a number: " << endl;
	int x = clsInputValidate::ReadIntNumber("Invalid Number, Enter again: ");
	cout <<"x = " << x << endl;

	cout << "\nPlease enter a double number: " << endl;

	double a = clsInputValidate::ReadDblNumber("Invalid Number, Enter again: ");
	cout << "a = " << a << endl;

	cout << "\nPlease enter a number between 50 to 100: ";
	int y = clsInputValidate::ReadIntNumberBetween(50, 100, "Number is not with in range, please enter another number: ");
	cout << "y = " << y << endl;

	cout << "\nPlease enter a double number between 10.5 to 30.90: ";
	double d = clsInputValidate::ReadDblNumberBetween(10.5, 30.90, "Number is not with in range, please enter another number: ");
	cout << "d = " << d << endl;

	cout << endl << clsInputValidate::IsValidDate(clsDate(31, 12, 2026));
}
