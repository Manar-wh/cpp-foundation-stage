#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <typename T>
class clsMyQueueArr
{
protected:
	clsDynamicArray<T> DyArr;

public:

	void Push(T Value) {

		DyArr.InsertAtEnd(Value);
	}

	void Print() {
		DyArr.PrintList();
	}

	int Size() {
		return DyArr.Size();
	}

	T Front() {
		return DyArr.GetItem(0);
	}

	T Back() {
		return DyArr.GetItem(DyArr.Size() - 1);
	}

	void Pop() {
		DyArr.DeleteFirstItem();
	}

	T GetItem(int Index) {
		return DyArr.GetItem(Index);
	}

	void Reverse() {
	  DyArr.Reverse();
	}

	bool UpdateItem(int Index, T value) {
		return DyArr.SetItem(Index, value);
	}

	void InsertAfter(int Index, T value) {
		DyArr.InsertAfter(Index, value);
	}

	void InsertAtFront(T value) {
		DyArr.InsertAtBeginning(value);
	}

	void InsertAtBack(T value) {
		DyArr.InsertAtEnd(value);
	}

	void Clear() {
		DyArr.Clear();
	}
};

