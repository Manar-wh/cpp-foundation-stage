#include <iostream>
using namespace std;

void FillArrayWithOrderNumbers(int Arr[3][3], short Row, short Cols) {

	int counter = 1;

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			Arr[i][j] = counter++;
		}
	}
}

void PrintMatrix(int Arr[3][3], short Row, short Cols) {

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << "\n";

	}
}

void TransposeMatrix(int Arr[3][3], int Transpose[3][3], short Row, short Cols) {
	
	for (int i = 0; i < Row; i++)
	{

		for (int j = 0; j < Cols; j++)
		{

			Transpose[j][i] = Arr[i][j];
		}
	}
}


int main() {

	int Arr[3][3];

	int Transpose[3][3];

	FillArrayWithOrderNumbers(Arr, 3, 3);

	cout << "The following is a 3x3 matrix:\n";

	PrintMatrix(Arr, 3, 3);

	TransposeMatrix(Arr, Transpose, 3, 3);

	cout << "\n\nThe following is the transposed matrix:\n";
	PrintMatrix(Transpose, 3, 3);

}
