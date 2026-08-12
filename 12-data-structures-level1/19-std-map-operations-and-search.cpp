#include <iostream>
#include <map>
using namespace std;

int main()
{
	map <string, int> StudentGrades;
	StudentGrades["Sara"] = 90;
	StudentGrades["Nada"] = 95;
	StudentGrades["Doha"] = 88;

	cout << "Printing all map value: \n\n";
	for ( const auto &s : StudentGrades)
	{
		cout << "Student: " << s.first << ", Grades: " << s.second << "\n";
	}

	cout << "\nFinding Sara's Grade in the map: \n";

	string StudentName = "Sara";
	if (StudentGrades.find(StudentName) != StudentGrades.end())
	{
		cout << StudentName << "'s Grade: " << StudentGrades[StudentName] << "\n";
	}
	else
	{
		cout << "\nGrade Not Found For " << StudentName << endl;
	}

	cout << "\nFinding Reem's Grade in the map: \n";
	StudentName = "Reem";
	if (StudentGrades.find(StudentName) != StudentGrades.end())
	{
		cout << StudentName << "'s Grade: " << StudentGrades[StudentName] << "\n";
	}
	else
	{
		cout << "Grade Not Found For " << StudentName << endl;
	}


}
