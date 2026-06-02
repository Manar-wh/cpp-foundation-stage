#include <iostream>
using namespace std;

short ReadYear() {
	short Year;
	cout << "Please enter The Year ? ";
	cin >> Year;
	return Year;
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

int FindDayOrder(short Day, short Month, short Year) {

	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string FindDayName(short DayOrder) {

	string DaysOfTheWeek[7] = { "Sun","Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	return DaysOfTheWeek[DayOrder];
}

string FindMonthName(short Month) {

	string NameOfMonths[12] = { "Jan", "Feb", "Mar", "Apr", "May",
		"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	return NameOfMonths[Month - 1];
}

void PrintMonthCalendar(short Month, short Year) {


	printf("\n-----------------%s-----------------\n", FindMonthName(Month).c_str());

	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	short NumberOfDays = NumberOfDaysInMonth(Month, Year);
	short DayOrder = FindDayOrder(1, Month, Year);

	int i = 0;
	for (i = 0 ; i < DayOrder; i++)
	{
		printf("     ");
	}

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);


		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n ------------------------------------\n");
}

void PrintYearCalendar( short Year) {

	printf("\n ------------------------------------\n");
	printf("\t  Calender - %d", Year);
	printf("\n ------------------------------------\n");

	for (int i = 1; i <= 12; i++)
	{
		PrintMonthCalendar(i, Year);

	}
}

int main() {

	short Year = ReadYear();
	PrintYearCalendar(Year);

	system("pause > 0");
	return 0;

}
