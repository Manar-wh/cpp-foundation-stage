#include <iostream>
#include <ctime>
using namespace std;

#pragma warning(disable : 4996)

struct stDate {
	short Day;
	short Month;
	short Year;
};

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

stDate ReadFullDate() {
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

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

short DayOfWeekOrder(short Day, short Month, short Year) {
	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short DayOfWeekOrder(stDate Date) {
	return DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
}

bool IsEndOfWeek(stDate Date) {
	return (DayOfWeekOrder(Date) == 6);
}

bool IsWeekEnd(stDate Date) {
	short DayOrder = DayOfWeekOrder(Date);
	return (DayOrder == 5 || DayOrder == 6);
}

bool IsBusinessDay(stDate Date) {
	return !IsWeekEnd(Date);
}

int DaysUntilTheEndOfWeek(stDate Date) {
	return 6 - DayOfWeekOrder(Date);
}

int DaysUntilTheEndOfMonth(stDate Date) {
	int DaysInMonth = NumberOfDaysInMonth(Date.Month, Date.Year);
	return DaysInMonth - Date.Day;
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

stDate GetSystemDate() {
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

	short CurrentDayOrder = DayOfWeekOrder(Date);
	cout << "Today is: " << FindDayName(CurrentDayOrder) << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year << "\n";

	ShowResult(Date);

	system("pause > 0");
	return 0;
}
