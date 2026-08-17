#include <iostream>
#include "clsMyStrings.h"

using namespace std;

int main()
{
    clsMyStrings S1;

    cout << "\n[1] --- Setting Initial Values ---\n";

    S1.Value = "Manar";
    cout << "-> S1: " << S1.Value << "\n";

    S1.Value = "SARAH";
    cout << "-> S1: " << S1.Value << "\n";

    S1.Value = "REEM";
    cout << "-> S1: " << S1.Value << "\n";

    cout << "\n[2] --- Undo Sequence ---\n";

    S1.Undo();
    cout << "<- Undo 1: " << S1.Value << "\n";

    S1.Undo();
    cout << "<- Undo 2: " << S1.Value << "\n";

    S1.Undo();
    cout << "<- Undo 3: " << S1.Value << "\n";

    cout << "\n[3] --- Redo Sequence ---\n";

    S1.Redo();
    cout << "-> Redo 1: " << S1.Value << "\n";

    S1.Redo();
    cout << "-> Redo 2: " << S1.Value << "\n";

    S1.Redo();
    cout << "-> Redo 3: " << S1.Value << "\n";

    cout << "\n-----------------------------\n";

    system("pause>0");
    return 0;
}
