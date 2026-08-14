#include <iostream>
using namespace std;
#include "clsDblLinkedList.h"
int main()
{
	clsDblLinkedList <int> MydblLinkedList;

	if (MydblLinkedList.IsEmpty())
	{
		cout << "Yes,List Is Empty\n\n";
	}
	else
		cout << "List Not Empty\n\n";

	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "Linked List Content: \n";
	MydblLinkedList.PrintList();

	if (MydblLinkedList.IsEmpty())
	{
		cout << "\nYes,List Is Empty\n";
	}
	else
		cout << "\nList Is Not Empty\n";

	 cout << "\nNumber of the Item in Linked List: " << MydblLinkedList.Size() << "\n";

}
