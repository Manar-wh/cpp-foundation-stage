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

char Readchar() {
	char c;
	cout << "\nPlease Enter your a charecter: \n";
	cin >> c;
	return c;
}

short HowManyLetter(string s, char c) {

	short counter=0;

	for (short i = 0; i < s.length(); i++)
	{
		if (c == s[i])
		{
			counter++;
		}
	}

	return counter;
}

int main() {

	string S;
	char c;
	short counter = 0;

	S = ReadString();
	c = Readchar();

	cout << "\nLetter " << c << " count= " << HowManyLetter(S, c) << "\n";

}
