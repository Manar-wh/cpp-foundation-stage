#include <iostream>
using namespace std;

int main() {
    
    int arr[6] = { 4,6,2,1,4,8 };
    int* p = arr;

    cout << "Adrress :\n";
    cout << p << "\n";
    cout << p + 1 << "\n";
    cout << p + 2 << "\n";
    cout << p + 3 << "\n";
    cout << p + 4 << "\n";
    cout << p + 5 << "\n";

    cout << "\nValues :\n";
    cout << *p << "\n";
    cout << *(p+1) << "\n";
    cout << *(p + 2) << "\n";
    cout << *(p + 3) << "\n";
    cout << *(p + 4) << "\n";
    cout << *(p + 5) << "\n";

}
