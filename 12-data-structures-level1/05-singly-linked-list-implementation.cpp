#include <iostream>
using namespace std;

class Node {
public:
    int Value;
    Node* Next;
};

int main() {
    // 1. Declare pointers and allocate objects in the Heap
    Node* Node1 = new Node();
    Node* Node2 = new Node();
    Node* Node3 = new Node();

    // 2. Assign values
    Node1->Value = 1;
    Node2->Value = 2;
    Node3->Value = 3;

    // 3. Link nodes
    Node1->Next = Node2;
    Node2->Next = Node3;
    Node3->Next = nullptr;

    // 4. Print Linked List elements
    Node* head = Node1;
    while (head != nullptr) {
        cout << head->Value << "\n";
        head = head->Next;
    }

    // 5. Memory Cleanup
    delete Node1;
    delete Node2;
    delete Node3;

    return 0;
}
