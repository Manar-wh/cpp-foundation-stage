#include <iostream>
using namespace std;

struct stEmployee {
    string FirstName;
    float Salary;
};

int main() {
    
    stEmployee Employee, * ptr;

    Employee.FirstName = "Manar";
    Employee.Salary = 10000;

    cout << "Employee Name: " << Employee.FirstName << "\n";
    cout << "Employee Salary: " << Employee.Salary << "\n";

    ptr = &Employee;

    cout << "\nPrinting Using Pointer:\n";
    cout << ptr->FirstName << "\n";
    cout << ptr->Salary << "\n";

}
