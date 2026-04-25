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

enum enWhatToCount { CapitalLetter = 0, SmallLetter = 1, all = 2 };

short CountLetters(string S, enWhatToCount WhatToCount) {

	short Counter = 0;

	if (WhatToCount == enWhatToCount::all)
	{
		return S.length();
	}

	for (short i = 0; i < S.length(); i++)
	{
		if (WhatToCount == enWhatToCount::CapitalLetter && isupper(S[i]))
		{
			Counter++;
		}
		else if (WhatToCount == enWhatToCount::SmallLetter && islower(S[i]))
		{
			Counter++;
		}
	}
	return Counter;
}

int main() {

	enWhatToCount WhatToCount;
	string S;
	S = ReadString();

	cout << "\nString length: " << CountLetters(S, enWhatToCount::all) << "\n";
	cout << "\nCapital letter count: " << CountLetters(S, enWhatToCount::CapitalLetter) << "\n";
	cout << "\nSmall letter count: " << CountLetters(S, enWhatToCount::SmallLetter) << "\n";
}
