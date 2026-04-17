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

int SumNumbersOfMatrix(int Arr[3][3], short Row, short Cols) {

	int Sum = 0;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Sum += Arr[i][j];
		}
	}
	return Sum;
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrix(Matrix, 3, 3);

	cout << "Matrix: \n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nSum of matrix is:  " << SumNumbersOfMatrix(Matrix, 3, 3) << "\n";
	
}
