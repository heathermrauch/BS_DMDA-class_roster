#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

/* E. Create a Roster class. */
class Roster {
public:

	/* E1. Create an array of pointers, classRosterArray, to hold the data
	   provided in the "studentData Table". */
	Student* classRosterArray[5];
	
	/* E2a. Parse each set of data identified in the "studentData Table". */
	void parse();

	/* E3a. Define the function, add. */
	void add(string studentID, string firstName, string lastName, 
		string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);

	/* E3b. Define the function, remove. */
	void remove(string studentID);

	/* E3c. Define the function, printAll. */
	void printAll();

	/* E3d. Define the function, printAverageDaysInCourse. */
	void printAverageDaysInCourse(string studentID);

	/* E3e. Define the function, printInvalidEmails. */
	void printInvalidEmails();

	/* E3f. Define the function, printByDegreeProgram */
	void printByDegreeProgram(DegreeProgram degreeProgram);

	Roster();
	~Roster();
};

#endif