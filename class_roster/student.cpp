#include <iostream>
#include "degree.h"
#include "student.h"
using namespace std;

/* D1. Create the class, Student, in the files student.h
   and student.cpp, which includes each of the following
   variables:  student ID, first name, last name, email
   address, age, an array of days to complete each course,
   degree program.*/

/* D2a. Create an accessor for each instance variable
   from part D1. */
string Student::getStudentId() const {
	return studentId; 
}
string Student::getFirstName() const {
	return firstName; 
}
string Student::getLastName() const {
	return lastName; 
}
string Student::getEmailAddress() const {
	return emailAddress; 
}
int Student::getStudentAge() const {
	return studentAge; 
}
int Student::getDaysPerCourse(int i) const {
	return daysPerCourse[i]; 
}
DegreeProgram Student::getDegreeProgram() const {
	return degreeProgram; 
}

/* D2b. Create a mutator for each instance variable
   from part D1. */
void Student::setStudentId(string str) {
	studentId = str; 
}
void Student::setFirstName(string str) {
	firstName = str; 
}
void Student::setLastName(string str) {
	lastName = str; 
}
void Student::setEmailAddress(string str) {
	emailAddress = str; 
}
void Student::setStudentAge(int age) {
	studentAge = age; 
}
void Student::setDaysPerCourse(int i, int days) {
	daysPerCourse[i] = days; 
}
void Student::setDegreeProgram(DegreeProgram degree) {
	degreeProgram = degree; 
}

/* D2d. Create a constructor using all of the input parameters
   provide in the table. */
Student::Student(string studentId, string firstName, string lastName,
	string emailAddress, int age, int daysInCourse1, int daysInCourse2,
	int daysInCourse3, DegreeProgram degreeProgram) {
	
	setStudentId(studentId);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setStudentAge(age);
	setDaysPerCourse(0, daysInCourse1);
	setDaysPerCourse(1, daysInCourse2);
	setDaysPerCourse(2, daysInCourse3);
	setDegreeProgram(degreeProgram);
	
	return;
}

Student::~Student() {

	// no subobjects to delete
	return;
}

/* D2e. Create a print() function to print specific student data. */
void Student::print() {
	
	string degree;
	
	if (this != NULL) {
		if (this->getDegreeProgram() == DegreeProgram::NETWORK) {
			degree = "NETWORK";
		}
		else if (this->getDegreeProgram() == DegreeProgram::SECURITY) {
			degree = "SECURITY";
		}
		else if (this->getDegreeProgram() == DegreeProgram::SOFTWARE) {
			degree = "SOFTWARE";
		}
		else {
			degree = "";
		}
		cout << this->getStudentId() << "\t" << this->getFirstName() << "\t"
			<< this->getLastName() << "\t" << this->getStudentAge() << "\t"
			<< "{" << this->getDaysPerCourse(0) << ","
			<< this->getDaysPerCourse(1) << "," << this->getDaysPerCourse(2) << "}\t"
			<< degree << endl;
	}
	
	return;
}