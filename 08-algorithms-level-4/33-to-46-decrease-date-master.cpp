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

stDate DecreaseDateByOneDay(stDate Date) {

	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
	}
	else
	{
		Date.Day--;
	}
	return Date;
}

stDate DecreaseDateByXDays(stDate Date, int XDays) {

	for (int i = 0; i < XDays; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}
	return Date;
}

stDate DecreaseDateByOneWeek(stDate Date) {
	return DecreaseDateByXDays(Date, 7);
}

stDate DecreaseDateByXWeek(stDate Date, int XWeek) {

	return DecreaseDateByXDays(Date, XWeek * 7);
}

stDate DecreaseDateByOneMonth(stDate Date) {

	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

stDate DecreaseDateByXMonth(stDate Date, int XMonth) {

	for (int i = 0; i < XMonth; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}

stDate DecreaseDateByOneYear(stDate Date) {
	return DecreaseDateByXMonth(Date, 12);
}

stDate DecreaseDateByXYear(stDate Date,int XYear) {
	for (int i = 0; i < XYear; i++)
	{
		Date = DecreaseDateByOneYear(Date);
	}
	return Date;
}

stDate DecreaseDateByXYearFaster(stDate Date, int XYear) {
	Date.Year -= XYear;
	Date.Day = (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) ? 28 : Date.Day;
	return Date;
}

stDate DecreaseDateByOneDecade(stDate Date) {
	return DecreaseDateByXYear(Date, 10);
}

stDate DecreaseDateByXDecade(stDate Date, int XDecade) {
	for (int i = 0; i < XDecade; i++)
	{
		Date = DecreaseDateByOneDecade(Date);
	}
	return Date;
}

stDate DecreaseDateByXDecadeFaster(stDate Date, int XDecade) {
	Date.Year -= (XDecade * 10);
	Date.Day = (Date.Month == 2 && Date.Day == 29 && !IsLeapYear(Date.Year)) ? 28 : Date.Day;
	return Date;
}

stDate DecreaseDateByOneCentury(stDate Date) {

	return DecreaseDateByXYearFaster(Date, 100);
}

stDate DecreaseDateByOneMillennium(stDate Date) {

	return DecreaseDateByXYearFaster(Date, 1000);
}

void PrintDecreaseDate(stDate Date1) {
	Date1 = DecreaseDateByOneDay(Date1);
	cout << "\n01-Subtracting One Day is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDays(Date1, 10);
	cout << "\n02-Subtracting 10 Days is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneWeek(Date1);
	cout << "\n03-Subtracting One Week is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXWeek(Date1, 10);
	cout << "\n04-Subtracting 10 Weeks is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMonth(Date1);
	cout << "\n05-Subtracting One Month is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXMonth(Date1, 5);
	cout << "\n06-Subtracting 5 Months is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneYear(Date1);
	cout << "\n07-Subtracting One Year is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYear(Date1, 10);
	cout << "\n08-Subtracting 10 Years is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXYearFaster(Date1, 10);
	cout << "\n09-Subtracting 10 Years (Faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneDecade(Date1);
	cout << "\n10-Subtracting One Decade is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecade(Date1, 10);
	cout << "\n11-Subtracting 10 Decades is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByXDecadeFaster(Date1, 10);
	cout << "\n12-Subtracting 10 Decades (Faster) is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneCentury(Date1);
	cout << "\n13-Subtracting One Century is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year;

	Date1 = DecreaseDateByOneMillennium(Date1);
	cout << "\n14-Subtracting One Millennium is: " << Date1.Day << "/" << Date1.Month << "/" << Date1.Year << "\n";
}

int main() {

	stDate Date1 = ReadFullDate();
	PrintDecreaseDate(Date1);

	system("pause > 0");
	return 0;
}
