#pragma once
#include <iostream>
#include "clsStrings.h"
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
	static void Srand() {
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int RandNum = rand() % (To - From + 1) + From;
		return RandNum; 
	}

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, Mixchars = 4, SpecialCharacter = 5};

	static char GetRandomCharacter(enCharType CharType)
	{
		if (CharType == enCharType::Mixchars)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n
			break;
		}
		case enCharType::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}
		case enCharType::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}
		case enCharType::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}
		}
	}

	static string GenerateWord(enCharType CharType, short Length)
	{
		if (CharType == enCharType::Mixchars)
		{
			CharType = (enCharType)RandomNumber(1, 4);
		}
		string Word;
		for (int i = 1; i <= Length; i++) // 1 <= 4 ? | 2 <= 4 ...
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}

	static string GenerateKey(enCharType CharType)
	{
		string Key = "";
		Key = GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4) + "-";
		Key = Key + GenerateWord(CharType, 4);
		return Key;
	}

	static void GenerateKeys(enCharType CharType, short NumberOfKeys)
	{

		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenerateKey(CharType) << endl;
		}
	}

	static void Swap(int& Num1, int& Num2) {
		int TempDate = Num1;
		Num1 = Num2;
		Num2 = TempDate;
	}

	static void Swap(string& S1, string& S2) {
		string TempDate = S1;
		S1 = S2;
		S2 = TempDate;
	}

	static void Swap(double& Num1, double& Num2) {
		double TempDate = Num1;
		Num1 = Num2;
		Num2 = TempDate;
	}

	static void Swap(clsDate& D1, clsDate& D2) {
		clsDate TempDate = D1;
		D1 = D2;
		D2 = TempDate;
	}

	static void FillArrayWithRandomNumbers(int arr[100], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++) 
			arr[i] = RandomNumber(From, To);
	}

	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType Type, int LengthOfTheWord)
	{
		for (int i = 0; i < arrLength; i++) {
			string Word = GenerateWord(Type, LengthOfTheWord);
			arr[i] = Word;
		}
	}

	static void FillArrayWithRandomKeys(string arr[100], int NumberOfKey, enCharType Type )
	{
		for (int i = 0; i < NumberOfKey; i++) {
			arr[i] = GenerateKey(Type);
		}
	}

	static string Taps(int length) {
		string T = "";
		for (int i = 0; i < length; i++)
		{
			T += "\t";
		}
		return T;
	}

	static void ShuffleArray(int arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
		 clsUtil::Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void ShuffleArray(string arr[100], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			clsUtil::Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static string EncryptText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{ 
			Text[i] = char((int)Text[i] + EncryptionKey);
		}
		return Text; 
	}

	static string DecryptionText(string Text, short EncryptionKey)
	{
		for (int i = 0; i < Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
		}
		return Text;
	}

};

