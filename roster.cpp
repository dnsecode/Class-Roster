#include<string>
#include<iostream>
#include <iomanip> 
#include "roster.h"
using namespace std;

// F. I parse each set of data identified in the "studentData table".
// F. I add each student object to classRosterArray.
void Roster::parseStudentData(string studentData)
{
	// F. I parse student ID
	int itemEnd = studentData.find(",");
	string id = studentData.substr(0, itemEnd);

	// F. I parse firstName
	int itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string firstName = studentData.substr(itemStart, itemEnd - itemStart);

	// F. I parse lastName
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string lastName = studentData.substr(itemStart, itemEnd - itemStart);

	// F. I parse email
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string email = studentData.substr(itemStart, itemEnd - itemStart);

	// F. I parse age
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int age = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// F. I parse daysInCourse1
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse1 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// F. I parse daysInCourse2
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse2 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// F. I parse daysInCourse3
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse3 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// F. I parse DegreeProgram degreeProgram
	itemStart = itemEnd + 1;
	itemEnd = studentData.find('/0', itemStart);
	DegreeProgram degreeProgram = UNKNOWN;
	if (studentData.substr(itemStart, itemEnd - itemStart) == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (studentData.substr(itemStart, itemEnd - itemStart) == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (studentData.substr(itemStart, itemEnd - itemStart) == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}
	else {
		degreeProgram = UNKNOWN;
	}

	// F. I added this data to the class roster
	add(id, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// F. I add() sets the instance variables and updates the roster.
void Roster::add(string id, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	// F. I build the daysInCourse array so I can add it to the roster.
	int daysInCourse[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	// F. I build the roster
	classRosterArray[++dataEnd] = new Student(id, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

// F. I remove() removes students from the roster by student ID, but if the student ID does not exist, the function prints an error message which means the student was not found.
void Roster::remove(string studentId)
{
	// F. It finds the matching student ID in classRosterArray
	int i = 0;
	bool foundStudent = false;
	for (i = 0; i < dataEnd; ++i) {
		if (classRosterArray[i]->get_id() == studentId) {

			// F. If I found the student, I need to take them out the list by moving everyone after them one spot up so it fills the empty space
			foundStudent = true;
			int j = i;
			for (j = i; j < dataEnd; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			dataEnd--;
			cout << "Student " << studentId << " removed from roster." << endl;
		}
	}
	// F. It print a message if the student ID does not exist
	if (foundStudent == false) {
		cout << "Student ID not found." << endl;
	}
}

// F. It printAll() so it loops through all the students in classRosterArray and class the print() function for each student.
void Roster::printAll()
{

	cout << left << setw(7) << "ID";
	cout << left << setw(17) << "First name";
	cout << left << setw(17) << "Last name";
	cout << left << setw(32) << "Email";
	cout << left << setw(12) << "Age";
	cout << left << setw(22) << "Days in course";
	cout << left << setw(17) << "Degree program";
	cout << endl << endl;

	// F. This calls print() function from studentClass
	int i = 0;
	for (i = 0; i <= dataEnd; ++i) {
		classRosterArray[i]->print();
	}
}

// F. printAverageDaysInCourse() prints a student's average number of days in the three courses.
void Roster::printAverageDaysInCourse(string id)
{
	int days1 = 0;
	int days2 = 0;
	int days3 = 0;
	double avgDays = 0.0;
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->get_id() == id) {
			days1 = classRosterArray[i]->get_daysInCourse()[0];
			days2 = classRosterArray[i]->get_daysInCourse()[1];
			days3 = classRosterArray[i]->get_daysInCourse()[2];
			avgDays = (days1 + days2 + days3) / 3.0;

			// Pretty output
			cout << left << setw(10) << id;
			cout << left << setw(10) << avgDays;
			cout << endl;

			// Original output
			// cout << "Student: " << id << '\t';
			// cout << "Average days: " << avgDays << endl;
		}
	}
}

// F. I void printInvalidEmails() so it verfies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	string emailToCheck = "none";
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		emailToCheck = classRosterArray[i]->get_email();

		// F. I verified '@' is present
		if (emailToCheck.find('@') == string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

		// F. I verified '.' is present
		else if (emailToCheck.find('.') == string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

		// F. I verified ' ' is not present
		else if (emailToCheck.find(' ') != string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

	}

	// F. It print if there is no invalid email addresses.
	if (invalidEmail == false) {
		cout << "None found." << endl;
	}
}

// F. I void printByDegreeProgram(DegreeProgram degreeProgram) so it prints student information for a degree program specifys by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// F. I converted degree program enum to string.
	string progamString = "UNKNOWN";
	if (degreeProgram == SECURITY) {
		progamString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		progamString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		progamString = "SOFTWARE";
	}
	else {
		progamString = "UNKNOWN";
	}


	cout << left << setw(7) << "ID";
	cout << left << setw(17) << "First name";
	cout << left << setw(17) << "Last name";
	cout << left << setw(32) << "Email address";
	cout << left << setw(12) << "Age";
	cout << left << setw(22) << "Days in course";
	cout << left << setw(17) << "Degree program";
	cout << endl << endl;

	// F. This finds and print students in the requested program.
	bool studentInProgram = false;
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->get_degreeProgram() == degreeProgram) {
			studentInProgram = true;
			classRosterArray[i]->print();
		}
	}

	// F. This prints if there are no students in that type of program.
	if (studentInProgram == false) {
		cout << "None found." << endl;
	}
}

// F. My destructor that will release memory claimed by the roster object.
Roster::~Roster()
{
	int i = 0;
	for (i = 0; i < dataEnd; ++i) {
		delete classRosterArray[i];
	}
	cout << "Roster cleared." << endl;
}