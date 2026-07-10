#include <iostream>
#include <vector>
using namespace std;

class clsA {
public:
    int x;

    // Default constructor: required to allocate the array using 'new'
    clsA() {}

    // Parameterized constructor: used to set the value of x
    clsA(int value) {
        x = value;
    }

    void Print() {
        cout << "The value of x=" << x << endl;
    }
};

int main() {
    short NumberOfObject = 5;

    // Allocate dynamic array in Heap; 'Arr' pointer points to this array
    clsA* Arr = new clsA[NumberOfObject];

    // Loop to initialize each object in the array using the constructor
    for (short i = 0; i < NumberOfObject; i++) {
        Arr[i] = clsA(i); // Navigate via pointer to fill the object at index i
    }

    // Loop to display the values
    for (short i = 0; i < NumberOfObject; i++) {
        Arr[i].Print();
    }

    // Recommended: Free the allocated memory from the Heap
    delete[] Arr;

    return 0;
}
