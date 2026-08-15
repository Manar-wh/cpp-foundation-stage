#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
    clsDblLinkedList <int> MydblLinkedList;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    cout << "\nLinked List Contenet:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.UpdateItem(9, 9101);
    cout << "\nUpdate Node Value Is: ";
    MydblLinkedList.PrintList();


    system("pause>0");
}
