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

struct stDatePeriod { stDate StartDate; stDate EndDate; };

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
	short arrDaysInMonth[12] = { 31 , 28, 31,30, 31 , 30 , 31 , 31, 30, 31 , 30, 31 };
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

stDatePeriod GetPeriodDates() {
	stDatePeriod Period;
	cout << "Enter Start Date: \n\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date: \n";
	Period.EndDate = ReadFullDate();
	return Period;
}

bool IsOverlapPeriods(stDatePeriod Period1, stDatePeriod Period2) {

	return !(IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate) || IsDate1AfterDate2(Period1.StartDate, Period2.EndDate));
}

bool IsDateWithinPeriod(stDate DateToCheck, stDatePeriod Period) {
	return !(IsDate1BeforeDate2(DateToCheck, Period.StartDate) || IsDate1AfterDate2(DateToCheck, Period.EndDate));
}

int OverlapDaysCounter(stDatePeriod Period1, stDatePeriod Period2) {
	short LengthOfPeriod1 = PeriodLengthInDays(Period1);
	short LengthOfPeriod2 = PeriodLengthInDays(Period2);
	
	int OverlapDays = 0;
	if (!IsOverlapPeriods(Period1, Period2))
	{
		return 0;
	}

	if (LengthOfPeriod1 < LengthOfPeriod2)
	{
		while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate) || IsDate1EqualDate2(Period1.StartDate, Period1.EndDate))
		{
			if (IsDateWithinPeriod(Period1.StartDate, Period2))
			{
				OverlapDays++;
			}
			Period1.StartDate = AddOneDayToDate(Period1.StartDate);
		}
	}
	else
	{
		while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate) || IsDate1EqualDate2(Period2.StartDate, Period2.EndDate))
		{
			if ((IsDateWithinPeriod(Period2.StartDate, Period1)))
			{
				OverlapDays++;
			}
			Period2.StartDate = AddOneDayToDate(Period2.StartDate);
		}
	}

	return OverlapDays;
}

int main() {

	stDatePeriod Period1;
	stDatePeriod Period2;
	cout << "Enter Period 1: \n";
	Period1 = GetPeriodDates();
	cout << "\n";
	cout << "Enter Period 2: \n";
	Period2 = GetPeriodDates();

	int OverlapCounter = OverlapDaysCounter(Period1, Period2);
	cout << "\nOverlap Days Counter is : " << OverlapCounter;
	


	system("pause > 0");
	return 0;
}
