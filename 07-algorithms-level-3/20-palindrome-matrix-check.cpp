#include <iostream>
using namespace std;

void PrintMatrix(int Matrix[3][3], short Rows, short Cols) {
    for (int i = 0; i < Rows; i++) {
        for (int j = 0; j < Cols; j++) {
            printf("%02d \t", Matrix[i][j]);
        }
        cout << "\n";
    }
}

bool IsPalindromeMatrix(int Matrix[3][3], short Rows, short Cols) {


    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] !=  Matrix[i][Cols - 1  - j])
            {
                return false;
            } 
        }
    }
    return true;
}

int main() {

    srand((unsigned)time(NULL));

    int Matrix1[3][3] = { {8,7,8}, {1,9,1}, {0,2,0} };

    cout << "Matrix1: \n";
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
    {
        cout << "\nMatrix Is palindrome\n";
    }
    else
        cout << "\nMatrix Is NOT palindrome\n";

    return 0;
}
