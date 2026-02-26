#include <iostream>
#include<vector>
using namespace std;



int main() {

	vector <int> vNumbers;

	vNumbers.push_back(80);
	vNumbers.push_back(70);
	vNumbers.push_back(60);
	vNumbers.push_back(50);
	vNumbers.push_back(40);
	vNumbers.push_back(30);
	vNumbers.push_back(20);

	cout << "\nFirst Element: " << vNumbers.front();
	cout << "\nLast Element: " << vNumbers.back() ;

	//returns the number of elements present in the vector
	cout << "\nSize: " << vNumbers.size();

	//check the overall size of a vector
	cout << "\nCapacity: " << vNumbers.capacity();

	//returns 1 (true) if the vector is empty
	cout << "\nEmpty : " << vNumbers.empty() << endl;

	cout << "\n\n-------------------\n";

	// remove all elements from the vector
// the vector becomes empty but capacity remains the same
	vNumbers.clear();

	// returns 1 (true) because the vector is now empty
	cout << "\nEmpty : " << vNumbers.empty() << endl;

	// returns 0 because there are no elements
	cout << "\nSize: " << vNumbers.size()<< endl;

}
