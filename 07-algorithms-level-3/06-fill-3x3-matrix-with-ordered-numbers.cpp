#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

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
			cout << setw(1) << Arr[i][j] << "     ";
		}
		cout << "\n";
	}

}

int main() {

	int Arr[3][3];

	FillArrayWithOrderNumbers(Arr, 3, 3);

	cout << "\nThe following is a 3x3 matrix:\n\n";

	PrintMatrix(Arr, 3, 3);
}
