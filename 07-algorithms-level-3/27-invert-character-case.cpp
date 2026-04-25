#include <iostream>
#include <string>
#include <cctype>
using namespace std;
 
char ReadChar() {
	char c;
	cout << "Please Enter your character: \n";
	cin >> c;
	return c;
}

char InvertLetterCase(char c) {

	return isupper(c) ? tolower(c) : toupper(c);
}

int main() {

	char c;
	c = ReadChar();

	cout << "\nChar after invert case: \n";

	c= InvertLetterCase(c);
	cout << c << "\n";
}
