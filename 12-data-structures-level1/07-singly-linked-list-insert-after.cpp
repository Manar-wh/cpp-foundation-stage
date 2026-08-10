#include <iostream>
using namespace std;

class Node
{
public:
	int Value;
	Node* Next;
};

void InsertAtBeginning(Node* &head, int value) {

	Node* new_Node = new Node();
	new_Node->Value = value;
	new_Node->Next = head;
	head = new_Node;
}

void PtrintList(Node* head) {

	while (head != NULL)
	{
		cout << head->Value << "  ";
		head = head->Next;
	}
}

Node* Find(Node* head, int value) {

	while (head != NULL)
	{
		if (head->Value == value)
		{
			return head;
		}
		head = head->Next;
	}
	return NULL;
}

void InsertAfter(Node* Prev_node, int value) {

	if (Prev_node == NULL)
	{
		cout << "the given previous node cannot be NULL";
		return;
	}

	Node* New_nude = new Node();
	New_nude->Value = value;
	New_nude->Next = Prev_node->Next;
	Prev_node->Next = New_nude;
}

int main()
{
	Node* head = NULL;
	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);

	cout << "Befor InsertAfter: \n";
	PtrintList(head);

	Node *N1 = Find(head, 2);
	InsertAfter(N1, 500);
	cout << "\nAfter InsertAfter: \n";
	PtrintList(head);

}
