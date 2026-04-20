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
            Matrix[i][j] = RandomNumber(0, 100);
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

bool IsNumberInMatrix(int Matrix[3][3], short Rows, short Cols, int Num) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Num)
            {
                return true;
            }
        }
    }
    return false;
}

int main() {

    srand((unsigned)time(NULL));
    int Num;

    int Matrix[3][3];

    FillMatrixWithRandomNumber(Matrix, 3, 3);

    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "\nEnter the number to look for in matrix: ";
    cin >> Num;

    if (IsNumberInMatrix(Matrix, 3, 3, Num))
    {
        cout << "\nYES it is there\n";
    }else
        cout << "\nNo it is not there\n";

    return 0;
}
