#include <iostream>
using namespace std;

class clsPerson {

	class clsAddress {

		string _AddressLine1;
		string _AddressLine2;
		string _City;
		string _Country;

	public:

		clsAddress(string AddressLine1, string AddressLine2, string City, string Country) {

			_AddressLine1 = AddressLine1;
			_AddressLine2 = AddressLine2;
			_City = City;
			_Country = Country;
		}

		void Print()
		{
			cout << "\nAddress:\n";
			cout << _AddressLine1 << endl;
			cout << _AddressLine2 << endl;
			cout << _City << endl;
			cout << _Country << endl;
		}
	};

	string _FirstName;
	string _LastName;

public:

	clsAddress Address;

	clsPerson(string FirstName, string LastName,string AddressLine1, string AddressLine2, string City, string Country)
		: Address(AddressLine1, AddressLine2, City, Country) 
	{
		_FirstName = FirstName;
		_LastName = LastName;
	}

	void Print()
	{
		cout << "\nPerson:\n";
		cout << _FirstName << endl;
		cout << _LastName << endl;
	}
};

int main() {

	clsPerson A("Ahmed", "Mohammed", "Corniche Road", "Al-Shati District", "Jeddah", "Saudi Arabia");
	A.Address.Print();
	A.Print();

	system("pause>0");
	return 0;
}
