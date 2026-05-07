#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector <string> SplitString(string s, string delim) {

	int pos = 0;
	string sWord = "";
	vector <string> vword;

	while ((pos = s.find(delim)) != std::string::npos) {

		sWord = s.substr(0, pos);

		if (sWord != "")
		{
			vword.push_back(sWord);
		}
		s.erase(0, pos + delim.length());
	}

	if (s != "")
	{
		vword.push_back(s);

	}
	return vword;
}

string JoinString(vector<string> vString, string Delim) {

	string s = "";

	for (string& n : vString) {
		s = s + n + Delim;
	}

	return s.substr(0, s.length() - Delim.length());
}

string LowerAllString(string s) {

	for (int i = 0; i < s.length(); i++)
	{
		s[i] = tolower(s[i]);
	}

	return s;
}

string ReplaceWordInStringUsingSplit(string s1, string StringToReplace, string ReplaceTo, bool MatchCase = true) {

	vector <string> vWords;
	vWords = SplitString(s1, " ");

	for (string &s : vWords)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = ReplaceTo;
			}
		}
		else
		{
			if (LowerAllString(s) == LowerAllString(StringToReplace))
			{
				s = ReplaceTo;
			}
		}
	}

	return JoinString(vWords, " ");
}


int main() {

	string s = "Welcom to London , London is a nice city";
	vector <string> vWords;
	string StringToReplace = "London";
	string ReplaceTo = "Jeddah";

	cout << "\nOriginal String:\n" << s;

	
	cout << "\n\nReplace with match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(s, StringToReplace, ReplaceTo);

	cout << "\n\nReplace with dont match case: ";
	cout << "\n" << ReplaceWordInStringUsingSplit(s, StringToReplace, ReplaceTo, false) << "\n";


}
