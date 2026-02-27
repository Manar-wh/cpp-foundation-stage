#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


// This program saves a list of names from a vector into a text file.

void SaveVectorToFile(string FileName, vector <string>& vFilecontent) {

    fstream File;

    File.open(FileName, ios::out);

    if (File.is_open())
    {

        for (string &line: vFilecontent)
        {
            if (line != "")
            {
                File << line << endl;

            }
        }

        File.close();
    }
}

int main()
{
   
    vector <string> vFilecontent{ "Manar", "Lama", "Sara", "Ahmed", "Sami"};

    fstream File;

    SaveVectorToFile("Names.txt", vFilecontent);
  
    return 0;
}
