#pragma once
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include "clsStrings.h"
#include <string>
#include <fstream>
class clsBankClient : public clsPerson
{
	enum enMode{EmptyMode= 0, UpdateMode = 1};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	static clsBankClient _convertLineToClientObject(string Line, string Seperator = "#//#") {
		vector <string> vAllClients;
		vAllClients = clsStrings::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vAllClients[0], vAllClients[1], vAllClients[2], 
			vAllClients[3], vAllClients[4], vAllClients[5], stof(vAllClients[6]));
	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	string _ConvertObjectToLine(clsBankClient Client,string Delim= "#//#") {
		string Line;
		Line += Client.FirstName + Delim;
		Line += Client.LastName + Delim;
		Line += Client.Email + Delim;
		Line += Client.Phone + Delim;
		Line += Client.AccountNumber + Delim;
		Line += Client.PinCode + Delim;
		Line += 
		Line += to_string(Client.AccountBalance) + Delim;
		return Line;
	}

	void _Update() {
		vector <clsBankClient> vAllVector;
		vAllVector = LoadDataFromFileToVector();
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vAllVector)
			{
				if (C.AccountNumber == AccountNumber)
				{
					C = *this;
				}
				MyFile << _ConvertObjectToLine(C) << endl;
			}
		}
	}

public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone , string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		 _Mode = Mode;
		 _AccountNumber = AccountNumber;
		 _PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	void setAccountNumber(string AccountNumber) {
		_AccountNumber = AccountNumber;
	}
	string getAccountNumber() {
		return _AccountNumber;
	}
	__declspec(property(get = getAccountNumber, put = setAccountNumber)) string AccountNumber;

	void setPinCode(string PinCode) {
		_PinCode = PinCode;
	}
	string getPinCode() {
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}
	float getAccountBalance() {
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc. Number : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient Find(string AccountNumber) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsBankClient Client = _convertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _convertLineToClientObject(Line);
				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	
	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	static bool IsClientExist(string AccountNumber) {
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static vector <clsBankClient> LoadDataFromFileToVector() {
		vector <clsBankClient> vAllClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _convertLineToClientObject(Line);

				vAllClients.push_back(Client);
				
			}
			MyFile.close();
		}
		return vAllClients;
	}

 enum enSaveResult{svFailedEmptyObject = 0 , svSucceeded =1};

	enSaveResult Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:
			return enSaveResult::svFailedEmptyObject;

		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;
		default:
			break;
		}
	}
};

