#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;


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

bool IsScalarMatrix(int Matrix[3][3],short Row, short Cols) {

	int FirstElement = Matrix[0][0];

	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			
			if (i == j && Matrix[i][j] != FirstElement)
			{
				return false;
			}
			else if (i != j && Matrix[i][j] != 0) {
				return false;
			}
		}
	}
	return true;
}

void PrintIsScalarMarix(int Matrix[3][3], short Row, short Cols) {

	if (IsScalarMatrix(Matrix, Row, Cols))
	{
		cout << "\nYes: Matrix is scalar\n";
	}
	else
		cout << "\nNo: Matrix is Not scalar\n";
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3] = {
		{7,0,0},
		{0,7,0},
		{0,0,7}
	};

	cout << "Matrix: \n";

	PrintMatrix(Matrix, 3, 3);
	
	PrintIsScalarMarix(Matrix, 3, 3);

}
