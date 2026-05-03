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

string Replacewords(string s, string TheWord, string Replaceto) {

	int pos = 0;

	while ((pos = s.find(TheWord)) != std::string::npos) {

		s.replace(pos, TheWord.length(), Replaceto);
		pos = s.find(TheWord, pos + Replaceto.length());
	}

	return s;
}

int main() {

	string s = "Welcome to Saudi, Saudi is a nice place";
	cout << s << "\n";
	cout << Replacewords(s, "Saudi", "Saudi Arabia") << "\n";
}
