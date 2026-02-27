#include <iostream>
#include<vector>
using namespace std;

//Vector Iterators

int main() {

	vector <int> num{ 5,8,6,9,3 };

	// declare iterator
	vector <int> ::iterator itr;

	for (itr = num.begin(); itr !=num.end(); itr++ )
	{
		cout << *itr << endl;
	}
		
}
