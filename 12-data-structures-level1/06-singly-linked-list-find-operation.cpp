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
		cout << head->Value << endl;
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

int main()
{
	Node* head = NULL;
	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);

	PtrintList(head);

	Node *N1 = Find(head, 2);
	if (N1 != NULL)
	{
		cout << "\nNode Found :)";
	}
	else
	{
		cout << "\nNode Not Found :(";
	}
}
