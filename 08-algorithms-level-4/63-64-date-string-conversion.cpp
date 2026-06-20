#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct stDate {
	short Day;
	short Month;
	short Year;
};

vector <string> SplitString(string S1, char Delim) {
	int pos = 0; string Word = ""; vector <string> vWords;
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		Word = S1.substr(0, pos);

		if (Word != "")
		{
			vWords.push_back(Word);

		}
		S1.erase(0, pos + 1);
	}

	if (S1 != "")
	{
		vWords.push_back(S1);
	}
	return vWords;
}

stDate StringToDate(string DateString) {
	stDate Date;
	vector <string> vWords;
	vWords = SplitString(DateString, '/');

		Date.Day = stoi(vWords[0]);
		Date.Month = stoi(vWords[1]);
		Date.Year = stoi(vWords[2]);
		return Date;
}

string DateToString(stDate Date) {
	string Words;
	Words = to_string(Date.Day)+'/'+ to_string(Date.Month) + '/' + to_string(Date.Year);
	return Words;
}

string ReadStringDate(string Message)
{
	string DateString;
	cout << Message;
	getline(cin >> ws, DateString);
	return DateString;
}

int main() {

	stDate Date;

	string DateString = ReadStringDate("\nPlease Enter Date dd / mm / yyyy ? ");

	Date = StringToDate(DateString);
	cout << "Day: " << Date.Day << "\n" << "Month: " << Date.Month << "\n" << "Year: " << Date.Year << "\n";
	cout << "\nYou Enterd: " << DateToString(Date);

	system("pause > 0");
	return 0;
}
