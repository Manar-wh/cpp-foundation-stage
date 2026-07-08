#include <iostream>
using namespace std;

class clsPerson {
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

	void PrintInfo() {
		cout << "info:\n";
		cout << "---------------------------\n";
		cout << "ID        : " << _ID << "\n";
		cout << "FirstName : " << _FirstName << "\n";
		cout << "LastName  : " << _LastName << "\n";
		cout << "FullName  : " << FullName() << "\n";
		cout << "Email     : " << _Email << "\n";
		cout << "Phone     : " << _Phone << "\n";
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

class clsEmployee : public clsPerson {

	double _Salary;
	string _Title;
	string _Department;

public:

	clsEmployee(int ID, string FirstName, string LastName, string Email, string Phone, string Title, string Department, double Salary) : clsPerson(ID,  FirstName,  LastName,  Email,  Phone) {
		_Salary = Salary;
		_Title = Title;
		_Department = Department;
	}

	void setSalary(double Salary) {
		_Salary = Salary;
	}
	double Salary() {
		return _Salary;
	}

	void setTitle(string Title) {
		_Title = Title;
	}
	string Title() {
		return _Title;
	}

	void setDepartment(string Department) {
		_Department = Department;
	}
	string Department() {
		return _Department;
	}
		
	void PrintInfo() {

		clsPerson::PrintInfo();
		cout << "Title     : " << _Title << "\n";
		cout << "Department: " << _Department << "\n";
		cout << "Salary    : " << _Salary << "\n";
		cout << "---------------------------\n";
	}
};

int main() {
	clsEmployee Employee1(10, "Ahmed", "Alqhtani", "ahqht@gmail.com", "05029292929", "Web Developer", "IT Teqnology", 6500);
	Employee1.PrintInfo();
	return 0;
}
