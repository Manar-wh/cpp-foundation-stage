#include <iostream>
#include <string>
using namespace std;

string ReadString() {
	string Str;
	cout << "Please Enter Your String : \n";
	getline(cin, Str);
	return Str;
}

void PrintFirstLetter(string Str) {

	bool IsFirstLetter = true;

	for (int i = 0; i < Str.length(); i++)
	{
		if (Str[i] != ' ' && IsFirstLetter == true )
		{
			cout << Str[i] << endl;
		}

		IsFirstLetter = (Str[i] == ' ' ? true : false);
	}
}

int main() {

	PrintFirstLetter(ReadString());
}
