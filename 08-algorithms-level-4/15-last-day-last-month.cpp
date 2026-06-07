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

bool IsLastDayInMonth(stDate Date) {
	return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(stDate Date) {
	return (Date.Month == 12);
}

int main() {
	stDate Date1 = ReadFullDate();

	if (IsLastDayInMonth(Date1))
	{
		cout << "\nYes, Day " << Date1.Day << " is the last day in month.";
	}
	else
	{
		cout << "\nNo, Day " << Date1.Day << " is Not the last day in month.";
	}

	if (IsLastMonthInYear(Date1))
	{
		cout << "\nYes, Month " << Date1.Month << " is the last Month in the year.";
	}
	else
	{
		cout << "\nNo, Month " << Date1.Month << " is Not the last Month in the year.";
	}

	system("pause > 0");
	return 0;
}
