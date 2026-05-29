#include <iostream>
#include <string>
using namespace std;

long long ReadNumber() {
	long long Number;
	cout << "Please enter your number? ";
	cin >> Number;
	return Number;
}

string NumberToText(long long Number) {

	if (Number == 0)
	{
		return "";
	}

	if (Number >= 1 && Number <= 19)
	{
		string Arr[]= {"", "One","Two","Three","Four","Five","Six","Seven",
					"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
					"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
		return Arr[Number] + " ";
	}

	if (Number >= 20 && Number <= 99)
	{
		string Arr[] = { "", "","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
		return Arr[Number / 10] + " " + NumberToText(Number % 10);
	}

	if (Number >= 100 && Number <= 999)
	{
		return NumberToText(Number / 100) + "Hundred " + NumberToText(Number % 100);
	}

	if (Number >= 1000 && Number <= 999999)
	{
		return NumberToText(Number / 1000) + "Thousand " + NumberToText(Number % 1000);
	}
	if (Number >= 1000000 && Number <= 999999999) {

		return NumberToText(Number / 1000000) + "Million " + NumberToText(Number % 1000000);
	}
	if (Number >= 1000000000 && Number <= 999999999999)
	{
		return NumberToText(Number / 1000000000) + "Billion " + NumberToText(Number % 1000000000);
	}
	else
	{
		return "\nNumber Is Too Long";
	}
}


int main()
{
	long long Number;
	Number = ReadNumber();
	cout << NumberToText(Number);
}
