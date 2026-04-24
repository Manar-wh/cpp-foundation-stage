#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString() {
	string Str;
	cout << "Please Enter your string: \n";
	getline(cin, Str);
	return Str;
}

string ConvertAllLetterToUpper(string Str) {

	for (short i = 0; i < Str.length(); i++)
	{
		Str[i] = toupper(Str[i]);
	}
	return Str;
}

string ConvertAllLetterToLower(string Str) {

	for (short i = 0; i < Str.length(); i++)
	{
		Str[i] = tolower(Str[i]);
	}
	return Str;
}

int main() {
	string Str;
	Str = ReadString();

	cout << "\nYour string with Upper letter: \n";
	Str = ConvertAllLetterToUpper(Str);
	cout << Str << endl;

	cout << "\nYour string with Lower letter: \n";
	Str = ConvertAllLetterToLower(Str);
	cout << Str << endl;

}
