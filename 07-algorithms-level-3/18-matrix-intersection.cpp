#include <iostream>
#include <ctime>

using namespace std;

int RandomNumber(int from, int to) {

    return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumber(int Matrix[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(1, 100);
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

bool IsNumberInMatrix(int Matrix1[3][3],short Rows, short Cols, int Num) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Num == Matrix1[i][j])
            {
               return true;
            }
        }
    }
    return false;
}

void PrintIntersectedNumbers(int Matrix1[3][3],int Matrix2[3][3], short Rows, short Cols) {

    int Num = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
           Num = Matrix2[i][j];

           if (IsNumberInMatrix(Matrix1, Rows, Cols, Num))
           {
               cout << Num << "\t";
           }
        }
    }
    cout << "\n";
}

int main() {

    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];

    FillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumber(Matrix2, 3, 3);
    cout << "\nMatrix2: \n";
    PrintMatrix(Matrix2, 3, 3);

    cout << "\nIntersected Numbers Are: \n";
    PrintIntersectedNumbers(Matrix1, Matrix2, 3, 3 );

    return 0;
}
