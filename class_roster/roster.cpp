#include <cstdlib>
#include <iostream>
#include "degree.h"
#include "roster.h"
#include "student.h"
using namespace std;

// E. Create a Roster class (roster.cpp)
Roster::Roster() {

	for (int i = 0; i < 5; i++) {
		classRosterArray[i] = nullptr;
	}
	
	return;
}

/* F5. Implement the destructor to release the memory that was allocated dynamically in Roster */
Roster::~Roster() {
	
	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	for (int i = 0; i < size; i++) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i] = nullptr;
		}
		delete classRosterArray[i];
	}

	return;
}

/* E2. Create a student object for each studnet in the data table and 
   populate classRosterArray. */
void Roster::parse() {

	const string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		/* A. Modify the "studentData Table" to include your personal
		   information as the last item. */
		"A5,Heather,Rauch,hruach1@wgu.edu,32,20,25,30,SOFTWARE"
	};

	/* E2a. Parse each set of data identified in the
	   "studentData Table." */
	for (int i = 0; i < 5; i++) {

		// Student ID
		size_t start = 0;
		size_t end = studentData[i].find(",", start);
		string studentId = studentData[i].substr(start, end);

		// First Name
		start = end + 1;
		end = studentData[i].find(",", start);
		string firstName = studentData[i].substr(start, end - start);

		// Last Name
		start = end + 1;
		end = studentData[i].find(",", start);
		string lastName = studentData[i].substr(start, end - start);

		// Email Address
		start = end + 1;
		end = studentData[i].find(",", start);
		string emailAddress = studentData[i].substr(start, end - start);

		// Student Age
		start = end + 1;
		end = studentData[i].find(",", start);
		int age = std::atoi(studentData[i].substr(start, end - start).c_str());

		// Days in Course 1
		start = end + 1;
		end = studentData[i].find(",", start);
		int daysInCourse1 = std::atoi(studentData[i].substr(start, end - start).c_str());

		// Days in Course 2
		start = end + 1;
		end = studentData[i].find(",", start);
		int daysInCourse2 = std::atoi(studentData[i].substr(start, end - start).c_str());

		// Days in Course 3
		start = end + 1;
		end = studentData[i].find(",", start);
		int daysInCourse3 = std::atoi(studentData[i].substr(start, end - start).c_str());

		// Degree Program
		start = end + 1;
		end = studentData[i].find(",", start);
		DegreeProgram degreeProgram;
		if (studentData[i].substr(start, end - start) == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		else if (studentData[i].substr(start, end - start) == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		else if (studentData[i].substr(start, end - start) == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}

		/* E2b. Add each student object to classRosterArray */
		add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
			daysInCourse3, degreeProgram);
	}
}

/* E3a. Define the function, add. */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, 
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int index = 0;
	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	for (int i = 0; i < size; i++) {
		if (classRosterArray[i] == nullptr) {
			index = i;
			break;
		}
	}
	
	classRosterArray[index] = new Student(studentID, firstName, lastName,
		emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3,
		degreeProgram);
}

/* E3b. Define the function, remove. */
void Roster::remove(string studentId) {
	
	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	bool found = false;
	
	for (int i = 0; i < size; i++) {
		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentId() == studentId) {
				found = true;
				for (int j = i; j < size - 1; j++) {
					classRosterArray[j] = classRosterArray[j + 1];
				}
				classRosterArray[size - 1] = nullptr;
				break;
			}
		}
	}

	if (!found) {
		cout << "The student with the ID: " << studentId << " was not found.";
	}
}

/* E3c. Define the function, printAll.  */
void Roster::printAll() {

	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	for (int i = 0; i < size; i++) {
		classRosterArray[i]->print();
	}
	cout << endl;
}

/* E3d. Define the function, printAverageDaysInCourse. */
void Roster::printAverageDaysInCourse(string studentId) {
	
	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	for (int i = 0; i < size; i++) {
		
		int total = 0;
		
		if (classRosterArray[i]->getStudentId() == studentId) {
			for (int j = 0; j < 3; j++) {
				total += classRosterArray[i]->getDaysPerCourse(j);
			}
			cout << "Student ID: " << studentId << ", Average Days In Course: " << total / 3 << endl;
		}
	}
}

/* E3e. Define the function, printInvalidEmails. */
void Roster::printInvalidEmails() {
	
	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	int at, period, space;
	
	for (int i = 0; i < size; i++) {
		
		string email = classRosterArray[i]->getEmailAddress();
		at = email.find('@');
		period = email.find('.');
		space = email.find(' ');

		if (!(at >= 0) || !(period >= 0) || !(space < 0)) {
			cout << email << " - is invalid." << endl;
		}
	}
	cout << endl;
}

/* E3f. Define the function,printByDegreeProgram. */
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	string degree;
	size_t size = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	if (degreeProgram == DegreeProgram::NETWORK) {
		degree = "NETWORK";
	}
	else if (degreeProgram == DegreeProgram::SECURITY) {
		degree = "SECURITY";
	}
	else if(degreeProgram == DegreeProgram::SOFTWARE) {
		degree = "SOFTWARE";
	}

	for (int i = 0; i < size; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}