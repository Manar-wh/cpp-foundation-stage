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

struct stDatePeriod { stDate StartDate; stDate EndDate; stDate DateToCheck; };

stDatePeriod GetPeriodDates() {
	stDatePeriod Period;
	cout << "Enter Start Date: \n\n";
	Period.StartDate = ReadFullDate();
	cout << "\nEnter End Date: \n";
	Period.EndDate = ReadFullDate();
	return Period;
}

bool IsDateWithinPeriod(stDate DateToCheck, stDatePeriod Period) {
	return !(IsDate1BeforeDate2(DateToCheck, Period.StartDate) || IsDate1AfterDate2(DateToCheck,Period.EndDate));
}

int main() {

	stDatePeriod Period;
	cout << "Enter Period: \n";
	Period = GetPeriodDates();

	cout << "Enter Date to check: \n";

	stDate DateToCheck;
	DateToCheck = ReadFullDate();

	if (IsDateWithinPeriod(DateToCheck, Period))
	{
		cout << "\nYes, Date is within Period";
	}
	else
		cout << "\nNo, Date is Not in Period";

	system("pause > 0");
	return 0;
}
