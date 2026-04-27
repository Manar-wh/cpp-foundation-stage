#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string ReadString() {
    string Text;
    cout << "Please Enter your string: " << endl;
    getline(cin >> ws, Text); 
    return Text;
}

char ReadChar() {
    char Target;
    cout << "Please Enter a character: " << endl;
    cin >> Target;
    return Target;
}

char InvertLetterCase(char Letter) {
    return isupper(Letter) ? (char)tolower(Letter) : (char)toupper(Letter);
}

int CountLetter(const string& Text, char Target, bool MatchCase = true) {

    int Counter = 0;

    for (int i = 0; i < Text.length(); i++) {

        if (MatchCase) {
            if (Text[i] == Target) {

                Counter++;
            }
        }
        else {

            if (tolower(Text[i]) == tolower(Target)) {
                Counter++;
            }
        }
    }
    return Counter;
}

int main() {

    string UserInput = ReadString();
    char TargetChar = ReadChar();

    cout << "\nLetter '" << TargetChar << "' Count (Match Case) = "
        << CountLetter(UserInput, TargetChar) << endl;

    cout << "Letter '" << TargetChar << "' Or '" << InvertLetterCase(TargetChar)
        << "' Count (All) = " << CountLetter(UserInput, TargetChar, false) << endl;

    return 0;
}
