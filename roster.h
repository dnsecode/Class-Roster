#include<string>
#include <iostream>
#include "student.h"
using namespace std;

#ifndef roster_h 
#define roster_h

class Roster {
private:
	int dataEnd = -1;
	const static int numStudents = 5;

public:
	// part F. Create an array or vector of pointers and I named it classRosterArray so it can hold the data provided in the "studentData Table".
	Student* classRosterArray[numStudents];

	// F. I parse each set of data identified in the "studentData Table."
	// F. I Add each student object to classRosterArray.
	void parseStudentData(string studentData);

	// F. I add() sets the instance variables and updates the roster.
	void add(string id, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	// F. I remove() removes students from the roster by student ID, but if the student ID does not exist, the function prints an error message indicating that the student was not found.
	void remove(string id);

	// F. I printAll() prints that loops through all the students in classRosterArray so it calls the print() function for each student.
	void printAll();

	// F. It correctly prints the average number of days in the 3 courses for the student whoose studentID is passed in as the parameter.
	void printAverageDaysInCourse(string id);

	// F. I printInvalidEmails() verfies student email addresses and displays all invalid email addresses to the user.
	void printInvalidEmails();

	// F. I printByDegreeProgram() so it verifies student email addresses and displays all invalid email addresses to the user.
	void printByDegreeProgram(DegreeProgram degreeProgram);

	// F. My destructor so it will release memory claimed by the roster object.
	~Roster();
};

#endif 
