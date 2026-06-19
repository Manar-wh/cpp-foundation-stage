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

bool IsOverlapPeriods(stDatePeriod Period1, stDatePeriod Period2) {

	return !(IsDate1BeforeDate2(Period1.EndDate, Period2.StartDate) || IsDate1AfterDate2(Period1.StartDate, Period2.EndDate));
}

int main() {

	stDatePeriod Period1;
	stDatePeriod Period2;
	cout << "Enter Period 1: \n";
	Period1 = GetPeriodDates();
	cout << "\n";
	cout << "Enter Period 2: \n";
	Period2 = GetPeriodDates();

	if (IsOverlapPeriods(Period1, Period2))
	{
		cout << "\nYes, Periods Overlap";
	}
	else
		cout << "\nNo, Periods Not Overlap";

	system("pause > 0");
	return 0;
}
