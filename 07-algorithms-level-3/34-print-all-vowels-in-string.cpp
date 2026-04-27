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

bool IsVowel(char c) {

    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void PrintAllVowels(string s) {

    for ( int i = 0; i < s.length(); i++)
    {
        if (IsVowel(s[i])) {

            cout << s[i] << "  ";
        }
    }
}

int main() {

    string s = ReadString();
    cout << "\nVowels in the string are: \n"; 
    PrintAllVowels(s);

    return 0;
}
