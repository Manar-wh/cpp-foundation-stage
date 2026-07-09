#include <iostream>
using namespace std;

class clsPerson {
public:
	// 'virtual' tells the compiler to look at the actual object type at runtime, not the pointer type
	virtual void print() {
		cout << "Hello, I'm a person!\n";
	}
};

class clsEmployee : public clsPerson {
public:
	void print() {
		cout << "Hello, I'm an Employee!\n";
	}
};

class clsStudent : public clsPerson{
public:
	void print() {
		cout << "Hello, I'm a Student!\n";
	}
};

int main() {

	clsEmployee Employee1;
	clsStudent Student1;

	// 1. Direct Calls: Calls the print function directly from the specific object type
	Employee1.print(); // Prints Employee message
	Student1.print();  // Prints Student message

	// Creating Base class pointers pointing to Derived class objects
	clsPerson* person1 = &Employee1;
	clsPerson* person2 = &Student1;

	// 2. Polymorphic Calls: Because of 'virtual', the pointer automatically 
	// detects the true object type behind it and executes its overridden function.
	person1->print(); // Dynamically calls Employee's print
	person2->print(); // Dynamically calls Student's print

	return 0;
}
