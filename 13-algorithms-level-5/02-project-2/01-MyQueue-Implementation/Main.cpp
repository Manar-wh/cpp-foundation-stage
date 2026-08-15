#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
using namespace std;

int main()
{

    clsMyQueue <int> MyQueue;
    MyQueue.Push(1);
    MyQueue.Push(2);
    MyQueue.Push(3);
    MyQueue.Push(4);
    MyQueue.Push(5);

    cout << "Queue: \n";
    MyQueue.Print();

    cout << "\nQueue List:  " << MyQueue.Size();
    cout << "\nQueue Front:  " << MyQueue.Front();
    cout << "\nQueue Back:  " << MyQueue.Back();

    MyQueue.Pop();

    cout << "\nQueue After pop(): ";
    MyQueue.Print();
  
    system("pause>0");
}
