#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;


string ReadString() {
    string s;
    cout << "Please Enter your String: " << endl;
    getline(cin >> ws, s);
    return s;
}

vector <string> SplitString(string s, string delim) {

    short pos = 0;
    string word = "";

    vector<string>vwords;

    while ((pos = s.find(delim)) != std::string::npos)
    {
       word =  s.substr(0, pos);

       if (word != "")
       {
           vwords.push_back(word);
       }

       s.erase(0, pos + delim.length());
    }

    if (s != "")
    {
        vwords.push_back(s);
    }
    return vwords;
}

int main() {

    string s = ReadString();
    vector<string>vwords;

    vwords = SplitString(s," ");
    cout << "\nTokens: " << vwords.size() << "\n";
    
    for (string& n : vwords) {

        cout << n << "\n";
    }

    return 0;
}
