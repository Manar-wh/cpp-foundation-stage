#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to print the content of a file line by line

void PrintFileContenet(string FileName) {

    fstream MyFile;  // file object
    string Line;     // variable to store each line

    MyFile.open(FileName, ios::in); // open file in read mode

    if (MyFile.is_open()) 
    {
        // read the file line by line

        while (getline(MyFile, Line))
        {
            cout << Line << endl; // print each line
        }

        MyFile.close();
    }
}


int main()
{

    PrintFileContenet("f.txt");

    return 0;
}
