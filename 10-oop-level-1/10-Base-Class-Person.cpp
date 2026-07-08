#include <iostream>
using namespace std;

class clsPerson{
	int _ID;
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;

public:
	
	clsPerson(int ID, string FirstName, string LastName, string Email, string Phone) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Email = Email;
		_Phone = Phone;
	}

	int ID() {
		return _ID;
	}

	void setFirstName(string FirstName) {
		_FirstName = FirstName;
	}
	string FirstName() {
		return _FirstName;
	}

	void setLastName(string LastName) {
		_LastName = LastName;
	}
	string LastName() {
		return _LastName;
	}

	string FullName() {
		return _FirstName + " " + _LastName;
	}

	void setEmail(string Email) {
		_Email = Email;
	}

	string Email() {
		return _Email;
	}

	void setPhone(string Phone) {
		_Phone = Phone;
	}

	string Phone() {
		return _Phone;
	}

	void PrintPerson() {
		cout << "info:\n";
		cout << "---------------------------\n";
		cout << "ID       : " << _ID << "\n";
		cout << "FirstName: " << _FirstName << "\n";
		cout << "LastName : " << _LastName  << "\n";
		cout << "FullName : " << FullName() << "\n";
		cout << "Email    : " << _Email     << "\n";
		cout << "Phone    : " << _Phone     << "\n";
		cout << "---------------------------\n";
	}

	void SendEmail(string Subject, string Message) {
		cout << "\nThe Following message sent successfully to email: " << _Email << "\n";
		cout << "Subject: " << Subject << "\n";
		cout << "Body: " << Message << "\n";
	}

	void SendSMS(string SMS) {
		cout << "\nThe Following SMS sent successfully to phone: " << _Phone << "\n";
		cout << "Body: " << SMS << "\n";
	}
};

int main() {

	clsPerson Person1(1, "Manar", "Alwahedi", "Manar@gmail.com", "01234567");
	Person1.PrintPerson();
	Person1.SendEmail("Are you fine?", "Hi, How are you? ");
	Person1.SendSMS("Hi, How are you ? ");
	
	return 0;
}
