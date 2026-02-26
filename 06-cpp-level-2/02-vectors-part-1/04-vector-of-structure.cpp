#include <iostream>
#include <vector>
using namespace std;

struct stEmployee {
	string FirsName;
	string LastName;
	float Salary;
};


int main() {

	vector <stEmployee> vEmployees;

	stEmployee tempEmployee;

	tempEmployee.FirsName = "Mohammed";
	tempEmployee.LastName = "Ahmed";
	tempEmployee.Salary = 4500;
	vEmployees.push_back(tempEmployee);

	tempEmployee.FirsName = "Sara";
	tempEmployee.LastName = "Omar";
	tempEmployee.Salary = 6000;
	vEmployees.push_back(tempEmployee);

	tempEmployee.FirsName = "Sami";
	tempEmployee.LastName = "Ahmed";
	tempEmployee.Salary = 8000;
	vEmployees.push_back(tempEmployee);

	for (stEmployee& E : vEmployees) {

		cout << "First Name = " << E.FirsName << endl;
		cout << "Last Name = " << E.LastName << endl;
		cout << "Salary = " << E.Salary << endl;
		cout << "\n";

	}


}
