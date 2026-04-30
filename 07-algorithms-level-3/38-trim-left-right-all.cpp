#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string TirmFromLeft(string s) {

    for (short i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
           return s.substr(i, s.length() - i);
        }
    }
    return "";
}

string TirmFromRight(string s) {


    for (short i = s.length() - 1 ; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            return s.substr(0, i + 1);
        }
    }
    return "";
}

string Tirm(string s) {

    return TirmFromLeft(TirmFromRight(s));
}

int main() {

    string s = "  Manar Alwahedi   ";

    cout << "String          = " << "|" << s << "|" << "\n";
    cout << "Trim from left  = " << "|" << TirmFromLeft(s) << "|" << "\n";
    cout << "Trim from right = " << "|" << TirmFromRight(s) << "|" << "\n";
    cout << "Full Trim       = " << "|" << Tirm(s) << "|" << "\n";

}
