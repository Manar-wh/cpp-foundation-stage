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

void PrintList(Node* head) {
	while (head != NULL)
	{
		cout << head->Value << " ";
		head = head->Next;
	}
	cout << "\n";
}

void InsertAfter(Node*  Current, int value) {

	if (Current == NULL) return;

	Node* new_node = new Node();
	new_node->Value = value;

	new_node->Prev = Current;
	new_node->Next = Current->Next;

	if (Current->Next != NULL)
	{
		Current->Next->Prev = new_node;
	}
	Current->Next = new_node;
}

void InsertAtEnd(Node* &head, int value) {
	
	Node* new_node = new Node();
	new_node->Value = value;
	new_node->Next = NULL;

	if (head == NULL)
	{
		new_node->Prev = NULL;
		head = new_node;
		return;
	}

	Node* Current = head;
	while (Current->Next != NULL)
	{
		Current = Current->Next;
	}
	new_node->Prev = Current;
	Current->Next = new_node;
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);

	InsertAtEnd(head, 500);
	PrintList(head);

}
