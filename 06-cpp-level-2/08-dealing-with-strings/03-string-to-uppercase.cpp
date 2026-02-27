#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{

	string Name = "manar";

	for (int i = 0; i < Name.length(); i++)
	{
		Name.at(i) = toupper(Name.at(i));
	}

	cout << Name << endl;

	return 0;
}
