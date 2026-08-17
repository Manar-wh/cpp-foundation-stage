#pragma once
#include <iostream>
#include "clsDynamicArray.h"
using namespace std;

template <class T>
class clsMyStackArr
{
protected:

	clsDynamicArray <T> DyArr;
public:

	void Push(T Value) {
		DyArr.InsertAtBeginning(Value);
	}

	void Print() {
		DyArr.PrintList();
	}

	int Size() {
		return DyArr.Size();
	}

	T Top() {
		return DyArr.GetItem(0);
	}

	T Bottom() {
		return DyArr.GetItem(Size() - 1);
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

	void UpdateItem(int Index, T Value) {
		DyArr.SetItem(Index, Value);
	}

	void InsertAfter(int Index, T Value) {
		DyArr.InsertAfter(Index, Value);
	}

	void InsertAtFront(T Value) {
		DyArr.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value) {
		DyArr.InsertAtEnd(Value);
	}

	void Clear() {
		DyArr.Clear();
	}
};

