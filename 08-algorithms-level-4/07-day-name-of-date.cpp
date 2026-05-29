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

int FindDayOrder(short Year, short Month, short Day) {


	short a = (14 - Month) / 12;
	short y = Year - a;
	short m = Month + (12 * a) - 2;

	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

	return d;
}

string FindDayName(short DayOrder) {

	string DaysOfTheWeek[7] = { "Sun","Mon", "Tues", "Wed", "Thurs", "Fri", "Sat"};
	return DaysOfTheWeek[DayOrder];
}

void PrintDate(short Year, short Month, short Day) {

	int DayOrder = FindDayOrder(Year, Month, Day);

	string DayName = FindDayName(DayOrder);

	cout << "\nDate    : " << Day << "/" << Month << "/" << Year << "\n";
	cout << "Day Order : " << DayOrder << "\n";
	cout << "Day Name  : " << DayName << "\n";

}

int main() {

	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	PrintDate(Year, Month, Day);

	system("pause > 0");
	return 0;
}
