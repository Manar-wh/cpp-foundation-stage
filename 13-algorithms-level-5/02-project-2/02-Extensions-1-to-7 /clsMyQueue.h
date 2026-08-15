#pragma once
#include <iostream>
using namespace std;
#include "clsDblLinkedList.h"

template <class T>
class clsMyQueue
{
protected:
	clsDblLinkedList <T> MyDblList;

public:

	void Push(T Value) {
		MyDblList.InsertAtEnd(Value);
	}

	void Print() {
		MyDblList.PrintList();
	}

	int Size() {
		return MyDblList.Size();
	}

	T Front() {
		return MyDblList.GetItem(0);
	}

	T Back() {
		return MyDblList.GetItem(Size() - 1);
	}

	void Pop() {
		MyDblList.DeleteFirstNode();
	}

	T GetItem(int Index) {
		return MyDblList.GetItem(Index);
	}

	void Reverse() {

		MyDblList.Reverse();
	}

	void UpdateItem(int Index, T Value) {
		MyDblList.UpdateItem(Index, Value);
	}

	void InsertAfter(int Index, T Value) {
		MyDblList.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value) {
		MyDblList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value) {
		MyDblList.InsertAtEnd(Value);
	}

	void Clear() {
		MyDblList.Clear();
	}

};

