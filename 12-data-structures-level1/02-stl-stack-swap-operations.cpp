#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack <int> stkNumbers1;

	stkNumbers1.push(50);
	stkNumbers1.push(40);
	stkNumbers1.push(30);
	stkNumbers1.push(20);
	stkNumbers1.push(10);

	stack <int> stkNumbers2;

	stkNumbers2.push(5);
	stkNumbers2.push(4);
	stkNumbers2.push(3);
	stkNumbers2.push(2);
	stkNumbers2.push(1);

	stkNumbers1.swap(stkNumbers2);

	cout << "=== stkNumbers1 Elements (After Swap) ===" << endl;
	while (!stkNumbers1.empty())
	{
		cout << "stkNumbers1 Top Element: " << stkNumbers1.top() << endl;
		stkNumbers1.pop();
	}

	cout << "\n========================================" << endl;
	cout << "=== stkNumbers2 Elements (After Swap) ===" << endl;
	while (!stkNumbers2.empty())
	{
		cout << "stkNumbers2 Top Element: " << stkNumbers2.top() << endl;
		stkNumbers2.pop();
	}

	return 0;
}
