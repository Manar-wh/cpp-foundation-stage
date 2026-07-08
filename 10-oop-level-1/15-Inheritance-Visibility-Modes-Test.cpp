#include <iostream>
using namespace std;

class clsA {
private:
	int x = 4;
	int multiply() { return x * 5; } // Inaccessible outside clsA

protected:
	int y = 5;
	int adding() { return y + 100; } // Accessible to derived classes only

public:
	int z = 19;
	int subtract() { return z - 10; }
};

// Protected inheritance: public and protected members of clsA become protected in clsB
class clsB : protected clsA {
	int c = 0;
public:
	int a = 5;
};

// Protected inheritance: can still access inherited protected members from clsB
class clsC : protected clsB {
public:
	void func3() {
		// adding() is still protected and accessible within the hierarchy
		int Sum = clsB::adding() + clsB::a;
		cout << Sum << "\n";
	}

	void func4() {
		// subtract() became protected in clsB, so it is accessible here
		cout << clsB::subtract() << "\n";
	}
};

int main() {
	clsC C1;
	C1.func3(); // Prints 110
	C1.func4(); // Prints 9

	// C1.subtract(); ❌ Error: Protected members cannot be accessed directly from main()

	return 0;
}
