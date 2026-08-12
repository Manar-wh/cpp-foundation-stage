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


void DeleteLastNode(Node* &head) {
	
	if (head == NULL)
		return;

	if (head->Next == NULL) {
		delete head;
		head = NULL; 
		return;
	}

	Node* LastNode = head;

	while (LastNode->Next !=NULL)
	{
		LastNode = LastNode->Next;
	}

	LastNode->Prev->Next = NULL;

	delete LastNode ;
}


int main()
{
	Node* head = NULL;

	InsertAtBeginning(head, 1);
	InsertAtBeginning(head, 2);
	InsertAtBeginning(head, 3);
	InsertAtBeginning(head, 4);
	InsertAtBeginning(head, 5);

	DeleteLastNode(head);
	PrintList(head);

}
