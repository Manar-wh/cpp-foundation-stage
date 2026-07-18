#include <iostream>
using namespace std;
#include "clsBankClient.h"
int main()
{
	clsBankClient Client1 = clsBankClient::Find("A103");
	if (!(Client1.IsEmpty()))
	{
		cout << "\nClinet found ";
	}
	else
	{
		cout << "\nClinet not found ";
	}
	Client1.Print();

	clsBankClient Client2 = clsBankClient::Find("A101", "1234");
	if (!Client2.IsEmpty())
	{
		cout << "\nClient Found\n";
	}
	else
	{
		cout << "\nClient Was not Found ";
	}
	Client2.Print();

	cout << "\nIs Client Exist? " << clsBankClient::IsClientExsist("A300");
}
