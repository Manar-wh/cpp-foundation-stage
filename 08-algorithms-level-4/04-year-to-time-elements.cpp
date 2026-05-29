#include <iostream>
using namespace std;



short ReadYear() {
	short Year;
	cout << "Please enter The Year ? ";
	cin >> Year;
	return Year;
}

bool IsLeapYear(short Year) {
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short NumberOfDays(short Year) {

	return IsLeapYear(Year) ? 366 : 365;
}

int NumberOfHours(short Year) {

	return NumberOfDays(Year) * 24;
}

int NumberOfMins(short Year) {

	return NumberOfHours(Year) * 60;
}

int NumberOfsecond(short Year) {

	return NumberOfMins(Year) * 60;
}


int main() {

	short Year = ReadYear();

	cout << "\nNumber of Days in Year [" << Year << "] is " << NumberOfDays(Year);
	cout << "\nNumber of Hours in Year [" << Year << "] is " << NumberOfHours(Year);
	cout << "\nNumber of Minutes in Year [" << Year << "] is " << NumberOfMins(Year);
	cout << "\nNumber of Seconds in Year [" << Year << "] is " << NumberOfsecond(Year);

	system("pause > 0");
	return 0;

}
