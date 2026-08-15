#pragma once
#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
using namespace std;

template <typename T>
class clsMyStack : public clsMyQueue <T>
{

public:

	void Push(T value) {

		clsMyQueue <T>::MyDblList.InsertAtBeginning(value);
	}

	T Top() {
		return clsMyQueue<T>::Front();
	}

	T Bottom() {
		return clsMyQueue<T>::Back();
	}

};
