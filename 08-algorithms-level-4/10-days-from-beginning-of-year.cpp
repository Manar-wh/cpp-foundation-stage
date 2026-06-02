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

int main() {

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	cout << "\nNumber Of Days From The Beginning Of The Year: " << NumberOfDaysFromBeginning(Day, Month, Year);

	system("pause > 0");
	return 0;
}
