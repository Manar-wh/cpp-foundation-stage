#include <iostream>
using namespace std;

void printArray(int arr[4][4]) {

    for (int i = 0; i < 4; i++) {

        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";

        }
        cout << "\n";
    }
}

void reverseRows(int arr[4][4]) {
    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 4; j++) {

            swap(arr[i][j], arr[3 - i][j]);
        }
    }
}

int main() {
    int Arr1[4][4]{
        {6,4,8,7},
        {9,2,7,2},
        {3,5,1,6},
        {4,4,2,4}
    };

    cout << "Original Array:\n";
    printArray(Arr1);

    reverseRows(Arr1);

    cout << "\nReversed Rows Array:\n";
    printArray(Arr1);
}
