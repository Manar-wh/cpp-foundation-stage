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

short ReadDay() {
	short Day;
	cout << "Please enter The Day ? ";
	cin >> Day;
	return Day;
}

struct stDate {
	short Day;
	short Month;
	short Year;
};

stDate ReadFullDate() {
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

short IsLeapYear(short Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDaysInMonth(short Month, short Year) {
	if (Month < 1 || Month > 12)
	{
		return 0;
	}
	short arrDaysInMonth[12] = { 31 , 28, 31,30, 31 , 30 , 31 , 31, 30, 31 , 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (arrDaysInMonth[Month - 1]);
}

bool IsValidDate(stDate Date) {
	short NumOfDaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	return (Date.Day > 0 && Date.Day <= NumOfDaysInMonth) &&
		(Date.Month > 0 && Date.Month <= 12);
}

int main() {

	stDate Date;
	Date = ReadFullDate();
	
	if (IsValidDate(Date))
	{
		cout << "\nYes, it is a valid Date";
	}
	else
		cout << "\nNo, it is Not a valid Date";

	system("pause > 0");
	return 0;
}
