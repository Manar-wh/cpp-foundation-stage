#include <iostream>
using namespace std;

int main() {

 // Declare a normal integer variable
    int a = 10;

 // Declare a pointer to int
    int* p;

 // Store the address of variable 'a' in pointer 'p'
    p = &a;

 // Print the address of variable 'a'
    cout << "Address of a (&a): " << &a << endl;

 // Print the value of pointer p (which is the address of a)
    cout << "Value of p (address stored in pointer): " << p << endl;

 // Print the value of 'a'
    cout << "Value of a: " << a << endl;

 // Print the value that p points to (dereferencing the pointer)
    cout << "Value pointed to by p (*p): " << *p << endl;

 // Print the address of the pointer itself
    cout << "Address of pointer p (&p): " << &p << endl;

    return 0;
}
