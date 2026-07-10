#include <iostream> 
using namespace std;

class clsA {
public:
    int x;

    // Method to print the value of x for the current object
    void Print()
    {
        cout << "The value of x=" << x << endl;
    }
};

// Passing by Value: Takes a copy of the object, does NOT affect the original one
void Func1(clsA A) {
    A.x = 10;
}

// Passing by Reference: Takes the actual object, any modification will affect the original one
void Func2(clsA& A) {
    A.x = 200;
}

int main() {

    clsA A1;
    A1.x = 50;

    cout << "A.x before calling function is: ";
    A1.Print();

    // Passing the object by value
    Func1(A1);
    cout << "\nThe value of x After calling function1 (byVal) is: ";
    A1.Print();

    // Passing the object by reference
    Func2(A1);
    cout << "\nThe value of x After calling function2 (byRef) is: ";
    A1.Print();

    return 0;
}
