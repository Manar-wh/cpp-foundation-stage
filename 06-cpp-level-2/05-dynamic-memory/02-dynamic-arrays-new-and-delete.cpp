#include <iostream>
using namespace std;

int main() {

	int NumOfStudent;
	cout << "How manay student do you want to enter ? ";
	cin >> NumOfStudent;

	float* ptr;

	ptr = new float[NumOfStudent];

	cout << "\nGrade of Students:\n";

	for (int i = 0; i < NumOfStudent; i++)
	{
		cout << "Student " << i + 1 << ": ";
		cin >> *(ptr + i);
	}

	for (int i = 0; i < NumOfStudent; i++)
	{
		cout << "Student " << i + 1 << ": " << *(ptr + i) << endl;
	}
  
  delete[] ptr;

}
