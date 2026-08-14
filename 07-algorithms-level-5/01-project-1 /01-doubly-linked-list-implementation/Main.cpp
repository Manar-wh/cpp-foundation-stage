#include <iostream>
using namespace std;
#include "clsDblLinkList.h"
int main()
{
	clsDblLinkList <int> MydblLinkList;
	MydblLinkList.InsertAtBeginning(5);
	MydblLinkList.InsertAtBeginning(4);
	MydblLinkList.InsertAtBeginning(3);
	MydblLinkList.InsertAtBeginning(2);
	MydblLinkList.InsertAtBeginning(1);

	cout << "Link List Content: \n";
	MydblLinkList.PrintList();

	clsDblLinkList <int>::Node* N1 = MydblLinkList.Find(4);
	if (N1 != NULL)
	{
		cout << "\nNode with value 4 Is Found :)\n";
	}
	else
		cout << "\nNode with value 4 Is Not Found :(\n";

	MydblLinkList.InsertAfter(N1, 700);
	cout << "\nLink List Content After InsertAfter: \n";
	MydblLinkList.PrintList();

	MydblLinkList.InsertAtEnd(800);
	cout << "\nLink List Content After InsertAtEnd: \n";
	MydblLinkList.PrintList();

	 N1 = MydblLinkList.Find(5);
	 MydblLinkList.DeleteNode(N1);
	 cout << "\nLink List Content After DeleteNode 5: \n";
	 MydblLinkList.PrintList();

	 MydblLinkList.DeleteFirstNode();
	 cout << "\nLink List Content After Delete First Node: \n";
	 MydblLinkList.PrintList();

	 MydblLinkList.DeleteLastNode();
	 cout << "\nLink List Content After Delete Last Node: \n";
	 MydblLinkList.PrintList();

}

