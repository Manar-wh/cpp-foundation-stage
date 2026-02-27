#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// This function adds a new line at the end of the file

void AppendToFile(string FileName) {

    fstream MyFile;

    // Open file in append mode (add without deleting old content)
    MyFile.open(FileName, ios::app);

    if (MyFile.is_open())
    {
        // Write a new line to the file
        MyFile << "You Can Do It!" << endl;

        // Always close the file after finishing
        MyFile.close();
    }
}

// This function reads all lines from file
// and stores them inside a vector
void LoadDataFromFileToVector(string FileName, vector<string>& vFilecontent) {

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        // Read file line by line until end of file
        while (getline(MyFile, Line))
        {
            vFilecontent.push_back(Line);  // Add each line to the vector

        }

        MyFile.close();
    }
}

int main()
{

    vector<string> vFilecontent;

    AppendToFile("Message To Manar.txt");

    LoadDataFromFileToVector("Message To Manar.txt", vFilecontent);

    for (string& L : vFilecontent) {

        cout << L << endl;
    }

    return 0;
}
