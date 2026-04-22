#include <iostream>
using namespace std;

void PrintFebonacciUsingRecursion(int Number, int Prev2, int Prev1) {

	int FebNum = 0;

	if (Number > 0)
	{
		cout << Prev1 << "\t";
		FebNum = Prev2 + Prev1;
		Prev2 = Prev1;
		Prev1 = FebNum;

		PrintFebonacciUsingRecursion(Number-1, Prev2, Prev1);
	}
}

int main() {

	PrintFebonacciUsingRecursion(10,0,1);

}
