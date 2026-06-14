#include <iostream>
#include <ctime>
using namespace std;

#pragma warning(disable : 4996)

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
	short arrDaysInMonth[12] = { 31 , 28, 31, 30, 31 , 30 , 31 , 31, 30, 31 , 30, 31 };
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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
	return (Date1.Year < Date2.Year) ? true :
		(Date1.Year == Date2.Year) ?
		((Date1.Month < Date2.Month) ? true :
		(Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false) : false;
}

stDate AddOneDayToDate(stDate Date) {

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

void SwapDates(stDate &Date1, stDate &Date2) {

	stDate TempDates;

	TempDates.Day = Date1.Day;
	TempDates.Month = Date1.Month;
	TempDates.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = TempDates.Day;
	Date2.Month =  TempDates.Month;
	Date2.Year = TempDates.Year;
}

int HowManyDaysBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
	int Days = 0;
	short SawpFlagValue = 1;

	if (!IsDate1BeforeDate2(Date1, Date2))
	{
		SwapDates(Date1, Date2);
		SawpFlagValue = -1;
	}

	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = AddOneDayToDate(Date1);
		Days++;
	}
	return (IncludeEndDay) ? ++Days  * SawpFlagValue : Days * SawpFlagValue;
}

int main() {

	stDate Date1 = ReadFullDate();
	cout << "\n";
	stDate Date2 = ReadFullDate();

	cout << "\nDiffrence is: " << HowManyDaysBetweenTwoDates(Date1, Date2) << " Day(s)\n";
	cout << "\nDiffrence (Including end day) is: " << HowManyDaysBetweenTwoDates(Date1, Date2, true) << " Day(s)\n";

	system("pause > 0");
	return 0;
}
