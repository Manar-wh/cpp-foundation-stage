#include <iostream>
using namespace std;

class clsPerson {

    string _FirstName;
    string _LastName;

public:

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
        return  FirstName() + " " + LastName();
    }
};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Manar");
    Person1.setLastName("Alwahedi");
    cout << Person1.FullName();
}
