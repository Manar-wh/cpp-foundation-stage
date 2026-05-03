#include <iostream>
#include <string>

using namespace std;


string Replacewords(string s, string TheWord, string Replaceto) {

    int pos = s.find(TheWord);

    while (pos != std::string::npos) {

        s.replace(pos, TheWord.length(), Replaceto);

        pos = s.find(TheWord, pos + Replaceto.length());
    }

    return s;
}

int main() {

    string s = "Welcome to Italy, Italy is a nice place";

    cout << "Original String:\n" << s << "\n\n";

    string result = Replacewords(s, "Italy", "Saudi Arabia");

    cout << "String After Replace:\n" << result << "\n";

    return 0;
}
