#pragma once
#include <iostream>
using namespace std;

template <typename T>
class clsDynamicArray
{
	int _Size = 0;

public:

	T* OriginalArray;

	clsDynamicArray(int Size = 0) {
		if (Size < 0)
			Size = 0;

		_Size = Size;
		OriginalArray = new T[Size];
	}

	bool SetItem(int Index, T Value) {

		if (Index < 0 || Index >= _Size)
			return false;

		OriginalArray[Index] = Value;
		return true;
	}

	void PrintList() {

		for (int i = 0; i < _Size; i++)
		{
			cout << OriginalArray[i] << "  ";
		}
	}

	bool IsEmpty() {
		return (_Size == 0);
	}

	int ArraySize() {
		return _Size;
	}

	~clsDynamicArray() {
		delete[] OriginalArray; 
	}
};

