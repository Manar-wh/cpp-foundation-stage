#include <iostream> 
using namespace std;

class clsEmployee {
public:
string ID;
string Name;
int salary;

clsEmployee(string ID, string Name, int salary) {

    this->ID = ID;
    this->Name = Name;
    this->salary = salary;
}

static void Fun1(clsEmployee Employee1) {

    Employee1.Print();
}

void Func2() {

    Fun1(*this);
}

void Print() {

    cout << this->ID << " " << this->Name << " " << this->salary << "\n";
}
}; 

int main() {

    clsEmployee Employee1("10", "Ahmed", 9000);
    Employee1.Func2();

    return 0;
}
