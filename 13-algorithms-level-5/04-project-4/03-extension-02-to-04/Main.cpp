#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
    clsDynamicArray <int> MyDynamicArray(5);

    MyDynamicArray.SetItem(0,1);
    MyDynamicArray.SetItem(1,2);
    MyDynamicArray.SetItem(2,3);
    MyDynamicArray.SetItem(3,4);
    MyDynamicArray.SetItem(4,5);

    cout << "\nIs Empty   ?  " << MyDynamicArray.IsEmpty();
    cout << "\nArray Size :  " << MyDynamicArray.ArraySize();
    cout << "\nArray Item :  ";
    MyDynamicArray.PrintList();


    cout << "\n\nItem(2) : " << MyDynamicArray.GetItem(2) << "\n";

    MyDynamicArray.Reverse();
    cout << "\nArray Item After Reverse :  ";
    MyDynamicArray.PrintList();

    MyDynamicArray.Clear();
    cout << "\nArray Item After Clear :  ";
    MyDynamicArray.PrintList();


    system("pause>0");
    return 0;
}
