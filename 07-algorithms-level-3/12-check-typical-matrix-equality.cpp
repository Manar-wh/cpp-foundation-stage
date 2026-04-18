#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int RandomNumber(int from, int to) {

	return rand() % (to - from + 1) + from;
}

void FillMatrix(int Matrix[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Matrix[i][j] = RandomNumber(1, 10);
		}
	}
}


void PrintMatrix(int Matrix[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%02d \t", Matrix[i][j]);
		}
		cout << "\n";
	}
}

bool CheckIfMatricesAreTypical(int Matrix1[3][3], int Matrix2[3][3] ,short Row, short Cols) {


	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			if (Matrix1[i][j] != Matrix2[i][j])
			{
				return false;
			}
			else
				return true;
		}
	}
}

void PrintMatricesAreTypical(int Matrix1[3][3], int Matrix2[3][3], short Row, short Cols) {

	if (CheckIfMatricesAreTypical(Matrix1, Matrix2, Row, Cols))
	{
		cout << "\nMatrices Are Typical\n";
	}
	else
		cout << "\nMatrices Are Not Typical\n";
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];


	FillMatrix(Matrix1, 3, 3);
	cout << "Matrix1: \n";
	PrintMatrix(Matrix1, 3, 3);

	
	FillMatrix(Matrix2, 3, 3);
	cout << "Matrix2: \n";
	PrintMatrix(Matrix2, 3, 3);


	PrintMatricesAreTypical(Matrix1, Matrix2, 3, 3);

}
