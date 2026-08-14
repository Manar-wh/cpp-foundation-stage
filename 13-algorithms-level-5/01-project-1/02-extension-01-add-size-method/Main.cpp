#include <iostream>
using namespace std;
#include "clsDblLinkedList.h"
int main()
{
	clsDblLinkedList <int> MydblLinkedList;
	MydblLinkedList.InsertAtBeginning(5);
	MydblLinkedList.InsertAtBeginning(4);
	MydblLinkedList.InsertAtBeginning(3);
	MydblLinkedList.InsertAtBeginning(2);
	MydblLinkedList.InsertAtBeginning(1);

	cout << "Linked List Content: \n";
	MydblLinkedList.PrintList();

	 cout << "\nNumber of the Item in Linked List: " << MydblLinkedList.Size() << "\n";

}
