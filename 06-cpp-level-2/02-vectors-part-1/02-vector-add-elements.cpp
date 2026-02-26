#include <iostream>
#include <vector>
using namespace std;


int main() {
 
	vector <int> vNumber;

	vNumber.push_back(9);
	vNumber.push_back(8);
	vNumber.push_back(7);
	vNumber.push_back(6);
	vNumber.push_back(5);
	vNumber.push_back(4);
	vNumber.push_back(3);
	vNumber.push_back(2);
	vNumber.push_back(1);


	for (int& n : vNumber) {
		printf("%0*d \n", 2, n);
	}

	return 0;
}
