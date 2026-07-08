#include <iostream>
using namespace std;

class clsEmployee {

	int _ID;
	string _FirstName;
	string _LastName;
	string _Title;
	string _Email;
	string _Phone;
	int _Salary;
	string _Department;

public:

	clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, int Salary, string Department) {
		_ID = ID;
		_FirstName = FirstName;
		_LastName = LastName;
		_Title = Title;
		_Email = Email;
		_Phone = Phone;
		_Salary = Salary;
		_Department = Department;
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

	void setTitle(string Title) {
		_Title = Title;
	}
	string Title() {
		return _Title;
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

	void setSalary(int Salary) {
		_Salary = Salary;
	}
	int Salary() {
		return _Salary;
	}

	void setDepartment(string Department) {
		_Department = Department;
	}
	string Department() {
		return _Department;
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

	void PrintEmployee() {
		cout << "info:\n";
		cout << "---------------------------\n";
		cout << "ID         : " << _ID << "\n";
		cout << "FirstName  : " << _FirstName << "\n";
		cout << "LastName   : " << _LastName << "\n";
		cout << "FullName   : " << FullName() << "\n";
		cout << "Title      : " << _Title << "\n";
		cout << "Email      : " << _Email << "\n";
		cout << "Phone      : " << _Phone << "\n";
		cout << "Salary     : " << _Salary << "\n";
		cout << "Department : " << _Department << "\n";
		cout << "---------------------------\n";
	}

};

int main() {
   
	// 	clsEmployee(int ID, string FirstName, string LastName, string Title, string Email, string Phone, int Salary, string Department) {

	clsEmployee Employee1(1, "Manar", "Alwahedi", "Wep Developer", "Manar@gmail.com", "012345678", 10000, "IT Department");
	Employee1.PrintEmployee();
	Employee1.SendEmail("\nWelcome to the Team!", "Dear Manar,\nwe are thrilled to have you with us as a Wep Developer in the IT Department.\nWishing you a great journey ahead!");
	Employee1.SendSMS("\nYour salary of 10000 SAR has been successfully deposited into your bank account.\nThank you for your hard work!");
	system("pause");
	return 0;
}	

