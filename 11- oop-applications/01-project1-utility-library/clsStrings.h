#include <iostream>
#include <vector>
using namespace std;
#pragma once

class clsStrings
{
private:
	string _Value;

	static char InvertLetterCase(char c) {
		return isupper(c) ? tolower(c) : toupper(c);
	}

	static bool IsVowel(char c) {
		c = tolower(c);
		return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}

public:
	enum enWhatToCount { CapitalLetter = 0, SmallLetter = 1, all = 2 };

	clsStrings() { _Value = ""; }
	clsStrings(string value) { _Value = value; }

	void setValue(string value) {
		_Value = value;
	}
	string getValue() {
		return _Value;
	}
	__declspec(property(get = getValue, put = setValue)) string Value;

	static short CountLetters(string S, enWhatToCount WhatToCount) {
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

	short CountLetters(enWhatToCount WhatToCount) {
		return CountLetters(_Value, WhatToCount);
	}

	static string ConvertFirstLettersToUpper(string Str) {
		bool IsFirstLetter = true;

		for (int i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && IsFirstLetter == true)
			{
				Str[i] = toupper(Str[i]);
			}

			IsFirstLetter = (Str[i] == ' ' ? true : false);
		}
		return Str;
	}

	void ConvertFirstLettersToUpper() {
		_Value = ConvertFirstLettersToUpper(_Value);
	}

	static string ConvertFirstLettersToLower(string Str) {
		bool IsFirstLetter = true;

		for (int i = 0; i < Str.length(); i++)
		{
			if (Str[i] != ' ' && IsFirstLetter == true)
			{
				Str[i] = tolower(Str[i]);
			}

			IsFirstLetter = (Str[i] == ' ');
		}
		return Str;
	}

	void ConvertFirstLettersToLower() {
		_Value = ConvertFirstLettersToLower(_Value);
	}

	static string ConvertAllLettersToUpper(string Str) {
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = toupper(Str[i]);
		}
		return Str;
	}

	void ConvertAllLettersToUpper() {
		_Value = ConvertAllLettersToUpper(_Value);
	}

	static string ConvertAllLettersToLower(string Str) {
		for (short i = 0; i < Str.length(); i++)
		{
			Str[i] = tolower(Str[i]);
		}
		return Str;
	}

	void ConvertAllLettersToLower() {
		_Value = ConvertAllLettersToLower(_Value);
	}

	static string InvertAllLettersCase(string S) {
		for (short i = 0; i < S.length(); i++)
		{
			S[i] = InvertLetterCase(S[i]);
		}
		return S;
	}

	void InvertAllLettersCase() {
		_Value = InvertAllLettersCase(_Value);
	}

	static short CountSpecificLetter(string s, char c, bool MatchCase = false) {
		short counter = 0;
		for (short i = 0; i < s.length(); i++) {
			if (MatchCase) {
				if (c == s[i]) counter++;
			}
			else {
				if (tolower(c) == tolower(s[i])) counter++;
			}
		}
		return counter;
	}

	short CountSpecificLetter(char c, bool MatchCase = false) {
		return CountSpecificLetter(_Value, c, MatchCase);
	}

	static int CountAllVowels(string s) {
		int counter = 0;
		for (int i = 0; i < s.length(); i++) {
			if (IsVowel(s[i])) {
				counter++;
			}
		}
		return counter;
	}

	int CountAllVowels() {
		return CountAllVowels(_Value);
	}

	static int CountWords(string s) {
		string delim = " ";
		short pos = 0;
		string word = "";
		int counter = 0;

		while ((pos = s.find(delim)) != std::string::npos)
		{
			word = s.substr(0, pos);

			if (word != "")
			{
				counter++;
			}

			s.erase(0, pos + delim.length());
		}
		if (s != "")
		{
			counter++;
		}
		return counter;
	}

	int CountWords() {
		return CountWords(_Value);
	}

	static vector <string> Split(string s, string delim) {
		short pos = 0;
		string word = "";
		vector<string> vwords;

		while ((pos = s.find(delim)) != std::string::npos)
		{
			word = s.substr(0, pos);

			if (word != "")
			{
				vwords.push_back(word);
			}

			s.erase(0, pos + delim.length());
		}

		if (s != "")
		{
			vwords.push_back(s);
		}
		return vwords;
	}

	vector <string> Split(string delim) {
		return Split(_Value, delim);
	}

	static string TrimLeft(string s) {
		for (short i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ')
			{
				return s.substr(i, s.length() - i);
			}
		}
		return "";
	}

	void TrimLeft() {
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string s) {
		for (short i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] != ' ')
			{
				return s.substr(0, i + 1);
			}
		}
		return "";
	}

	void TrimRight() {
		_Value = TrimRight(_Value);
	}

	static string Trim(string s) {
		return TrimLeft(TrimRight(s));
	}

	void Trim() {
		_Value = Trim(_Value);
	}

	static string Join(vector<string> vString, string delim) {
		string s = "";
		for (string& n : vString) {
			s = s + n + delim;
		}
		return s.substr(0, s.length() - delim.length());
	}

	static string ReverseWords(string s) {
		vector <string> vString;
		vString = Split(s, " ");

		vector <string> ::iterator iter = vString.end();
		string s2;

		while (iter != vString.begin()) {
			iter--;
			s2 += *iter + " ";
		}
		return s2.substr(0, s2.length() - 1);
	}

	void ReverseWords() {
		_Value = ReverseWords(_Value);
	}

	static string ReplaceWord(string s1, string StringToReplace, string ReplaceTo, bool MatchCase = false) {
		vector <string> vWords;
		vWords = Split(s1, " ");

		for (string& s : vWords)
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
				if (ConvertAllLettersToLower(s) == ConvertAllLettersToLower(StringToReplace))
				{
					s = ReplaceTo;
				}
			}
		}
		return Join(vWords, " ");
	}

	static string RemovePunctuations(string s) {
		string s2 = "";
		for (int i = 0; i < s.length(); i++)
		{
			if (!ispunct(s[i]))
			{
				s2 += s[i];
			}
		}
		return s2;
	}

	void RemovePunctuations() {
		_Value = RemovePunctuations(_Value);
	}
};
