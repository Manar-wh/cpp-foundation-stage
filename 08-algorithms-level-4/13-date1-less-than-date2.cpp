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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
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

bool IsDate1BeforeDate2(stDate Date1 , stDate Date2) {

	return (Date1.Year < Date2.Year) ? true :
		(Date1.Year == Date2.Year) ? 
		((Date1.Month < Date2.Month) ? true :
		(Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day): false) : false;
}

int main() {

	stDate Date1 = ReadFullDate();
	cout << "\n";
	stDate Date2 = ReadFullDate();

	if (IsDate1BeforeDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 less than Date2.";
	}
	else
		cout << "\nNo, Date1 Not less than Date2.";

	system("pause > 0");
	return 0;
}
