#include <iostream>
using namespace std;

class clsAddress
{
	string _AddressLine1;
	string _AddressLine2;
	string _POBox;
	string _ZipCode;

public:

	clsAddress(string AddressLine1, string AddressLine2, string POBox, string ZipCode) {
		_AddressLine1 = AddressLine1;
		_AddressLine2 = AddressLine2;
		_POBox = POBox;
		_ZipCode = ZipCode;
	}

	void setAddressLine1(string AddressLine1) {
		_AddressLine1 = AddressLine1;
	}

	string AddressLine1() {
		return _AddressLine1;
	}

	void setAddressLine2(string AddressLine2) {
		_AddressLine2 = AddressLine2;
	}

	string AddressLine2() {
		return _AddressLine2;
	}

	void setPOBox(string POBox) {
		_POBox = POBox;
	}

	string POBox() {
		return _POBox;
	}

	void setZipCode(string ZipCode) {
		_ZipCode = ZipCode;
	}

	string ZipCode() {
		return _ZipCode;
	}

	void PrintAddress() {

		cout << "Address Details\n";
		cout << "----------------------\n";
		cout << "AddressLine1: " << _AddressLine1 << "\n";
		cout << "AddressLine2: " << _AddressLine2 << "\n";
		cout << "POBox       : " << _POBox << "\n";
		cout << "ZipCode     : " << _ZipCode << "\n";

	}
};

int main() {
   
	clsAddress Address1("Almasudi Street","Prince Fahad street","1234",  "3212" );
	Address1.PrintAddress();

	Address1.setAddressLine1("King Abdulaziz Road");
	cout << "\nUpdate Address Line 1:" << Address1.AddressLine1();

}
