#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int from, int to) {

    return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumber(int matrix[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			matrix[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int matrix[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << matrix[i][j] << "     ";
		}
		cout << endl;
	}
}

int SumOneCol(int matrix[3][3], short Rows, short ColIndex) {

	int sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		sum += matrix[i][ColIndex];
	}

	return sum;
}

void FillColumnSums(int matrix[3][3], int ArrSum[3], short Rows, short Cols) {


	for (int j = 0; j < Cols; j++)
	{

		ArrSum[j] = SumOneCol(matrix, Rows, j);
	}
}

void PrintColumnSums(int colSums[3], short length) {

	for (int i = 0; i < length; i++)
	{
		cout << "Col " << i + 1 << " Sum = " << colSums[i] << endl;
	}

}


int main()
{

    srand((unsigned)time(NULL));

	int matrix[3][3];

	int colSums[3];

	FillMatrixWithRandomNumber(matrix,3 , 3);

	cout << "\nThe following is a 3x3 random matrix: \n";
	PrintMatrix(matrix, 3, 3);

	FillColumnSums(matrix, colSums, 3, 3);

	cout << "\n\nThe following are the sum of each column in the matrix: \n";

	PrintColumnSums(colSums, 3);
   
}

