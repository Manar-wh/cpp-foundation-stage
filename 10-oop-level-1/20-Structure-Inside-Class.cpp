#include <iostream>
using namespace std;

class clsA {

	struct stAddress {
		string AdressLine1;
		string AdressLine2;
		string city;
		string country;
	};

public:

	stAddress Address;
	clsA() {
		Address.AdressLine1 = "Corniche Road";
		Address.AdressLine2 = "Al Shati District";
		Address.city = "Jeddah";
		Address.country = "Saudi Arabia";
	}

	void PrintAddress() {

		cout << "country    : " << Address.country << "\n";
		cout << "city       : " << Address.city << "\n";
		cout << "AdressLine1: " << Address.AdressLine1 << "\n";
		cout << "AdressLine2: " << Address.AdressLine2 << "\n";
	}
};

int main() {

	clsA A;
	A.PrintAddress();
	system("pause>0");
	return 0;
}
