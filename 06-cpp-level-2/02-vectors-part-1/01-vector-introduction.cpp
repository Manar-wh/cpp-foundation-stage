#include <iostream>
#include <vector>
using namespace std;


int main() {
 
	vector <int> vNumber = { 30,40,50,60 };

	//ranged loop

	for (int &n : vNumber) {
		cout << n << endl;
	}

	return 0;
}
