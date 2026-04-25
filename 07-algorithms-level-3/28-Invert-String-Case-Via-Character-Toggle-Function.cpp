#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString() {
	string S;
	cout << "Please Enter your string: \n";
	getline(cin, S);
	return S;
}

char InvertLetterCase(char c) {

	return isupper(c) ? tolower(c) : toupper(c);
}

string InvertAllLetterCase(string S) {

	for (short i = 0; i < S.length(); i++)
	{
		
		S[i] = InvertLetterCase(S[i]);
	}
	return S;
}

int main() {

	string S;
	S = ReadString();
	cout << "\nString before invert case: \n";
	cout << S << "\n";

	cout << "\nString after invert case: \n";
	S = InvertAllLetterCase(S);
	cout << S << "\n";
}
