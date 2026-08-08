#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> MyQueue1;

	MyQueue1.push(8);
	MyQueue1.push(4);
	MyQueue1.push(6);
	MyQueue1.push(2);
	MyQueue1.push(1);
	
	queue <int> MyQueue2;

	MyQueue2.push(42);
	MyQueue2.push(43);
	MyQueue2.push(40);
	MyQueue2.push(45);
	MyQueue2.push(41);

	MyQueue1.swap(MyQueue2);

	cout << "=== MyQueue1 Elements (After Swap) ===" << endl;
	while (!MyQueue1.empty())
	{
		cout << "MyQueue1 Front Element: " << MyQueue1.front() << endl;
		MyQueue1.pop();
	}

	cout << "\n========================================" << endl;
	cout << "=== MyQueue2 Elements (After Swap) ===" << endl;
	while (!MyQueue2.empty())
	{
		cout << "MyQueue2 Front Element: " << MyQueue2.front() << endl;
		MyQueue2.pop();
	}

	return 0;
}
