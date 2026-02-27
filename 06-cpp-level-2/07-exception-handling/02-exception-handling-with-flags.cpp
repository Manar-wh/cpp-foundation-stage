#include <iostream>
#include<vector>
using namespace std;

int main() {

	vector <int> vNum{ 65,87,3,2,7,6 };

	bool errorOccurred = false;   // Flag to check if an error occurs


	// Try to modify elements
	try
	{
		vNum.at(5) = 5;
		vNum.at(6) = 9; // This index does not exist → will throw an exception
	}
	catch (...)
	{
		errorOccurred = true; // Set the flag if any exception occurs
	}


	for (int &n : vNum)
	{
		cout << n << endl;
	}

	// Print error message if an exception happened

	if (errorOccurred == true)

	{
	   cout << "error happened\n"; 
	}

	return 0;
}
