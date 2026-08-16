#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0,10);
    MyDynamicArray.SetItem(1,20);
    MyDynamicArray.SetItem(2,30);
    MyDynamicArray.SetItem(3,40);
    MyDynamicArray.SetItem(4,50);

    cout << "\nIs Empty   ?  " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size :  " << MyDynamicArray.ArraySize();
    cout << "\nArray Item :  ";
    MyDynamicArray.PrintList();


    MyDynamicArray.InsertAT(0,990);
    cout << "\n\nArray Item After Insert 990 AT 0 :  ";
    MyDynamicArray.PrintList();
    cout << "\nArray Size :  " << MyDynamicArray.ArraySize();

    system("pause>0");
    return 0;
}
