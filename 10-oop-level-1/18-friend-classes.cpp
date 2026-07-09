#include <iostream>
using namespace std;

class clsA {

	int _Var1;

protected:

	int Var2;

public:
	int Var3;

	clsA()
	{
		_Var1 = 9;
		Var2 = 10;
		Var3 = 5;
	}
	
	friend class clsB;
};

class clsB {

public:

	void Display(clsA A) {
		cout << "The value of Var1 = " << A._Var1 << "\n";
		cout << "The value of Var2 = " << A.Var2 << "\n";
		cout << "The value of Var3 = " << A.Var3 << "\n";
	}
};

int main() {

	clsA A1;
	clsB B1;
	B1.Display(A1);

	return 0;
}
