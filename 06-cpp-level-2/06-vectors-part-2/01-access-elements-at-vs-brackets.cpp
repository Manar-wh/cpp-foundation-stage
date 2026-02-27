
#include <iostream>
#include<vector>
using namespace std;


int main() {

	vector <int> num{ 8,4,2,7,3,1 };

	cout << "Print Vector using at.[i]\n";

	cout << "Element at index[0]: " << num.at(0) << endl;
	cout << "Element at index[1]: " << num.at(1) << endl;
	cout << "Element at index[2]: " << num.at(2) << endl;
	cout << "Element at index[3]: " << num.at(3) << endl;
	cout << "Element at index[4]: " << num.at(4) << endl;
	cout << "Element at index[5]: " << num.at(5) << endl;


	cout << "\n\nPrint Vector using [i]\n";

	cout << "Element at index[0]: " << num[0] << endl;
	cout << "Element at index[1]: " << num[1] << endl;
	cout << "Element at index[2]: " << num[2] << endl;
	cout << "Element at index[3]: " << num[3] << endl;
	cout << "Element at index[4]: " << num[4] << endl;
	cout << "Element at index[5]: " << num[5] << endl;

	}
