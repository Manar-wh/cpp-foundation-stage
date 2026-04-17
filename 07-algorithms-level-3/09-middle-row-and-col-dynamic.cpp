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

void PrintMiddleRow(int Arr[3][3], short Row, short Cols) {

	short MiddleRow = Row / 2;

	for (int j = 0; j < Cols; j++)
	{
		printf("%02d \t", Arr[MiddleRow][j]);
	}
	cout << "\n";
}

void PrintMiddleCols(int Arr[3][3], short Row, short Cols) {

	short MiddleCols = Cols / 2;

	for (int i = 0; i < Row; i++)
	{
		printf("%02d \t", Arr[i][MiddleCols]);
	}
	cout << "\n";
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3];

	FillMatrix(Matrix, 3, 3);

	cout << "Matrix1: \n";
	PrintMatrix(Matrix, 3, 3);

	cout << "\nMiddle Row:  \n";
	PrintMiddleRow(Matrix, 3, 3);

	cout << "\nMiddle Column:  \n";

	PrintMiddleCols(Matrix, 3, 3);
}
