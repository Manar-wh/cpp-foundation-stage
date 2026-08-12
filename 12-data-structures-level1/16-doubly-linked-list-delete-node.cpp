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

void DeleteNode(Node* &head, Node* NodeToDelete) {

	if (head == NULL || NodeToDelete == NULL)
	return;

	if (head == NodeToDelete)
	{
		head = NodeToDelete->Next;
	}

	if (NodeToDelete->Next != NULL)
	{
		NodeToDelete->Next->Prev = NodeToDelete->Prev;
	}

	if (NodeToDelete->Prev != NULL)
	{
		NodeToDelete->Prev->Next = NodeToDelete->Next;
	}
	delete NodeToDelete;
	return;
}


int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);

	Node* N1 = FindNode(head, 5);
	DeleteNode(head, N1);
	PrintList(head);

}
