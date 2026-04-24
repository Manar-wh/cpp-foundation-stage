#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ReadString() {
	string Str;
	cout << "Please Enter Your String : \n";
	getline(cin, Str);
	return Str;
}

string ConvertFirstLetterToLower(string Str) {

	bool IsFirstLetter = true;

	for (int i = 0; i < Str.length(); i++)
	{
		if (Str[i] != ' ' && IsFirstLetter == true )
		{
			Str[i]= tolower(Str[i]);
		}

		IsFirstLetter = (Str[i] == ' ');
	}

	return Str;
}

int main() {

	string Str;

	Str = ReadString();
	Str = ConvertFirstLetterToLower(Str);
	cout << "\nString after conversion:\n" << Str << "\n";
	
}
