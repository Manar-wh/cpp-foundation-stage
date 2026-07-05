#include <iostream>
using namespace std;

class clsPerson {

    int _ID = 10;
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
        return  _FirstName + " " + _LastName;
    }

    //Read only Property
    int ID() {
        return _ID;
    }
};

int main()
{
    clsPerson Person1;

    Person1.setFirstName("Manar");
    Person1.setLastName("Alwahedi");

    cout << "ID: " << Person1.ID() << "\n";
    cout << "First Name: " << Person1.FirstName() << "\n";
    cout << "Last Name: " << Person1.LastName() << "\n";
    cout << "Full Name: " << Person1.FullName() << "\n";

}
