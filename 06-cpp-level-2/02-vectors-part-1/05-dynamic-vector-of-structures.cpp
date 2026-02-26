#include <iostream>
#include<vector>
using namespace std;

struct stEmployee {
	string FirstName;
	string LastName;
	float Salary=0;
};

void ReadEmployeeinfo(vector <stEmployee>& vEmployees) {

	stEmployee tempEmployee;
	char IfYes;
	do
	{
		cout << "Enter Employee First Name: ";
		cin >> tempEmployee.FirstName;
		cout << "Enter Employee Last Name: ";
		cin >> tempEmployee.LastName;
		cout << "Enter Employee Salary: ";
		cin >> tempEmployee.Salary;
		vEmployees.push_back(tempEmployee);

		cout << "\nDo you want to enter another Employee ? Yes[Y] / No[N] : ";
		cin >> IfYes;

	} while (IfYes == 'y' || IfYes == 'Y');
}

void PrintEmployeeInfo(const vector <stEmployee>& vEmployees) {

	cout << "\nEmployees Information\n";

	for (const stEmployee& E : vEmployees) {

		cout << "\nEmployee First Name: " << E.FirstName;
		cout << "\nEmployee Last Name: " << E.LastName;
		cout << "\nEmployee Salary: " << E.Salary;

		cout << "\n---------------------\n";
	}
}

void CleanScreen() {

	system("cls");
	system("color 0F");
}

int main() {

	vector <stEmployee> vEmployees;

	ReadEmployeeinfo(vEmployees);
	CleanScreen();
	PrintEmployeeInfo(vEmployees);

}
