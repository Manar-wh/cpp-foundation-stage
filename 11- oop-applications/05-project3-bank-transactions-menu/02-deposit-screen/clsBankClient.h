#pragma once
#include <iostream>
using namespace std;
#include "clsPerson.h"
#include "clsStrings.h"
#include <string>
#include <fstream>
class clsBankClient : public clsPerson
{
	enum enMode{EmptyMode= 0, UpdateMode = 1, AddNewClientMode = 2};
	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;
	bool _IsMarkToDelete = false;

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
		Line += to_string(Client.AccountBalance) + Delim;
		return Line;
	}

	static vector <clsBankClient> _LoadDataFromFileToVector() {
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

	void _Update() {
		vector <clsBankClient> vAllVector;
		vAllVector = _LoadDataFromFileToVector();
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);
		if (MyFile.is_open())
		{
			for (clsBankClient& C : vAllVector)
			{
				if (C.AccountNumber == _AccountNumber)
				{
					C = *this;
				}
				MyFile << _ConvertObjectToLine(C) << endl;
			}
			MyFile.close();
		}
	}

	void AddNewClient() {
		_AddDataLineToFile(_ConvertObjectToLine(*this));
	}

	void _AddDataLineToFile(string DataLine) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::app);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	void _SaveDataToFile(vector <clsBankClient> vAllClients) {

		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			for (clsBankClient& C : vAllClients)
			{
				if (C._IsMarkToDelete == false)
				{
					MyFile << _ConvertObjectToLine(C) << endl;
				}
			}
			MyFile.close();
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

 enum enSaveResult{svFailedEmptyObject = 0 , svSucceeded =1, svFailedAccountNumberExist = 2};

	enSaveResult Save() {
		switch (_Mode)
		{
		case enMode::EmptyMode:

			return enSaveResult::svFailedEmptyObject;
			

		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceeded;

		case enMode::AddNewClientMode:

			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResult::svFailedAccountNumberExist;
			}
			else
			{
				AddNewClient();
				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}

		default:
			break;
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber) {
		return clsBankClient(enMode::AddNewClientMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete() {
		vector <clsBankClient> vAllClients;
		vAllClients = _LoadDataFromFileToVector();

		for (clsBankClient& C : vAllClients)
		{
			if (C.AccountNumber == _AccountNumber)
			{
				C._IsMarkToDelete = true;
				break;
			}
		}
		_SaveDataToFile(vAllClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector <clsBankClient> GetClientsList() {

		return _LoadDataFromFileToVector();
	}

	static double GetTotalBalances() {
		vector <clsBankClient> vAllClients = GetClientsList();
		double TotalB = 0;
		for (clsBankClient& C : vAllClients) {
			TotalB += C.AccountBalance;
		}
		return TotalB;
	}

	void Deposit(double Amount) {
		_AccountBalance += Amount;
		Save();
	}
};

