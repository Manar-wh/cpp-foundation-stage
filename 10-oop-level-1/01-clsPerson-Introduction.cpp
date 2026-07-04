#include <iostream>
using namespace std;

class clsPerson {

public:
    string FirstName;
    string LastName;

    string FullName() {

        return FirstName + " " + LastName;
    }

    string SendGreetint() {
        return "Hi " + FullName() + "! Welcome to OOP Level 1";
    }
};

int main()
{
    clsPerson Person1;
    Person1.FirstName = "Manar";
    Person1.LastName = "Alwahedi";
    cout << Person1.FullName()<< "\n";
    cout << Person1.SendGreetint();
}
