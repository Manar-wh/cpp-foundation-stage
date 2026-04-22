#include <iostream>
using namespace std;

void PrintFebonacciUsingLoop(int Number) {

	int FebNum = 0;
	int Prev2 = 0;	int Prev1 = 1;
	cout << "1\t";

	for (int i = 2; i <= Number; i++)
	{
		FebNum = Prev2 + Prev1;
		cout << FebNum << "\t";
		Prev2 = Prev1;
		Prev1 = FebNum;
	}
}

int main() {

	PrintFebonacciUsingLoop(10);

}
