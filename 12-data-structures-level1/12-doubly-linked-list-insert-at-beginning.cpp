#include <iostream>
using namespace std;

class Node
{
public:
	int Value;
	Node* Next;
	Node* Prev;
};

void InsertAtBeginning(Node* &head, int value) {
	
	Node* new_node = new Node();
	new_node->Value = value;
	new_node->Next = head;
	new_node->Prev = NULL;

	if (head != NULL)
	{
		head->Prev = new_node;
	}

	head = new_node;
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);

	Node* Current = head;

	while (Current != NULL)
	{
		cout << Current->Value << " ";
		Current = Current->Next;
	}
}
