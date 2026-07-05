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

    string GetFirstName() {
        return _FirstName;
    }

    __declspec(property(get = GetFirstName, put = setFirstName)) string FirstName;
};

int main()
{
    clsPerson Person1;

    Person1.FirstName = "Manar";
    cout << Person1.FirstName << "\n";
}
