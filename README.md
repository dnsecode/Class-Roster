# Class-Roster
This is a C++ console application that simulates a simple student roster management system. It demonstrates core object-oriented programming principles such as encapsulation, class construction, parsing logic, and dynamic memory management. The program is designed to read, process, and manage student information from a predefined dataset.

📌 This project was developed as a portfolio piece to showcase software development and problem-solving skills in C++.

✅ Features Implemented
Parses and processes student data from a hardcoded input array
Maintains a student roster using a dynamic array of student objects
Displays all student records in a structured format
Calculates and displays the average days to complete courses per student
Identifies and lists invalid email addresses
Filters and displays students by degree program
Allows removal of students by ID with error handling
Ensures proper memory management through object destruction

📁 Project Structure
The program is organized into six source files using object-oriented design principles:
degree.h – Defines an enumeration for degree programs: SECURITY, NETWORK, SOFTWARE
student.h / student.cpp – Defines the Student class with member functions
roster.h / roster.cpp – Defines the Roster class for managing student objects
main.cpp – The program entry point and function calls for testing

🧠 Object-Oriented Design
Student Class
Private members: student ID, first name, last name, email, age, course durations, degree program
Public: constructor, getters/setters, print() function

Roster Class
Holds a dynamic array of Student*
Methods to add/remove students, validate email, calculate averages, and filter by degree program
Includes a destructor to free allocated memory

📊 Sample Data Format
The student data is initialized from a fixed array:
cpp
const string studentData[] = {
"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,[YourName],[YourLastName],[YourEmail],[YourAge],30,35,40,SOFTWARE"
};
Note: Some email addresses are intentionally malformed to test validation logic.

🔧 Functions Demonstrated in main.cpp
Displays course title, programming language, student ID, and developer name
Adds each student to the roster
Invokes functions to:
Print all students
List invalid emails
Print average days per student
Show students by degree program
Remove a student by ID with graceful error handling

💡 Skills Demonstrated
String parsing and input validation
Object-oriented programming in C++
Dynamic memory management with destructors
Modular class design and method encapsulation

🚀 How to Run
This project can be built and run using:
Visual Studio (Windows)
Xcode (macOS)
To build:
Open the .sln or .xcodeproj file in your IDE.
Ensure all six source files are included.
Build and run to see the output in the console.

A screenshot of the console output is included as proof of functionality.
![proj1](https://github.com/user-attachments/assets/dd1a81cb-3d8f-4fc7-b6e4-df43f3b35440)
![proj2](https://github.com/user-attachments/assets/9ef79712-809a-4eed-9a8e-742bb9398dae)


