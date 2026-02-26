#include <iostream>
using namespace std;


void fillarr3(int Arr1[5][5], int Arr2[5][5], int Arr3[5][5]) {

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Arr3[i][j] = Arr1[i][j] + Arr2[i][j];
		}
	}
}

void printarr3(int Arr3[5][5]) {

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int value = Arr3[i][j];

			if (value > 10)
			{
				value = 10;
			}

			printf("%0*d ", 2, value);
		}
		cout << endl;
	}
}


int main() {

	int Arr1[5][5]{
		{6,4,2,7,2},
		{3,5,1,6,4},
		{3,5,1,6,4},
		{4,6,2,4,5},
		{5,6,7,8,9}
	};

	int Arr2[5][5]{
		{6,4,2,7,2},
		{3,5,1,6,4},
		{3,5,1,6,4},
		{4,6,2,4,5},
		{5,6,7,8,9}
	};

	int Arr3[5][5];

	fillarr3(Arr1, Arr2, Arr3);
	printarr3(Arr3);
}
