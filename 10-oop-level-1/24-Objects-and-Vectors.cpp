#include <iostream> 
#include <vector>
using namespace std;

class clsA {
public:
    int x;

    // Parameterized Constructor to initialize x
    clsA(int value) {
        x = value;
    }

    // Method to print the value of x
    void Print()
    {
        cout << "The value of x=" << x << endl;
    }
};

int main() {

    // Creating a vector that stores objects of type clsA
    vector <clsA> V1;
    short NumberOfObjects = 5;
    
    // 1. Inserting objects into the vector using a loop
    for (int i = 0; i < NumberOfObjects; i++)
    {
        // clsA(i) creates a temporary anonymous object and pushes it into the vector
        V1.push_back(clsA(i));
    }

    // 2. Iterating through the vector and calling the Print method for each object
    for (int i = 0; i < NumberOfObjects; i++)
    {
        V1[i].Print();
    }

    return 0;
}
