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

void PrintMatrix(int Arr[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			printf("%02d \t", Arr[i][j]);
		}
		cout << "\n";
	}
}

void multiplymatrix(int Matrix1[3][3], int Matrix2[3][3], int MultiplyArray[3][3], short Row, short Cols) {


	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			MultiplyArray[i][j] = Matrix1[i][j] * Matrix2[i][j];
		}
	}
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix1[3][3];
	int Matrix2[3][3];
	int MultiplyArray[3][3];

	short Row = 3;
	short Cols = 3;

	FillMatrix(Matrix1, Row, Cols);

	FillMatrix(Matrix2, Row, Cols);

	multiplymatrix(Matrix1, Matrix2, MultiplyArray , Row, Cols);


	cout << "Matrix1: \n";
	PrintMatrix(Matrix1, Row, Cols);

	cout << "\nMatrix2: \n";
	PrintMatrix(Matrix2, Row, Cols);

	cout << "\nResult: \n";
	PrintMatrix(MultiplyArray, Row, Cols);
}
