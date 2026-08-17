#include <iostream>
#include "clsDynamicArray.h"
#include "clsMyQueueArr.h"
using namespace std;

int main()
{

    clsMyQueueArr <int> MyQueue;
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

    cout << "\n\n Item(2) : " << MyQueue.GetItem(2);

    MyQueue.Reverse();
    cout << "\n\nQueue after reverse() : \n";
    MyQueue.Print();

    MyQueue.UpdateItem(2, 600);
    cout << "\n\nQueue after updating Item(2) to 600 : \n";
    MyQueue.Print();

    MyQueue.InsertAfter(2, 800);
    cout << "\n\nQueue after Inserting 800 after Item(2) : \n";
    MyQueue.Print();

    MyQueue.InsertAtFront(1000);
    cout << "\n\nQueue after Inserting 1000 at front: \n";
    MyQueue.Print();

    MyQueue.InsertAtBack(2000);
    cout << "\n\nQueue after Inserting 2000 at back: \n";
    MyQueue.Print();

    MyQueue.Clear();
    cout << "\n\nQueue after Clear(): \n";
    MyQueue.Print();

    system("pause>0");
}
