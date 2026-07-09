#include <iostream>
using namespace std;

class clsPerson {
public:

	class clsAddress {
	private:
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

		void SetAddressLine1(string AddressLine1) {
			_AddressLine1 = AddressLine1;
		}
		string AddressLine1() {
			return _AddressLine1;
		}

		void SetAddressLine2(string AddressLine2) {
			_AddressLine2 = AddressLine2;
		}
		string AddressLine2() {
			return _AddressLine2;
		}

		void SetCity(string City) {
			_City = City;
		}
		string City() {
			return _City;
		}

		void SetCountry(string Country) {
			_Country = Country;
		}
		string Country() {
			return _Country;
		}

		void Print() {
			cout << "\nAddress:\n";
			cout << _AddressLine1 << endl;
			cout << _AddressLine2 << endl;
			cout << _City << endl;
			cout << _Country << endl;
		}
	};

private:
	string _FirstName;
	string _LastName;

public:
	clsAddress Address;

	clsPerson(string FirstName, string LastName, string AddressLine1, string AddressLine2, string City, string Country)
		: Address(AddressLine1, AddressLine2, City, Country)
	{
		_FirstName = FirstName;
		_LastName = LastName;
	}

	void SetFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string FirstName() {
		return _FirstName;
	}

	void SetLastName(string LastName) {
		_LastName = LastName;
	}
	string LastName() {
		return _LastName;
	}

	string FullName() {
		return _FirstName + " " + _LastName;
	}

	void Print() {
		cout << "\nPerson:\n";
		cout << _FirstName << endl;
		cout << _LastName << endl;
		cout << FullName() << endl;
	}
};

int main() {
	clsPerson A("Ahmed", "Mohammed", "Corniche Road", "Al-Shati District", "Jeddah", "Saudi Arabia");
	A.Address.Print();
	A.Print();

	system("pause>0");
	return 0;
}
