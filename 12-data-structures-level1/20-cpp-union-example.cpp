#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
    char c;
};

int main() {
    Data data;

    data.i = 10;
    cout << "data.i: " << data.i << endl;

    data.f = 220.5; // Here data.i is overwritten and replaced by the float value
    cout << "data.f: " << data.f << endl;

    // If we try to print data.i here, it will output a garbage value because the memory was modified
    cout << "data.i after setting f: " << data.i << endl; 

    return 0;
}
