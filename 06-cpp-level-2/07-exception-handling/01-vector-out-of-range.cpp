#include <iostream>
#include<vector>
using namespace std;

int main() {

	vector <int> vNum{ 65,87,3,2,7,6 };

	try
	{
		cout << vNum.at(6);
	}
	catch (...)	
	{
		cout << "OUT OF BOUND !!\n";
	}

	return 0;
}
