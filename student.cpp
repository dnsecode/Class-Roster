#include<string>
#include<iostream>
#include <iomanip> 
#include "student.h"
using namespace std;

// part E.2 Create each of the following functions in the Student class:

// My default contstructor
Student::Student() {
	this->id = "none";
	this->firstName = "none";
	this->lastName = "none";
	this->email = "none";
	this->age = 0;
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = UNKNOWN;
}

//  My constructor using all of the parameters input provided in the student table
Student::Student(string id, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

// I created an accessor (getter) for each instance variable
string Student::get_id() {
	return this->id;
}
string Student::get_firstName() {
	return this->firstName;
}
string Student::get_lastName() {
	return this->lastName;
}
string Student::get_email() {
	return this->email;
}
int Student::get_age() {
	return this->age;
}
int* Student::get_daysInCourse() {
	return this->daysInCourse;
}
DegreeProgram Student::get_degreeProgram() {
	return this->degreeProgram;
}

// I created a mutator (setter) for each instance variable
void Student::set_id(string id) {
	this->id = id;
}
void Student::set_firstName(string firstName) {
	this->firstName = firstName;
}
void Student::set_lastName(string lastName) {
	this->lastName = lastName;
}
void Student::set_email(string email) {
	this->email = email;
}
void Student::set_age(int age) {
	this->age = age;
}
void Student::set_daysInCourse(int daysInCourse[]) {
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void Student::set_degreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// a print() function to print specific student data in the provided format.
void Student::print() {

	// I converted the degree program enum to string
	string programString = "UNKNOWN";
	if (degreeProgram == SECURITY) {
		programString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		programString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		programString = "SOFTWARE";
	}
	else {
		programString = "UNKNOWN";
	}


	cout << left << setw(7) << id;
	cout << left << setw(17) << firstName;
	cout << left << setw(17) << lastName;
	cout << left << setw(32) << email;
	cout << left << setw(12) << age;
	cout << left << setw(7) << daysInCourse[0];
	cout << left << setw(7) << daysInCourse[1];
	cout << left << setw(12) << daysInCourse[2];
	cout << left << setw(17) << programString;
	cout << endl;
}

// My destructor
Student::~Student() {

}