#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int from, int to) {

    return rand() % (to - from + 1) + from;
}

void FillMatrixWithRandomNumber(int array[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			array[i][j] = RandomNumber(1, 100);
		}
	}
}

void PrintMatrix(int array[3][3], short Rows, short Cols) {

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < Cols; j++)
		{
			cout << setw(3) << array[i][j] << "     ";
		}
		cout << endl;
	}
}

int SumOneCol(int array[3][3], short Rows, short ColIndex) {

	int sum = 0;
	for (int i = 0; i < Rows; i++)
	{
		sum += array[i][ColIndex];
	}

	return sum;
}

void PrintEachColSum(int array[3][3], short Rows, short Cols) {


	for (int j = 0; j < Cols; j++)
	{

		cout << "\nCol " << j + 1 << " Sum = " <<
			SumOneCol(array, Rows , j);
	}
	
}


int main()
{

    srand((unsigned)time(NULL));
	int array[3][3];

	FillMatrixWithRandomNumber(array,3 , 3);

	cout << "\nThe following is a 3x3 random matrix: \n";
	PrintMatrix(array, 3, 3);


	cout << "\nThe following are the sum of each Column in the matrix: \n";

	PrintEachColSum(array, 3, 3);

   
}

