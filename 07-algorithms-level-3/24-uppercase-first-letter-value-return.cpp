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

string ConvertFirstLetterToUpper(string Str) {

	bool IsFirstLetter = true;

	for (int i = 0; i < Str.length(); i++)
	{
		if (Str[i] != ' ' && IsFirstLetter == true )
		{
			Str[i]= toupper(Str[i]);
		}

		IsFirstLetter = (Str[i] == ' ' ? true : false);
	}

	return Str;
}

int main() {

	string Str;

	Str = ReadString();
	Str = ConvertFirstLetterToUpper(Str);
	cout << "\nString after conversion:\n" << Str << "\n";
	
}
