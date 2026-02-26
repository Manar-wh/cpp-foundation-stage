#include <iostream>
using namespace std;

void Swap(int* n1, int* n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    
    int a = 10;
    int b = 5;

    cout << "\n Before swap \n";
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;

    Swap(&a, &b);

    cout << "\n After swap \n";
    cout << " a = " << a << endl;
    cout << " b = " << b << endl;


    return 0;
}
