#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

	//Some CCTYPE Functions

	char x = toupper('f');
	char y = tolower('B');

	cout << "convert letter to upper " << x << endl;
	cout << "convert letter to lower " << y << endl;
	
	// returns zero if not, and non zero of yes

	cout << "Is the letter capital?  " << isupper('A') << endl;

	cout << "Is the letter Small?  " << islower('A') << endl;

	cout << "isdigit('A')  " << isdigit('A') << endl;

	// punctuation characters are !"#$%&'()*+,-./:;<=>?@[\]^_`{|}~
	cout << "ispunct('A')  " << ispunct('A') << endl;


	return 0;
}
