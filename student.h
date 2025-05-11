#include<string>
#include<iostream>
#include "degree.h"
using namespace std;


#ifndef student_h
#define student_h

// Part E. For the Student class, do the following:
// E. Create the classStudent in the files student.h and student.cpp, which includes each of the following private variables, using the correct data type for each;
class Student {
private:
	string firstName;
	string lastName;
	string id;
	string email;
	int age;
	const static int numCourses = 3;
	int daysInCourse[numCourses];
	DegreeProgram degreeProgram;

public:
	// My constructor
	Student();

	// My constructor using all of the parameters input provided in the student table in this order
	Student(string id, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);

	// My destructor
	~Student();

	// I created a getter for each instance variable which I type string:
	string get_id();
	string get_firstName();
	string get_lastName();
	string get_email();
	int get_age();
	int* get_daysInCourse();
	DegreeProgram get_degreeProgram();

	// I created a setter for each instance variable which I type void:
	void set_id(string id);
	void set_firstName(string firstName);
	void set_lastName(string lastName);
	void set_email(string email);
	void set_age(int age);
	void set_daysInCourse(int daysInCourse[]);
	void set_degreeProgram(DegreeProgram degreeProgram);

	// I type print() so it can print specific student data.
	void print();
};

#endif 
