#include <iostream>
using namespace std;

class clsA {
private:
	int x=4;
	int multiply() {
		return x * 5;
	}
protected:
	int y=5;
	int adding() {
		return y + 100;
	}
public:
	int z = 19;
	int subtract() {
		return z - 10;
	}
};

class clsB : public clsA {
	int c = 4;

public:
	void Adding() {

		cout << clsA::adding() +c ;
	}
};

int main() {

	clsB B;
	B.Adding();
	
	return 0;
}
