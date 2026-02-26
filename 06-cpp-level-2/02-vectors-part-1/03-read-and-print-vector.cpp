#include <iostream>
#include <vector>
using namespace std;

int ReadNumberOnly(string Message) {

	int Number;
	cout << Message;
	cin >> Number;

	while (cin.fail()) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid number, try again: ";
		cin >> Number;
	}
	return Number;
}

void ReadVectorNum(vector <int> & vNumbers) {

	int n;
	char IfYes;

	do
	{
		 n = ReadNumberOnly("Please Enteer a Number: ");

		vNumbers.push_back(n);

		cout << "Do You Want to enter another Number Y/N  ? ";
		cin >> IfYes;

	} while (IfYes == 'y' || IfYes == 'Y');
}

void PrintVectorNumbers(vector <int>& vNumbers) {

	cout << "\nThe Numbers: \n";

	for (int num : vNumbers) {
		cout << num << " ";
	}
	cout << "\n";
}

int main() {

	vector <int> vNumbers;

	ReadVectorNum(vNumbers);
	PrintVectorNumbers(vNumbers);

	return 0;
}
