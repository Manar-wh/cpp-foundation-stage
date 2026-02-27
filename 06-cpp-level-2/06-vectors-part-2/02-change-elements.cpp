#include <iostream>
#include<vector>
using namespace std;

//Change Elements

int main() {

	vector <int> num{ 8,4,2,7,3,1 };

	cout << "Initial Vector: ";

	for (const int &n : num)
	{
		cout << n << " ";
	}

	cout << "\n\nUpdated Vector: ";

	for (int& n : num)
	{
		n = 2;
		cout << n << " ";
	}

	cout << "\n\nUpdated Vector: ";

	num[0] = 27;
	num.at(1) = 18;
	num.at(2) = 9;
	num.at(3) = 33;

	for (const int &n: num)
	{
		cout << n << " ";
	}

}
