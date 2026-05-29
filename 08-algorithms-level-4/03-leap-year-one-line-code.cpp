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

int main() {
	short Year = ReadYear();

	cout << "\n" << Year << (IsLeapYear(Year) ? " Is a leap year. " : " Is not a leap year. ");
}
