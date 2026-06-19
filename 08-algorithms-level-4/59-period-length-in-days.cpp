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

bool IsDate1BeforeDate2(stDate Date1, stDate Date2) {
	return (Date1.Year < Date2.Year) ? true :
		(Date1.Year == Date2.Year) ?
		((Date1.Month < Date2.Month) ? true :
			(Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false) : false;
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
	return (Date1.Year == Date2.Year) ?
		((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false)
		: false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2) {
	return (!IsDate1BeforeDate2(Date1, Date2)) && (!IsDate1EqualDate2(Date1, Date2));
}

struct stDatePeriod { stDate StartDate; stDate EndDate; };

stDatePeriod GetPeriodDates() {
	stDatePeriod Period;
	cout << "Enter Start Date: \n\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date: \n";
	Period.EndDate = ReadFullDate();
	return Period;
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

int HowManyDaysBetweenTwoDates(stDate Date1, stDate Date2, bool IncludeEndDay = false) {
	int Days = 0;
	while (IsDate1BeforeDate2(Date1, Date2))
	{
		Date1 = AddOneDayToDate(Date1);
		Days++;
	}
	return (IncludeEndDay) ? ++Days : Days;
}

int PeriodLengthInDays(stDatePeriod Period, bool IncludeEndDate = false) {

	return HowManyDaysBetweenTwoDates(Period.StartDate, Period.EndDate, IncludeEndDate);
}

int main() {

	stDatePeriod Period1;
	stDatePeriod Period2;
	cout << "Enter Period 1: \n";
	Period1 = GetPeriodDates();

	cout << "\nPeriod Length: " << PeriodLengthInDays(Period1);
	cout << "\nPeriod Length (Including End Day): " << PeriodLengthInDays(Period1, true);

	system("pause > 0");
	return 0;
}
