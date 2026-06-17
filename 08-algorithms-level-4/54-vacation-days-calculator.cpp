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
	short arrDaysInMonth[12] = { 31 , 28, 31, 30, 31 , 30 , 31 , 31, 30, 31 , 30, 31 };
	return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : (arrDaysInMonth[Month - 1]);
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

string FindDayName(short DayOrder) {

	string DaysOfTheWeek[7] = { "Sun","Mon", "Tues", "Wed", "Thurs", "Fri", "Sat" };
	return DaysOfTheWeek[DayOrder];
}

void VacationFrom(stDate Date) {
	int DayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	cout << "\nVacation From " << FindDayName(DayOrder) << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}

void VacationTo(stDate Date) {
	int DayOrder = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
	cout << "\nVacation To " << FindDayName(DayOrder) << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year;
}

bool IsWeekEnd(stDate Date) {
	short DayOrder = DayOfWeekOrder(Date);
	return (DayOrder == 5 || DayOrder == 6);
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

short CalculateVacationDays(stDate Date1, stDate Date2) {

	short Counter = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		if (!IsWeekEnd(Date1))
		{
			Counter++;
		}
		Date1 = AddOneDayToDate(Date1);

	}
	return Counter;
}

int main() {
	cout << "Vacation Starts: \n";
	stDate Date1 = ReadFullDate();
	cout << "\nVacation Ends: \n";
	stDate Date2 = ReadFullDate();
	VacationFrom(Date1);
	VacationTo(Date2);
	cout << "\nActual Vacation Days is: " << CalculateVacationDays(Date1, Date2);

	system("pause > 0");
	return 0;
}
