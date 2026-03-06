#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumbers(int from, int to) {
    int number;
    number = rand() % (to - from + 1) + from;
    return number;
}

void FillMatrixWithRandomNumbers(int array[3][3], short Rows , short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
           array[i][j] = RandomNumbers(1, 100);
        }
    }
}

void PrintMatrix(int array[3][3], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << array[i][j] << "       ";
        }
        cout << endl;
    }
}

int RowSum(int array[3][3], short RowNumber, short Cols) {


        int sum = 0;

        for (int j = 0; j < Cols; j++)
        {
            sum += array[RowNumber][j];

        }
        return sum;
}

void FillArray2(int array[3][3], int ArrSum[], short Rows, short Cols) {

    for (int i = 0; i < Rows; i++)
    {
        ArrSum[i] = RowSum(array, i, Cols);
    }
}

void PrintArray2(int ArrSum[], short Rows) {

    cout << "\nThe the following are the sum of each row in the matrix:\n";

    for (int i = 0; i < Rows; i++)
    {
        cout << "Row " << i + 1 << " Sum = " << ArrSum[i] << endl;
    }
}


int main()
{

    srand((unsigned)time(NULL));

    int array[3][3];

    FillMatrixWithRandomNumbers(array, 3, 3);
    
    cout << "The following is 3x3 random matrix: \n";

    PrintMatrix(array, 3, 3);

    int ArrSum[3];

    FillArray2(array , ArrSum, 3, 3);
    PrintArray2(ArrSum, 3);
}

