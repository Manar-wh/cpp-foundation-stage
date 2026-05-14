#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClintData {
	string AccountNumber;
	string PinCode;
	string Name;
	string phone;
	double AccountBalance = 0;
	bool MarkClientForDelet = false;
};

vector <string> SplitString(string s, string delim) {

	int pos = 0;
	string Word;
	vector <string> vWords;
	while ((pos = s.find(delim)) != std::string::npos) {

		Word = s.substr(0, pos);

		if (Word != "")
		{
			vWords.push_back(Word);
		}
		s.erase(0, pos + delim.length());
	}
	if (s != "")
	{
		vWords.push_back(s);
	}
	return vWords;
}

stClintData ConvertLinetoRecord(string Line, string delim = "#//#") {

	vector <string> vWords;
	vWords = SplitString(Line, delim);
	stClintData Client;

	Client.AccountNumber = vWords[0];
	Client.PinCode = vWords[1];
	Client.Name = vWords[2];
	Client.phone = vWords[3];
	Client.AccountBalance = stod(vWords[4]);
	return Client;
}

vector <stClintData> LoadDataFromFile(string FileName) {

	vector <stClintData> vClientsData;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClintData Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClientsData.push_back(Client);
		}
	}
	MyFile.close();
	return vClientsData;
}

string FindClientByAccountNumber() {

	string AccountNumber = "";
	cout << "Please enter the AccountNumber: ";
	cin >> AccountNumber;
	return AccountNumber;
}

bool IsGetClient(vector <stClintData> vClientsData, stClintData& Client , string AccountNumber) {
		
	for (stClintData& c : vClientsData) {

		if (AccountNumber == c.AccountNumber)
		{
			Client = c;
			return true;
		}
	}

	return false;
}

void PrintClientCard(stClintData& Client) {

	cout << "\nThe following are the client details:\n";
	cout << "\nAccout Number: " << Client.AccountNumber;
	cout << "\nPin Code : " << Client.PinCode;
	cout << "\nName : " << Client.Name;
	cout << "\nPhone : " << Client.phone;
	cout << "\nAccount Balance: " << Client.AccountBalance;

}

bool MarkClientForDeletByAccountNumber(vector <stClintData>& vClientsData, string AccountNumber) {

	for (stClintData &s : vClientsData)
	{
		if (s.AccountNumber == AccountNumber)
		{
			s.MarkClientForDelet = true;
			return true;
		}
	}

	return false;
}

string ConvertRecordToOneLine(stClintData& Client, string delim = "#//#") {

	string s = "";

	s += Client.AccountNumber + delim;
	s += Client.PinCode + delim;
	s += Client.Name + delim;
	s += Client.phone + delim;
	s += to_string(Client.AccountBalance);
	return s;
}

void FillFileAfterDelet( vector <stClintData>& vClientsData, string FileName ) {

	string Line = "";

	fstream MyFile;
	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (stClintData& s : vClientsData)
		{
			if (s.MarkClientForDelet == false) {

				Line = ConvertRecordToOneLine(s);
				MyFile << Line << "\n";
			}
		}
	}
	MyFile.close();
}

 bool DeletClientFromFile(vector <stClintData>& vClientsData, string AccountNumber , string FileName= ClientsFileName) {

	stClintData Client;

	if (IsGetClient(vClientsData, Client, AccountNumber))
	{
		PrintClientCard(Client);

		char DeletClient = 'Y';
		cout << "\nAre you sure you want to delet this client? [Y,N]";
		cin >> DeletClient;

		if (toupper(DeletClient) == 'Y')
		{
		MarkClientForDeletByAccountNumber(vClientsData, AccountNumber);
		FillFileAfterDelet(vClientsData, FileName);
		vClientsData = LoadDataFromFile(FileName);
		cout << "\nClient deleted successfully";
		return true;
		}
	}
	else
		cout << "\nClient " << AccountNumber << " is NOT found!";
	return false;
}

int main() {

	vector <stClintData> vClientsData;
	stClintData Client;

	vClientsData = LoadDataFromFile(ClientsFileName);
	
	string AccountNumber = FindClientByAccountNumber();

	DeletClientFromFile(vClientsData, AccountNumber);

}
