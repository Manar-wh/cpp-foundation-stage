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

int main() {

	vector <string> vString = { "Manar", "Sami", "Mohammed", "Lamia", "Ali" };

	cout << "Vector after join:\n";
	cout << JoinString(vString, "-");

}
