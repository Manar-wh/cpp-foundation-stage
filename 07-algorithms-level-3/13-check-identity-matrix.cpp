#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%02d \t", Matrix[i][j]);
        }
        cout << "\n";
    }
}

bool IsIdentityMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            if (i == j && Matrix[i][j] != 1) {
                return false;
            }
            else if (i != j && Matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

void DisplayIdentityResult(int Matrix[3][3], short Rows, short Cols) {
    if (IsIdentityMatrix(Matrix, Rows, Cols)) {
        cout << "\nYES: Matrix is Identity.\n";
    }
    else {
        cout << "\nNO: Matrix is NOT Identity.\n";
    }
}

int main() {
    srand((unsigned)time(NULL));

    int Matrix[3][3] = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };

    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    DisplayIdentityResult(Matrix, 3, 3);

    return 0;
}
