#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "degree.h"
using namespace std;

/* D1. Create the class, Student, in files student.h and
   student.cpp, ... */
class Student {

private:
	/* D1. ...which includes the variables: 
	   student ID, first name, last name, email address,
	   student age, an array of number of days to complete
	   each course, degree program */
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int studentAge;
	int	daysPerCourse[3];
	DegreeProgram degreeProgram;

public:
	/* D2a. Create an accessor for each instance variable
	   from part D1. */
	string getStudentId() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getStudentAge() const;
	int getDaysPerCourse(int) const;
	DegreeProgram getDegreeProgram() const;

	/* D2b. Create a mutator for each instance variable
	   from part D1. */
	void setStudentId(string);
	void setFirstName(string);
	void setLastName(string);
	void setEmailAddress(string);
	void setStudentAge(int);
	void setDaysPerCourse(int, int);
	void setDegreeProgram(DegreeProgram);

	/* D2d. create a constructor using all of the input
	   parameters provided in the table. */
	Student(string studentID, string firstName, string lastName,
		string emailAddress, int age, int daysInCourse1, int daysInCourse2,
		int daysInCourse3, DegreeProgram degreeProgram);
	~Student();

	/* D2e. Create a print() to print specific student data. */
	void print();
};

#endif