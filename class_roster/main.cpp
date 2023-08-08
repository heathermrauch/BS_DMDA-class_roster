#include <iostream>
#include "roster.h"
using namespace std;

/* F. Demonstrate the program's required functionality by adding a main
   function in main.cpp. */
int main()
{
    /* F1. Print out to the screen, via your application, the course title,
       the programming language used, your WGU studing ID, and your name. */
    cout << "C867-Scripting & Programming: Applications\n"
         << "Language: C++\n"
         << "Student ID: 001388379\n"
         << "Name: Heather Rauch\n" << endl;

    /* F2. Create an instance of the Roster class called classRoster. */
    Roster classRoster;

    /* F3. Add each student to classRoster. */
    classRoster.parse();

    /* F4. Convert pseudo code to complete the rest of the main() function */
    cout << "Displaying all student:" << endl;
    classRoster.printAll();

    cout << "Displaying invalid emails:" << endl << endl;
    classRoster.printInvalidEmails();

    size_t size = sizeof(classRoster.classRosterArray) / sizeof(classRoster.classRosterArray[0]);
    for (int i = 0; i < size; i++) {
        string studentId = classRoster.classRosterArray[i]->getStudentId();
        classRoster.printAverageDaysInCourse(studentId);
    }
    cout << endl;
    
    cout << "Showing students in degree program: SOFTWARE" << endl << endl;
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    cout << "Removing A3:" << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();

    cout << "Removing A3 again\n" << endl;
    classRoster.remove("A3"); //expected to print error message
    
    classRoster.~Roster();
    cout << "\nDONE.\n";
    
    return 0;
}