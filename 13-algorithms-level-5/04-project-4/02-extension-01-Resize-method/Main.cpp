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

    cout << "\n\nArray After Resize :  ";
    MyDynamicArray.Resize(2);
    cout << "\nArray Size :  " << MyDynamicArray.ArraySize();
    cout << "\nArray Item :  ";
    MyDynamicArray.PrintList();


    system("pause>0");
    return 0;
}
