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

int main()
{

    srand((unsigned)time(NULL));

    int array[3][3];

    FillMatrixWithRandomNumbers(array, 3, 3);
    
    cout << "The following is 3x3 random matrix: \n";

    PrintMatrix(array, 3, 3);

}

