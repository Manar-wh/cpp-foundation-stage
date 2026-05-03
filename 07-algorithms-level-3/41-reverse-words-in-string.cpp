#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

string ReadString() {
	string s;
	cout << "Enter your string: \n";
	getline(cin, s);
	return s;
}

vector <string> SplitString(string s, string delim) {

	vector <string> vString;
	string Words = "";
	short pos = 0;

	while ((pos = s.find(delim)) != std::string::npos)
	{
		Words = s.substr(0, pos);

		if (Words != "")
		{
			vString.push_back(Words);
		}

		s.erase(0, pos + delim.length());
	}

	if (s != "")
	{
		vString.push_back(s);
	}
	return vString;
}

string ReverseWordsInString(string s) {


	vector <string> vString;
	vString = SplitString(s, " ");

	vector <string> ::iterator iter = vString.end();
	string s2;

	while (iter != vString.begin()) {
		
		iter--;
		s2 += *iter + " ";
	}

	return s2.substr(0, s2.length() - 1);
}

int main() {

	string s = ReadString();
	cout << "\nString after reverse: \n";
	cout << ReverseWordsInString(s);

}
