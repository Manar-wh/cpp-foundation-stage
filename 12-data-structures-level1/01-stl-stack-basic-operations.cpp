#include <iostream>
#include <stack>
using namespace std;

int main()

{
    stack <int> stkNumbers;

    stkNumbers.push(10);
    stkNumbers.push(20);
    stkNumbers.push(30);
    stkNumbers.push(40);
    stkNumbers.push(50);

    cout << "count=" << stkNumbers.size() << endl;
    
    cout << "Numbers are:\n";
    while (!stkNumbers.empty()) {
        // print top element
        cout << stkNumbers.top() << "\n";
      
        // pop top element from stack
        stkNumbers.pop();
    }

    system("pause>0");
    return 0;
}
