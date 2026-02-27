#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	fstream File;

	// This program opens a file "f.txt" in append mode and writes two lines into it

	File.open("f.txt", ios::out | ios::app);

	if (File.is_open()) {

		File << "First line" << endl;
		File << "Second line" << endl;

		File.close();
	}

	return 0;
}
