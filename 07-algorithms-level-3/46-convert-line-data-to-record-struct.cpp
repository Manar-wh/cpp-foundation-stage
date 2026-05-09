#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stClintData {
	string AccountNumber;
	string PinCode;
	string Name;
	string phone;
	double AccountBalance = 0;
};

vector <string> SplitString(string s, string delim) {

	vector <string> vWord;
	int pos = 0;
	string word = "";
	while ((pos = s.find(delim)) != std::string::npos)
	{
		word = s.substr(0, pos );

		if (word != "")
		{
			vWord.push_back(word);
		}
		s.erase(0, pos + delim.length());
	}

	if (s != "")
	{
		vWord.push_back(s);
	}
	return vWord;
}

stClintData SaveDataInStruct(string s , string delim= "#//#") {
	vector <string> vWord;
	vWord = SplitString(s, delim);
	stClintData clint;

	clint.AccountNumber = vWord[0] ;
	clint.PinCode = vWord[1] ;
	clint.Name = vWord[2]  ;
	clint.phone = vWord[3]  ;
	clint.AccountBalance = stod(vWord[4]);
	return clint;
}

void PrintRecordClint(stClintData clint) {

	cout << "\n\nThe following is the extracted client record:\n";
	cout << "AccountNumber : " << clint.AccountNumber << "\n";
	cout << "PinCode       : " << clint.PinCode << "\n";
	cout << "Name          : " << clint.Name << "\n";
	cout << "phone         : " << clint.phone << "\n";
	cout << "AccountBalance: " << clint.AccountBalance << "\n";
}

int main() {

	string s = "A150#//#1234#//#Manar Alwahedi#//#079999#//#5270.000000";
	stClintData clint;
	clint = SaveDataInStruct(s);
	PrintRecordClint(clint);

}
