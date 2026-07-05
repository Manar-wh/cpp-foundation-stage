#include <iostream>
using namespace std;

//Understanding OOP Access Modifiers 

class clsPerson {
private:
    // Members inside 'private' are ONLY accessible within this class.
    int x = 6;

    int Func1() {
        return 50;
    }

protected:
    // Members inside 'protected' are accessible within this class and inherited classes.
    int y = 7;

    int func3() {
        return 60;
    }

public:
    // Members inside 'public' are accessible from anywhere outside the class (e.g., main function).
    string FirstName;
    string LastName;

    // Directly uses member variables because they share the same scope (class room).
    string FullName() {
        return FirstName + " " + LastName;
    }

    // Uses the public FullName() function internally to build a greeting message.
    string SendGreetint() {
        return "Hi " + FullName() + "! Welcome to OOP Level 1";
    }

    // An indirect bridge to access private and protected members safely.
    int Sumint() {
        // Formula: 50 * 6 - 7 = 293
        return Func1() * x - y;
    }
};
int main()
{
    clsPerson Person1;
    Person1.FirstName = "Manar";
    Person1.LastName = "Alwahedi";
    cout << Person1.FullName()<< "\n";
    cout << Person1.SendGreetint() << "\n";

   cout << Person1.Sumint() << "\n";
}
