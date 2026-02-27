#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void LoadDataFromFileToVector(string FileName, vector <string>& vFilecontent) {

    fstream MyFile;

    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string line;

        while (getline(MyFile, line)) {
            vFilecontent.push_back(line);
        }
        MyFile.close();
    }
}

void SaveVectorToFile(string FileName, vector <string>& vFilecontent) {

    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {

        for (string& Line : vFilecontent) {

            if (Line != "")
            {
                MyFile << Line << endl;
            }
        }
        MyFile.close();
    }
}

void UpdateRecordFromFile(string FileName, string Record, string Update) {

    vector <string> vFilecontent;
    
    LoadDataFromFileToVector(FileName, vFilecontent);

    for (string &Line : vFilecontent)
    {
        if (Line == Record)
        {
            Line = Update;
        }

    }

    SaveVectorToFile(FileName, vFilecontent);
}

void PrintFileContent(string FileName) {

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;
        while (getline(MyFile, Line)) {

            if (Line != "")
            {
                cout << Line << endl;
            }
        }
        MyFile.close();
    }
}

int main()
{

    cout <<  "File Content Before Update.\n";
    PrintFileContent("Names.txt");

    UpdateRecordFromFile("Names.txt", "Ahmed", "Omar");


    cout << "\nFile Content After Update.\n";
    PrintFileContent("Names.txt");


    return 0;
}
