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

void DeleteLastNode(Node* &head) {
	
	if (head == NULL) return;

	if (head->Next == NULL)
	{
		delete head; 
		head = NULL;
		return;
	}

	Node* LastNode = head;
	Node* PrevNode = head;

	while (LastNode->Next != NULL)
	{
		PrevNode = LastNode;
		LastNode = LastNode->Next;
	}
	PrevNode->Next = NULL;
	delete LastNode;
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
	DeleteLastNode(head);
	PrintList(head);
}
