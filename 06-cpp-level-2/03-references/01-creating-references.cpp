#include <iostream>
using namespace std;

int main() {

  // Declare a normal variable
    int a = 10;

  // Declare a reference that refers to the same memory location as 'a'
    int& b = a;

  // Print values before change
    cout << "Value of a before change: " << a << endl;
    cout << "Value of b before change: " << b << endl;

  // Print memory addresses before change
    cout << "Address of a before change: " << &a << endl;
    cout << "Address of b before change: " << &b << endl;

    cout << "-----------------------------" << endl;

  // Change the value using the reference
    b = 49;

  // Print values after change
    cout << "Value of a after change: " << a << endl;
    cout << "Value of b after change: " << b << endl;

  // Print memory addresses after change
    cout << "Address of a after change: " << &a << endl;
    cout << "Address of b after change: " << &b << endl;

    return 0;
}
