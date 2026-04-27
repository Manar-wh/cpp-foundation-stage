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
    return (c == 'a' || c == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int CountAllVowels(string s) {
    int counter = 0;
    for (int i = 0; i < s.length(); i++) {
        if (IsVowel(s[i])) {
            counter++;
        }
    }
    return counter;
}

int main() {
    string s = ReadString();
    cout << "\nNumber of vowels is= " << CountAllVowels(s) << "\n";
    return 0;
}
