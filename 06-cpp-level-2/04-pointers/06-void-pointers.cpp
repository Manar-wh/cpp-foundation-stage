#include <iostream>
using namespace std;

int main() {
    
    // Shows how a void pointer can hold different types and read their values

    void* ptr;

    float f1 = 20.4;
    int i = 3;

    ptr = &f1;

    cout << ptr << "\n";
    cout << *(static_cast<float*>(ptr)) << "\n";

    ptr = &i;

    cout << ptr << "\n";
    cout << *(static_cast<int*>(ptr)) << "\n";
}
