#include <iostream>
using namespace std;

void PrintArrayAddress(int* ptr, int length) {

    for (int i = 0; i < length; i++)
    {
        cout << ptr + i << "\n";
    }
}

void PrintArrayValues(int* ptr, int length) {

    for (int i = 0; i < length; i++)
    {
        cout << *(ptr + i) << "\n";
    }
}


int main() {
    
    int Arr[5] = { 5,4,3,2,1 };

    int* ptr = Arr;

    int length = sizeof(Arr) / sizeof(Arr[0]);

    cout << "The Address are:\n";
    PrintArrayAddress(ptr, length);

    cout << "\nThe Values are:\n";
   
    PrintArrayValues(ptr, length);


    return 0;
}
