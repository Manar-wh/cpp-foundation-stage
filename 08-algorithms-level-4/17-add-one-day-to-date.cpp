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

stDate AddIneDayToDate(stDate Date) {
	
	if (IsLastDayInMonth(Date))
	{

		if (IsLastMonthInYear(Date))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

int main() {

	stDate Date1 = ReadFullDate();
	Date1 = AddIneDayToDate(Date1);
	
	cout << "\nDate after adding one day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	system("pause > 0");
	return 0;
}
