#include <iostream>
#include <string>
using namespace std;

string RemovePunctuationsFromString(string s) {

	string s2 = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (!ispunct(s[i]))
		{
			s2 += s[i];
		}
	}
	return s2;
}

int main() {

	string s = "Welcome to Saudi Arabia, Saudi Arabia is a nice country; it's amazing.";
	cout << "Original String:\n" << s;

	cout << "\n\nPauncuations Removed:\n" << RemovePunctuationsFromString(s) << "\n";

}
