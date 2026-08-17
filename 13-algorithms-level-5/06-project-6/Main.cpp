#include <iostream>
#include "clsMyStackArr.h"

using namespace std;

int main()
{
    clsMyStackArr <int> MyStack;

    MyStack.Push(1);
    MyStack.Push(2);
    MyStack.Push(3);
    MyStack.Push(4);
    MyStack.Push(5);

    cout << "Stack: \n";
    MyStack.Print();

    cout << "\nStack Size:   " << MyStack.Size();
    cout << "\nStack Top:    " << MyStack.Top();
    cout << "\nStack Bottom: " << MyStack.Bottom();

    MyStack.Pop();

    cout << "\n\nStack After pop(): \n";
    MyStack.Print();

    cout << "\n\n Item(2) : " << MyStack.GetItem(2);

    MyStack.Reverse();
    cout << "\n\nStack after reverse() : \n";
    MyStack.Print();

    MyStack.UpdateItem(2, 600);
    cout << "\n\nStack after updating Item(2) to 600 : \n";
    MyStack.Print();

    MyStack.InsertAfter(2, 800);
    cout << "\n\nStack after Inserting 800 after Item(2) : \n";
    MyStack.Print();

    MyStack.InsertAtFront(1000);
    cout << "\n\nStack after Inserting 1000 at front: \n";
    MyStack.Print();

    MyStack.InsertAtBack(2000);
    cout << "\n\nStack after Inserting 2000 at back: \n";
    MyStack.Print();

    MyStack.Clear();
    cout << "\n\nStack after Clear(): \n";
    MyStack.Print();

    system("pause>0");
    return 0;
}
