#pragma once
#include <iostream>
using namespace std;

template <typename T>
class clsDynamicArray
{
	int _Size = 0;
	T* _TempArray;

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

	void Resize(int NewSize = 0) {

		if (NewSize < 0)
			NewSize = 0;
		_TempArray = new T[NewSize];

		if (NewSize < _Size)
			_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		delete[]OriginalArray;
		_Size = NewSize;
		OriginalArray = _TempArray;

	}

	T GetItem(int Index) {

		if (Index >= _Size || Index < 0)
			return 0;

		return OriginalArray[Index];
	}

	void Reverse() {
		int j = 0;
		_TempArray = new T[_Size];

		for (int i = _Size - 1; i >= 0; i--)
		{
			_TempArray[j] = OriginalArray[i];
			j++;
		}

		delete[] OriginalArray;
		OriginalArray = _TempArray;
	}

	void Clear() {
		_Size = 0;
		delete[] OriginalArray;
		OriginalArray = NULL;
	}

	bool DeleteItemAt(int Index) {

		if (Index <0 || Index >= _Size)
			return false;

		_TempArray = new T[_Size - 1];

		for (int i = 0; i < Index ; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		for (int i = Index + 1; i < _Size; i++)
		{
			_TempArray[i-1] = OriginalArray[i];
		}

		_Size--;
		delete[]OriginalArray;
		OriginalArray = _TempArray;
		return true;
	}

	bool DeleteFirstItem() {

		return DeleteItemAt(0);
	}


	bool DeleteLastItem() {

		return DeleteItemAt(_Size - 1);
	}

	int Find(T Value) {

		if (OriginalArray == NULL)
			return -1;
		for (int i = 0; i < _Size; i++)
		{
			if (OriginalArray[i] == Value)
			{
				return i;
			}
		}

		return -1;
	}

	bool DeleteItem(T Value) {

		int Index = Find(Value);
		return DeleteItemAt(Index);
	}


	~clsDynamicArray() {
		delete[] OriginalArray; 
	}

};

