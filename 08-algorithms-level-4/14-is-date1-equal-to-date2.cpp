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

bool IsDate1EqualDate2(stDate Date1, stDate Date2) {
	return (Date1.Year == Date2.Year) ? 
		((Date1.Month == Date2.Month) ? (Date1.Day == Date2.Day) : false) 
		: false;
}

int main() {
	stDate Date1 = ReadFullDate();
	cout << "\n";
	stDate Date2 = ReadFullDate();

	if (IsDate1EqualDate2(Date1, Date2))
	{
		cout << "\nYes, Date1 is Equal to Date2.";
	}
	else
		cout << "\nNo, Date1 Not Equal to Date2.";

	system("pause > 0");
	return 0;
}
