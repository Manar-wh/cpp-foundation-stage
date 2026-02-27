#include <iostream>
#include<vector>
using namespace std;


int main() {

	vector <int> vNum;

	// User inputs the numbers

	int length;
	cout << "How many Numbers do you want ? ";
	cin >> length;

	for (int i = 0; i < length; i++)
	{
		int num;	
		cout << "Number ["<< i << "] : ";
		cin >> num;
		vNum.push_back(num);
	}


	//Print all numbers after input

	cout << "\nNumbers you entered:\n";
	for (int& n : vNum) {

		cout << n << " ";
	}
	cout << "\n\n";


	// Let user try to modify elements

	bool errorOccurred = false;
	int index, newValue;

	cout << "Enter the index you want to modify (0-based): ";
	cin >> index;
	cout << "Enter the new value: ";
	cin >> newValue;

	try
	{
		vNum.at(index) = newValue;
	}
	catch(...)
	{
		errorOccurred = true; // Mark error if index is out of bound
	}

	// Print updated vector

	cout << "\n\nAfter updated:\n";

	for (int &n: vNum)
	{
		cout << n << " ";
	}

	if (errorOccurred == true)
	{
		cout << "Error: index out of bound!\n";
	}


	return 0;
}
