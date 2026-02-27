#include <iostream>
#include <string>
using namespace std;


int main() {


	string s1 = "My Name is Manar Alwahedi. ";

	//Prints the length of the string	
	cout << s1.length() << endl;

	//Returns the letter at position 11
	cout << s1.at(11) << endl;

	//Adds to the end of string
	s1.append("I LOVE PROGRAMMING.");
	cout << s1 << endl;

	//inserts Full at position 3
	s1.insert(3, "Full ");
	cout << s1 << endl ;	

	//Prints all the next 5 letters from position 16.
	cout << s1.substr(16, 5) << endl;

	//Adds one character to the end of the string
	s1.push_back('b');
	cout << s1 << endl;

	//Removes one character from the end of the string
	s1.pop_back();
	cout << s1 << endl;

	//Finds LOVE in the string
	cout << s1.find("LOVE") << endl;

	//Finds love in the string
	cout << s1.find("love") << endl;

	if (s1.find("love") == s1.npos)
	{
		cout << "love is not found";
	}

	//clears all string letters.
	s1.clear();

	cout << s1 << endl;

	return 0;
}
