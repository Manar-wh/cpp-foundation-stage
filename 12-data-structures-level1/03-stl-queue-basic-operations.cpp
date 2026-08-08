#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue <int> MyQueue;

	MyQueue.push(8);
	MyQueue.push(4);
	MyQueue.push(6);
	MyQueue.push(2);
	MyQueue.push(1);

	cout << "\nCount = " << MyQueue.size();
	cout << "\nFront = " << MyQueue.front();
	cout << "\nBack  = " << MyQueue.back();

	cout << "\nMy Queue= " << "\n";
	while (!MyQueue.empty())
	{
		cout << MyQueue.front() << "\n";
		MyQueue.pop();
	}
	return 0;
}
