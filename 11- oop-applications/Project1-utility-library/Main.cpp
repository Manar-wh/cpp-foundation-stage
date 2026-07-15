#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "clsUtil.h"
#include "clsStrings.h"
#include "clsDate.h"
int main()
{
	clsUtil::Srand();
	cout <<"Random Number:  "<< clsUtil::RandomNumber(1, 100) << "\n";
	cout <<"Random Character:  "<< clsUtil::GetRandomCharacter(clsUtil::enCharType::Mixchars) << "\n";
	cout <<"Random Word:  "<< clsUtil::GenerateWord(clsUtil::enCharType::Mixchars, 5) << "\n";
	cout <<"Random Key:  "<< clsUtil::GenerateKey(clsUtil::enCharType::Mixchars)<< "\n";
	cout << "Random Keys:  \n";
	clsUtil::GenerateKeys(clsUtil::enCharType::Mixchars, 5);

	cout << "\n";

	//swap int
	cout << "\nSwap int: \n";
	int x = 10, y = 20;
	cout << x << "  " << y << "\n";
	clsUtil::Swap(x, y);
	cout << x << "  " << y << "\n";

	//swap double
	cout << "\nSwap double: \n";
	double a = 5.5, b = 2.8;
	cout << a << "  " << b << "\n";
	clsUtil::Swap(a, b);
	cout << a << "  " << b << "\n";

	//swap string
	cout << "\nSwap string: \n";
	string S1 = "Ahmed", S2 = "Salem";
	cout << S1 << "  " << S2 << "\n";
	clsUtil::Swap(S1, S2);
	cout << S1 << "  " << S2 << "\n";

	//swap Dates
	cout << "\nSwap Dates: \n";
	clsDate D1(10, 10, 2025); clsDate D2(14, 4, 2026);
	cout << D1.DateToString() << "  " << D2.DateToString() << "\n";
	clsUtil::Swap(D1, D2);
	cout << D1.DateToString() << "  " << D2.DateToString() << "\n";

	//Shuffl Array
	
	//Int Array
	cout << "\nShuffl int Array:\n";
	int Arr1[5] = { 1,2,3,4,5 };
	clsUtil::ShuffleArray(Arr1, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << Arr1[i] << endl;
	}

	//String Array
	cout << "\nShuffl String Array:\n";
	string Arr2[5] = { "Ali", "Fadi", "Saeed", "Samer", "Ahmed"};
	clsUtil::ShuffleArray(Arr2, 5);
	for (int i = 0; i < 5; i++)
	{
		cout << Arr2[i] << endl;
	}

	int Arr3[3];
	clsUtil::FillArrayWithRandomNumbers(Arr3, 3, 10, 20);
	cout << "\nArray After Fill with random numbers: \n";
	for (short i = 0; i < 3; i++)
	{
		cout << Arr3[i] << "\n";
	}

	string Arr4[3];
	clsUtil::FillArrayWithRandomWords(Arr4, 3, clsUtil::enCharType::SmallLetter, 5);
	cout << "\nArray After Fill with random words: \n";
	for (short i = 0; i < 3; i++)
	{
		cout << Arr4[i] << "\n";
	}

	string Arr5[3];
	clsUtil::FillArrayWithRandomKeys(Arr5, 3, clsUtil::enCharType::Mixchars);
	cout << "\nArray After Fill with random Keys: \n";
	for (short i = 0; i < 3; i++)
	{
		cout << Arr5[i] << "\n";
	}

	cout << "\nText1" << clsUtil::Taps(5) << "Text2\n";

	const short EncrypionKey = 2;
	string Text = "Manar Alwahedi";
	string TextAfterEncryption = clsUtil::EncryptText(Text, EncrypionKey);
	string TextAfterDecryption = clsUtil::DecryptionText(TextAfterEncryption, EncrypionKey);

	cout << "\nText Befor Encryption= " << Text << "\n";
	cout << "Text After Encryption= " << TextAfterEncryption << "\n";
	cout << "Text After Decryption= " << TextAfterDecryption << "\n";

}
