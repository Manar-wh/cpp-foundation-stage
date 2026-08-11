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

Node* FindNode(Node* head, int value) {
	
	while (head != NULL )
	{
		if (head->Value == value)
		{
			return head;
		}

		head = head->Next;
	}
	return NULL;
}

int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);

	PrintList(head);

	Node* FoundNode = FindNode(head, 3);

	if (FoundNode != NULL)
	{
		cout << "\nNode Found :) \n";
	}
	else
	{
		cout << "\nNode Not Found :( \n";
	}
}
