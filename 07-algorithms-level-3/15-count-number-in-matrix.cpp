#include <iostream>
#include <ctime>
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
            Matrix[i][j] = RandomNumber(1, 10);
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

int CountNumberInMatrix(int Matrix[3][3], short Rows, short Cols , int NumberToCount) {
    
    int counter = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == NumberToCount)
            {
                counter++;
            }
        }
    }

    return counter;
}


int main() {

    srand((unsigned)time(NULL));

    int Matrix[3][3];
    int NumberToCount;

    FillMatrixWithRandomNumber(Matrix, 3, 3);

    cout << "Matrix: \n";
    PrintMatrix(Matrix, 3, 3);

    cout << "\nEnter the number to count in matrix? ";
    cin >> NumberToCount;

    cout << "\nNumber " << NumberToCount << " count in matrix is " << CountNumberInMatrix(Matrix, 3, 3, NumberToCount) << "\n";

    return 0;
}
