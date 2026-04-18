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

bool CheckMatricesIdentity(int Matrix[3][3],short Row, short Cols) {


	for (int i = 0; i < Row; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			
			if (i == j && Matrix[i][j] != 1)
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

void PrintMatricesAreTypical(int Matrix[3][3], short Row, short Cols) {

	if (CheckMatricesIdentity(Matrix, Row, Cols))
	{
		cout << "\nYes: Matrices Are Identity\n";
	}
	else
		cout << "\nNo: Matrices Are Not Identity\n";
}

int main() {

	srand((unsigned)time(NULL));

	int Matrix[3][3] = {
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};

	cout << "Matrix: \n";

	PrintMatrix(Matrix, 3, 3);

	
	PrintMatricesAreTypical(Matrix, 3, 3);

}
