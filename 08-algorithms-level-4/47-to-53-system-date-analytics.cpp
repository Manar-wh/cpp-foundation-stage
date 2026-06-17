#include <iostream>
using namespace std;

#pragma warning(disable : 4996)

struct stDate
{
	short Day;
	short Month;
	short Year;
	short DayOrder;
};

bool IsLeapYear(short Year) {
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

int FindDayOrder(short Year, short Month, short Day) {


	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

int NumberOfDaysFromBeginning(short Day, short Month, short Year) {

	int TotalDays = 0;

	for (int i = 1; i < Month; i++)
	{
		short NumOfDays = NumberOfDaysInMonth(i, Year);
		TotalDays += NumOfDays;
	}

	TotalDays += Day;
	return TotalDays;
}

string FindDayName(short DayOrder) {

	string DaysOfTheWeek[7] = { "Sun","Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
	return DaysOfTheWeek[DayOrder];
}

stDate DayOfWeekOrder(stDate Date) {

	short a = (14 - Date.Month) / 12;
	short y = Date.Year - a;
	short m = Date.Month + (12 * a) - 2;
	Date.DayOrder = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return Date;
}

bool IsEndOfWeek(stDate Date) {

	return (Date.DayOrder == 6);	
}

bool IsWeekEnd(stDate Date) {

	return (Date.DayOrder == 5 || Date.DayOrder == 6);
}

bool IsBusinessDay(stDate Date) {

	return !IsWeekEnd(Date);
}

int DaysUntilTheEndOfWeek(stDate Date) {
	return 6 - Date.DayOrder;
}

int DaysUntilTheEndOfMonth(stDate Date) {
	int DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	 int TheEndOfMonth = DaysInMonth - Date.Day;
	return TheEndOfMonth;
}

int DaysUntilTheEndOfYear(stDate Date) {

	short TotalDaysInYear = IsLeapYear(Date.Year) ? 366 : 365;
	return TotalDaysInYear - NumberOfDaysFromBeginning(Date.Day, Date.Month, Date.Year);
}

void ShowResult(stDate Date) {

	cout << "\nIs it end of week ? ";
	if (IsEndOfWeek(Date)) {
		cout << "Yes, it is end of week";
	}
	else {
		cout << "No, it is Not end of week";
	}


	cout << "\nIs it weekend ? ";
	if (IsWeekEnd(Date)) {
		cout << "Yes, it is weekend";
	}
	else {
		cout << "No, it is Not weekend";
	}


	cout << "\nIs it Business Day ? ";
	if (IsBusinessDay(Date)) {
		cout << "Yes, it is Business Day";
	}
	else {
		cout << "No, it is Not Business Day";
	}

	cout << "\nDays until the end of the week: " << DaysUntilTheEndOfWeek(Date) << " Day(s)";
	cout << "\nDays until the end of the month: " << DaysUntilTheEndOfMonth(Date) << " Day(s)";
	cout << "\nDays until the end of the  year: " << DaysUntilTheEndOfYear(Date) << " Day(s)";
}

stDate GetSystemDate()
{
	stDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
}

int main() {

	stDate Date;
	Date = GetSystemDate();
	system("cls");
	Date = DayOfWeekOrder(Date);
	cout << "Today is: " << FindDayName(Date.DayOrder) << ", " << Date.Day <<"/" << Date.Month << "/" << Date.Year <<"\n";
	ShowResult(Date);
	system("pause > 0");
	return 0;
}
