#include <iostream>
#include <vector>
using namespace std;

class clsA {
public:
    int x;

    // Parameterized Constructor only! Clean and logical.
    clsA(int value) {
        x = value;
    }

    void Print() {
        cout << "The value of x=" << x << endl;
    }
};

int main() {
    // 3 elements initialized directly in one step
    clsA Arr[] = { clsA(10), clsA(20), clsA(30) };

    // Loop exactly 3 times (the size of your array)
    for (short i = 0; i < 3; i++) {
        Arr[i].Print();
    }
    
    return 0;
}
