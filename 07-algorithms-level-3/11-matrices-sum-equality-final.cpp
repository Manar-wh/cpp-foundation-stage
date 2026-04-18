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

int SumNumbersOfMatrix(int Matrix[3][3], short Row, short Cols) {

	int Sum = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += Matrix[i][j];
		}
	}

	return Sum;
}

bool IsMatricesAreEqual(int Matrix1[3][3], int Matrix2[3][3], short Row, short Cols) {

	return (SumNumbersOfMatrix(Matrix1, Row, Cols) == SumNumbersOfMatrix(Matrix2, Row, Cols));
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

	if (IsMatricesAreEqual(Matrix1, Matrix2, 3, 3))
		cout << "\nMatrices are equal\n";
	else
		cout << "\nMatrices are NOT equal\n"; 


	

}
