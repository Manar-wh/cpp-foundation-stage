#include <iostream>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to) {

    return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(0, 1);
        }
    }
}

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%02d \t", Matrix[i][j]);
        }
        cout << "\n";
    }
}

int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols, int Num) {
    
    int CountNum = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Num)
            {
                CountNum++;
            }
        }
    }
    return CountNum;
}


bool IsSparseMatrix(int Matrix[3][3], short Rows, short Cols) {

    short MatrixSize = Rows * Cols;
    return (CountNumberInMatrix(Matrix, 3, 3, 0) >= ceil((float)MatrixSize / 2));
}

int main() {

    srand((unsigned)time(NULL));
    int CounteZero = 0;
    int CountNum = 0;
    int Matrix[3][3];

    FillMatrixWithRandomNumber(Matrix, 3, 3);

    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);


    if (IsSparseMatrix(Matrix, 3, 3))
    {
        cout << "\nYES: It is sparse\n";
    }
    else
        cout << "\nNO: It is NOT sparse\n";

    return 0;
}
