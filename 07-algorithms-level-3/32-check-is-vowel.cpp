#include <iostream>
#include <string>
#include <cctype>

using namespace std;


char ReadChar() {
    char c;
    cout << "Please Enter a character: " << endl;
    cin >> c;
    return c;
}

bool IsVowel(char c) {
    c = tolower(c);

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {

    char c = ReadChar();


    if (IsVowel(c))
        cout << "\nYes, Letter " << c << " is vowel\n";
    else
        cout << "\nNo, Letter " << c << " is Not vowel\n";

    return 0;
}
