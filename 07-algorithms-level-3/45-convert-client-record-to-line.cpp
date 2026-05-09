#include <iostream>
#include <string>

using namespace std;

struct stClintData {
	string AccountNumber;
	string PinCode;
	string Name;
	string phone;
	double AccountBalance = 0;
};

stClintData ReadData() {

	stClintData ClintData;

	cout << "Enter Account Number? ";
	getline(cin, ClintData.AccountNumber);

	cout << "Enter PinCode? ";
	getline(cin, ClintData.PinCode);
	
	cout << "Enter Name? ";
	getline(cin, ClintData.Name);

	cout << "Enter Phone? ";
	getline(cin, ClintData.phone);

	cout << "Enter AccountBalance? ";
	cin >> ClintData.AccountBalance;

	return ClintData;
}

string ConvertDataToOneLine(stClintData ClintData, string Seperator) {

	string ClientRecord = "";
	ClientRecord += ClintData.AccountNumber + Seperator;
	ClientRecord += ClintData.PinCode + Seperator;
	ClientRecord += ClintData.Name + Seperator;
	ClientRecord += ClintData.phone + Seperator;
	ClientRecord += to_string(ClintData.AccountBalance);

	return ClientRecord;
}

int main() {

	cout << "\nPlease Enter Client Data: \n\n";
	stClintData ClintData = ReadData();
	cout << "\n\nClient Record for Saving is: \n";
	cout << ConvertDataToOneLine(ClintData, "#//#");

}
