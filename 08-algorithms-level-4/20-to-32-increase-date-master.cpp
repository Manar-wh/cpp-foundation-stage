#include <iostream>
#include <ctime>
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

stDate IncreaseDateByXDays(stDate Date, int XDays) {
	for (int i = 0; i < XDays; i++)
	{
		Date = AddOneDayToDate(Date);
	}
	return Date;
}

stDate IncreaseDateByOneWeek(stDate Date) {
	return IncreaseDateByXDays(Date, 7);
}

stDate IncreaseDateByXWeek(stDate Date, int XWeek) {

	return IncreaseDateByXDays(Date, XWeek * 7);
}

stDate IncreaseDateByOneMonth(stDate Date) {

	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate IncreaseDateByXMonth(stDate Date, int XMonth) {
	for (int i = 0; i < XMonth; i++)
	{
		Date = IncreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate IncreaseDateByOneYear(stDate Date) {

	return IncreaseDateByXMonth(Date, 12);
}

stDate IncreaseDateByXYear(stDate Date, int XYear) {

	for (int i = 0; i < XYear; i++)
	{
		Date = IncreaseDateByOneYear(Date);
	}
	return Date;
}

stDate IncreaseDateByXYearFaster(stDate Date, int XYear) {

	Date.Year += XYear;
	Date.Day = (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) ? 28 : Date.Day;
	return Date;
}

stDate IncreaseDateByOneDecade(stDate Date) {
	return IncreaseDateByXYear(Date, 10);
}

stDate IncreaseDateByXDecade(stDate Date, int XDecade) {
	return IncreaseDateByXYear(Date, 10 * XDecade);
}

stDate IncreaseDateByXDecadeFaster(stDate Date, int XDecade) {
	Date.Year += (XDecade * 10);
	Date.Day = (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) ? 28 : Date.Day;
	return Date;
}

stDate IncreaseDateByOneCentury(stDate Date) {
	return IncreaseDateByXYearFaster(Date, 100);
}

stDate IncreaseDateByOneMillennium(stDate Date) {
	return IncreaseDateByXYearFaster(Date, 1000);
}

void PrintIncraseDate(stDate Date1) {

	Date1 = AddOneDayToDate(Date1);
	cout << "\n01-Adding One Day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDays(Date1, 10);
	cout << "\n02-Adding 10 Days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneWeek(Date1);
	cout << "\n03-Adding One Week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXWeek(Date1, 10);
	cout << "\n04-Adding 10 Weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMonth(Date1);
	cout << "\n05-Adding One Month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXMonth(Date1, 5);
	cout << "\n06-Adding 5 Months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneYear(Date1);
	cout << "\n07-Adding One Year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYear(Date1, 10);
	cout << "\n08-Adding 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXYearFaster(Date1, 10);
	cout << "\n09-Adding 10 Years (Faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneDecade(Date1);
	cout << "\n10-Adding One Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecade(Date1, 10);
	cout << "\n11-Adding 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByXDecadeFaster(Date1, 10);
	cout << "\n12-Adding 10 Decades (Faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneCentury(Date1);
	cout << "\n13-Adding One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = IncreaseDateByOneMillennium(Date1);
	cout << "\n14-Adding One Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << "\n";
}

int main() {

	stDate Date1 = ReadFullDate();
	PrintIncraseDate(Date1);

	system("pause > 0");
	return 0;
}
