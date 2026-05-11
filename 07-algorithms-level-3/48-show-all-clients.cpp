#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;

const string ClientsFileName = "Clients.txt";

struct stClintData {
	string AccountNumber;
	string PinCode;
	string Name;
	string phone;
	double AccountBalance = 0;
};

vector<string> SplitString(string S1, string Delim)
{
	vector<string> vString;
	short pos = 0;
	string sWord; 

	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S1.erase(0, pos + Delim.length());
	}
	if (S1 != "")
	{
		vString.push_back(S1); 
	}
	return vString;
}

stClintData ConvertLineToRecord(string Line, string Seperator ="#//#") {

	stClintData Client;
	vector <string> vClient;
	vClient = SplitString(Line, Seperator);

	Client.AccountNumber = vClient[0];
	Client.PinCode = vClient[1];
	Client.Name = vClient[2];
	Client.phone = vClient[3];
	Client.AccountBalance = stod(vClient[4]);
	return Client;
}

vector <stClintData> LoadClientsDataFromFile(string FileName) {

	vector <stClintData> vClientsInfo;
	fstream MyFile;
	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line;
		stClintData Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClientsInfo.push_back(Client);
		}
		MyFile.close();
	}
	return vClientsInfo;
}
void PrintClientData(stClintData c) {

	
	cout << "|" << setw(15) << left << c.AccountNumber;
	cout << "|" << setw(12) << left << c.PinCode;
	cout << "|" << setw(40) << left << c.Name;
	cout << "|" << setw(15) << left << c.phone;
	cout << "|" << setw(12) << left << c.AccountBalance;

}
void PrintAllClientsData(vector <stClintData>& vClientsInfo) {

	cout << "\t\t\t\tClient List (" << vClientsInfo.size() << ") Client(s).\n";
	cout << "\n-------------------------------------------------------------------------------------------------------------------\n\n";
	cout << "|" << setw(15) << left << " Account Number ";
	cout << "|" << setw(12) << left << " Pin Code ";
	cout << "|" << setw(40) << left << " Client Name ";
	cout << "|" << setw(15) << left << " Phone " ;
	cout << "|" << setw(12) << left << " Balence ";
	cout << "\n-------------------------------------------------------------------------------------------------------------------\n\n";

	for (stClintData& C : vClientsInfo) {

		PrintClientData(C);
		cout << "\n";
	}
	cout << "\n-------------------------------------------------------------------------------------------------------------------\n\n";

}


int main() {

	vector <stClintData> vClients;
	vClients = LoadClientsDataFromFile(ClientsFileName);
	PrintAllClientsData(vClients);

}
