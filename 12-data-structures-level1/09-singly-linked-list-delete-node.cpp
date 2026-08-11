#include <iostream>
using namespace std;

class Node
{
public:
	int Value;
	Node* Next;
};


void PrintList(Node* head) {

	while (head != NULL)
	{
		cout << head->Value << "  ";
		head = head->Next;
	}
	cout << "\n";
}

void InsertAtEnd(Node* &head, int value) {

	Node* new_node = new Node();
	new_node->Value = value;
	new_node->Next = NULL;
	
	if (head == NULL)
	{
		head = new_node;
		return;
	}

	Node* LastNode = head;

	while (LastNode->Next != NULL)
	{
		LastNode = LastNode->Next;
	}

	LastNode->Next = new_node;
	return;
}

void DeleteNode(Node* &head, int Value) {
	
	Node* Current = head;
	Node* PrevNode = head;

	if (head == NULL)
	{
		return;
	}

	if (Current->Value == Value)
	{
		head = Current->Next;
		delete Current;

		return;
	}

	while (Current != NULL && Current->Value != Value)
	{
		PrevNode = Current;
		Current = Current->Next;
	}

	if (Current == NULL)
	{
		return;
	}

	PrevNode->Next = Current->Next;
	delete Current;
	return;
}

int main()
{
	Node* head = NULL;
	InsertAtEnd(head, 1);
	InsertAtEnd(head, 2);
	InsertAtEnd(head, 3);
	InsertAtEnd(head, 4);
	InsertAtEnd(head, 5);

	PrintList(head);
	
	DeleteNode(head, 3);
	PrintList(head);

}
