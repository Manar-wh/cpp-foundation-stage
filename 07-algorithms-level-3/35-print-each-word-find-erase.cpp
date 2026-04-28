#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string ReadString() {
    string s;
    cout << "Please Enter your string: " << endl;
    getline(cin >> ws, s);
    return s;
}

void PrintEachWord(string s) {

    string delim = " ";
    short pos = 0;
    string word = "";

    while ((pos = s.find(delim)) != std::string::npos)
    {
       word =  s.substr(0, pos);

       if (word != "")
       {
           cout << word << "\n";
       }

       s.erase(0, pos + delim.length());
    }

    if (s != " ")
    {
        cout << s << "\n";
    }

}

int main() {

    string s = ReadString();

    cout << "\nYour string words is: \n\n";
    PrintEachWord(s);


    return 0;
}
