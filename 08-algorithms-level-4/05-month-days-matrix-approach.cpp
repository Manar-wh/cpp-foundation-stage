#include <iostream>
using namespace std;

short ReadYear() {
	short Year;
	cout << "Please enter The Year ? ";
	cin >> Year;
	return Year;
}

short ReadMonth() {
	short Month;
	cout << "Please enter The Month ? ";
	cin >> Month;
	return Month;
}

bool IsLeapYear(short Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth(short Month, short Year) {

	if (Month < 1 || Month > 12)
	{
		return 0;
	}

	if (Month == 2)
	{
		return IsLeapYear(Year) ? 29 : 28;
	}

	short Arr31Days[7] = { 1,3,5,7,8,10,12 };

	for (short i = 1; i <= 7; i++)
	{
		if (Month == Arr31Days[i - 1])
		{
			return 31;
		}
	}
	
	return 30;
}

int NumberOfHours(short Month, short Year) {

	return NumberOfDaysInMonth(Month, Year) * 24;
}

int NumberOfMins(short Month, short Year) {

	return NumberOfHours(Month, Year) * 60;
}

long NumberOfsecond(short Month, short Year) {

	return (long)NumberOfMins(Month, Year) * 60;
}


int main() {

	short Year = ReadYear();

	short Month = ReadMonth();

	cout << "\nNumber of Days in Month [" << Month << "] is " << NumberOfDaysInMonth(Month, Year);
	cout << "\nNumber of Hours in Month [" << Month << "] is " << NumberOfHours(Month, Year);
	cout << "\nNumber of Minutes in Month [" << Month << "] is " << NumberOfMins(Month, Year);
	cout << "\nNumber of Seconds in Month [" << Month << "] is " << NumberOfsecond(Month, Year);

	system("pause > 0");
	return 0;

}
