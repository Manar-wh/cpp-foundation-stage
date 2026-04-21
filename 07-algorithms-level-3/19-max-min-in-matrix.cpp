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

int MaxiNumInMatrix(int Matrix[3][3], short Rows, short Cols) {

    int MaximumNum = Matrix[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (MaximumNum < Matrix[i][j])
            {
                MaximumNum = Matrix[i][j];
            }
            
        }
    }
   return MaximumNum;
}

int MinimumNumInMatrix(int Matrix[3][3], short Rows, short Cols) {

    int minimumNum = Matrix[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (minimumNum > Matrix[i][j])
            {
                minimumNum = Matrix[i][j];
            }

        }
    }
    return minimumNum;
}

int main() {

    srand((unsigned)time(NULL));

    int Matrix1[3][3];
    int Matrix2[3][3];

    FillMatrixWithRandomNumber(Matrix1, 3, 3);
    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMax Number Is: " << MaxiNumInMatrix(Matrix1, 3, 3) << "\n";

    cout << "\nMinimum Number Is: " << MinimumNumInMatrix(Matrix1, 3, 3) << "\n";

    return 0;
}
