#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string ReadString() {
    string s;
    cout << "Please Enter your String: " << endl;
    getline(cin >> ws, s);
    return s;
}

int CountEachWordInString(string s) {

    string delim = " ";
    short pos = 0;
    string word = "";
    int counter = 0;

    while ((pos = s.find(delim)) != std::string::npos)
    {
       word =  s.substr(0, pos);

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

int main() {

    string s = ReadString();

    cout << "\nThe Number of Words in your string are: " << CountEachWordInString(s);
    
    return 0;
}
