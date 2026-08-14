#pragma once
#include <iostream>
using namespace std;

template <typename T>
class clsDblLinkList
{

public:

	class Node
	{
	public:
		T Value;
		Node* Next;
		Node* Prev;
	};

protected:

	Node* head = NULL;

public:

	void InsertAtBeginning(T value) {

		Node* new_node = new Node();
		new_node->Value = value;
		new_node->Prev = NULL;
		new_node->Next = head;

		if (head != NULL)
		{
			head->Prev = new_node;
		}
		head = new_node;
	}

	void PrintList() {

		Node* Current = head;
		while (Current != NULL)
		{
			cout << Current->Value << " ";
			Current = Current->Next;
		}
		cout << "\n";
	}

	Node* Find(T value) {

		Node* Current = head;

		while (Current !=NULL)
		{
			if (Current->Value == value)
			{
				return Current;
			}
			Current = Current->Next;
		}
		return NULL;
	}

	void InsertAfter(Node* NodeToFind, T value) {
		Node* Current = head;

		if (Current == NULL || NodeToFind == NULL)
		{
			return;
		}

		Node* new_node = new Node();
		new_node->Value = value;
		new_node->Next = NodeToFind->Next;
		new_node->Prev = NodeToFind;

		if (NodeToFind->Next != NULL)
		{
			NodeToFind->Next->Prev = new_node;
		}
		NodeToFind->Next = new_node;
	}

	void InsertAtEnd(T value) {

		Node* Current = head;
		Node* new_node = new Node();
		new_node->Value = value;
		new_node->Next = NULL;

		if (Current == NULL)
		{
			head = new_node;
			new_node->Prev = NULL;
			return;
		}

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = new_node;
		new_node->Prev = Current;
	}

	void DeleteNode(Node* NodeToDelete) {

		Node* Current = head;

		if (Current == NULL || NodeToDelete == NULL)
			return;

		if (head == NodeToDelete)
		{
			head = head->Next;
			if (head != NULL)
			{
				head->Prev = NULL; 
			}

			delete NodeToDelete;
			return; 
		}
		
		if (NodeToDelete->Prev !=NULL)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		if (NodeToDelete->Next != NULL)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;

		}
		delete NodeToDelete;
	}

	void DeleteFirstNode() {

		if (head == NULL)
			return;
			
		Node* Current = head;
		
		head = head->Next;

		if (head != NULL)
		{
			head->Prev = NULL;
		}
		delete Current;
	}

	void DeleteLastNode() {

		if (head == NULL)
			return;

		Node* Current = head;

		if (head->Next == NULL)
		{
			head = NULL;
			delete Current;
			return;
		}

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Prev->Next = NULL;
		delete Current;
	}


};

