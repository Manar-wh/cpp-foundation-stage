#pragma once
#include <iostream>
using namespace std;

template <class T>
class clsDblLinkedList
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
	int _Size = 0;

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
		_Size++;
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

	void InsertAfter(Node* NodeToInsertAfter, T value) {

		if (NodeToInsertAfter == NULL)
			return;
		
		Node* new_node = new Node();
		new_node->Value = value;
		new_node->Next = NodeToInsertAfter->Next;
		new_node->Prev = NodeToInsertAfter;

		if (NodeToInsertAfter->Next != NULL)
		{
			NodeToInsertAfter->Next->Prev = new_node;
		}
		NodeToInsertAfter->Next = new_node;
		_Size++;
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
			_Size++;
			return;
		}

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = new_node;
		new_node->Prev = Current;
		_Size++;
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
			_Size--;
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
		_Size--;

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
		_Size--;

	}

	void DeleteLastNode() {

		if (head == NULL)
			return;

		Node* Current = head;

		if (head->Next == NULL)
		{
			head = NULL;
			delete Current;
			_Size--;
			return;
		}

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Prev->Next = NULL;
		delete Current;
		_Size--;
	}

	int Size() const {
		return _Size;
	}

	bool IsEmpty() {

		return (_Size == 0);
	}

	void Clear() {

		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse() {

		Node* Current = head;
		Node* temp = NULL;
		while (Current != NULL)
		{
			temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = temp;
			Current = Current->Prev;
		}
		if (temp != NULL)
		{
			head = temp->Prev;
		}
	}

	Node* GetNode(int Index) {

		if (Index > _Size - 1 || Index < 0)
			return NULL;
		Node* Current = head;
		int Counter = 0;
		while (Current != NULL)
		{
			if (Counter == Index)
			{
				return Current;
			}
			Current = Current->Next;
			Counter++;
		}
		return NULL;
	}

	T GetItem(int Index) {

		Node* ItemNode = NULL;
		ItemNode = GetNode(Index);

		return (ItemNode != NULL) ? ItemNode->Value : T();
	}

	bool UpdateItem(int Index, T value) {

		Node* UpdateItem = NULL;
		UpdateItem = GetNode(Index);

		if (UpdateItem != NULL)
		{
			UpdateItem->Value = value;
			return true;
		}
		return false;
	}

	bool InsertAfter(int Index, T value) {

		Node* ItemNode = NULL;
		ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, value);
			return true;
		}
		return false;
	}
};

