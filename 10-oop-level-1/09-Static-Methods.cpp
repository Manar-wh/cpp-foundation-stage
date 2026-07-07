#include <iostream>
using namespace std;

class clsA
{
public:
	
	static int Func1() {
		return 80;
	}

};

int main() {  
	clsA A1;
	/*The following line calls static function directly via classnot through the object
	At class level you can call only static methods and static members*/

	cout << clsA::Func1()<< "\n";

	//static methods can also be called throught the object
	cout << A1.Func1() <<"\n";
}
