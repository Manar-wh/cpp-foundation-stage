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

	int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
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
