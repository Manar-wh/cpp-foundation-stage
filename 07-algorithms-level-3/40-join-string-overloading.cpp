#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;

string JoinString(vector <string> vString, string delim) {

	string s = "";

	for (string& n : vString) {

		s = s  + n + delim;
	}

	return s.substr(0, s.length() - delim.length());
}

string JoinString(string ArrJoin[], short length, string delim) {

	string s;

	for (int i = 0; i < length; i++)
	{
		s = s + ArrJoin[i] + delim;
	}

	return s.substr(0, s.length() - delim.length());
}

int main() {

	vector <string> vString = { "Manar", "Sami", "Mohammed", "Lamia"};
	string ArrJoin[4] = {"Software Engineer" , " Web Developer", "Data Scientist", "Data Scientist"};

	cout << "Vector after join:\n";
	cout << JoinString(vString, " - ");

	cout << "\nArray after join:\n";
	cout << JoinString(ArrJoin, 4 ," ^ ");
}
