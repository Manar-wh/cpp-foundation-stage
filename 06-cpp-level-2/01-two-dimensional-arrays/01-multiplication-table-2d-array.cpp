#include <iostream>
#include <cstdio> // Required for printf

using namespace std;

// Function to fill the 2D array with multiplication table data
void fillarr(int Mult[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            Mult[i][j] = (i + 1) * (j + 1);
        }
    }
}

// Function to print the 2D array with proper formatting
void printarr(int Mult[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            // Using printf for aligned columns
            printf("%*d ", 3, Mult[i][j]);
        }
        cout << endl;
    }
}

int main() {
    int Mult[12][12];

    fillarr(Mult);
    printarr(Mult);

    return 0;
}
