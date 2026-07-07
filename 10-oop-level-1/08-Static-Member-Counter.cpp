#include <iostream>
using namespace std;

class clsA
{
public:
	int v;
	static int Counter;

	clsA(){
		Counter++;	
	}
	void PrintResult() {
		cout << "Varable= " << v << "\n";
		cout << "Counter= " << Counter << "\n";
	}
};

int clsA::Counter = 0;

int main() {
   
	clsA A1, A2, A3;

	A1.v = 10;
	A2.v = 30;
	A3.v = 50;

	A1.PrintResult();
	A2.PrintResult();
	A3.PrintResult();

	A1.Counter = 990;
	cout << "\nafter chaning the static member counter in oneobject:\n";
	A1.PrintResult();
	A2.PrintResult();
	A3.PrintResult();
}
