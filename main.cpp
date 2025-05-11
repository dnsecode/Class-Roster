#include<string>
#include<iostream>
#include <iomanip> 
#include "student.h"
#include "roster.h"
using namespace std;

int main() {
	const int numStudents = 5;

	// B. I modified the "studentData Table" to include my personal information as the last item.
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Denise,Mascardo,dmasca1@wgu.edu,23,30,37,30,SOFTWARE"
	};

	// part G. I print the course title, the programming language used, your WGU student ID, and your name.
	cout << "=============================================" << endl;
	cout << "C867 - Scripting and Programming Applications" << endl;
	cout << "              Language: C++" << endl;
	cout << "         Student ID: #011134646" << endl;
	cout << "                  Denise Mascardo" << endl;
	cout << "=============================================" << endl << endl;

	// G. I created an instance of the Roster class called classRoster.
	Roster classRoster;

	// G. I added each student to the classRoster.
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		classRoster.parseStudentData(studentData[i]);
	}

	// G. I converted the ff. pseudo code so I can complete the rest of the main() function:
	// G. I printed the complete class roster.
	cout << "************" << endl;
	cout << "Class roster" << endl;
	cout << "************" << endl << endl;
	classRoster.printAll();
	cout << endl << endl;

	// G. I printed a list of invalid email addresses.
	cout << "***********************" << endl;
	cout << "Invalid email addresses" << endl;
	cout << "***********************" << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl << endl;

	// G. I printed average days in course by student ID.
	cout << "***********************" << endl;
	cout << "Average days in course" << endl;
	cout << "***********************" << endl << endl;

	cout << left << setw(12) << "ID";
	cout << left << setw(12) << "Average days";
	cout << endl << endl;

	// G. I loop through classRosterArray for each element:
	int j = 0;
	for (int j = 0; j < numStudents; ++j) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[j]->get_id());
	}
	cout << endl << endl;

	// G. I printed students in the SOFTWARE program.
	cout << "****************************" << endl;
	cout << "Students in Software program" << endl;
	cout << "****************************" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl << endl;

	// G. I remove student by student ID.
	cout << "**************" << endl;
	cout << "Remove student" << endl;
	cout << "**************" << endl << endl;
	classRoster.remove("A3");
	cout << endl << endl;

	// G. I printed class roster again the updated one.
	cout << "*******************" << endl;
	cout << "Update class roster" << endl;
	cout << "*******************" << endl << endl;
	classRoster.printAll();
	cout << endl << endl;

	// G. The above line should print a message stating such a student with this kind of ID was not found.
	cout << "********************" << endl;
	cout << "Retry remove student" << endl;
	cout << "********************" << endl << endl;
	classRoster.remove("A3");
	cout << endl << endl;

	// G. I called the destructor so it releases the roster object from memory.
	cout << "**************" << endl;
	cout << "Run destructor" << endl;
	cout << "**************" << endl << endl;
}