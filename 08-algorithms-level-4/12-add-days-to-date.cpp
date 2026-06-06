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

short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year) {
	short TotalDays = 0;
	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += NumberOfDaysInMonth(i, Year);
	}
	TotalDays += Day;
	return TotalDays;
}

struct stDate {
	short Day;
	short Month;
	short Year;
};

int HowManyDaysToAdd() {
	int AddingDays;
	cout << "\nHow Many Days To Add? ";
	cin >> AddingDays;
	return AddingDays;
}

stDate ReadFullDate() {
	stDate Date;
	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

stDate AddingDaysToDate(stDate Date, int AddingDays) {
	int RemainingDays = AddingDays + NumberOfDaysFromTheBeginingOfTheYear(Date.Day, Date.Month, Date.Year);
	Date.Month = 1;

	while (true)
	{
		short NumberOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);

		if (RemainingDays > NumberOfDays)
		{
			RemainingDays -= NumberOfDays;
			Date.Month++;

			if (Date.Month > 12)
			{
				Date.Year++;
				Date.Month = 1;
			}
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

int main() {
	stDate Date;

	Date = ReadFullDate();
	int AddingDays = HowManyDaysToAdd();

	Date = AddingDaysToDate(Date, AddingDays);

	cout << "\nDate After Adding [" << AddingDays << "] Days Is: " <<
		Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	system("pause > 0");
	return 0;
}
