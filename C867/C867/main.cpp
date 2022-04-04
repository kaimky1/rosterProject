// C867.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "student.h"
#include "roster.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "C867 Scripting and Programming - Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: " << "009452799" << endl;
    cout << "Full Name:" << " Mark Yonashiro\n" << endl;

    const string studentData[] =

    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Mark,Yonashiro,myonash@hawaii.edu,24,24,34,56,SOFTWARE" };

    Roster classRoster;
    for (int i = 0; i < 5; i++)
        classRoster.parse(studentData[i]);

   classRoster.printAll();
   classRoster.printInvalidEmails();
   classRoster.printAverageDaysInCourse("A1");
   classRoster.printAverageDaysInCourse("A2");
   classRoster.printAverageDaysInCourse("A3");
   classRoster.printAverageDaysInCourse("A4");
   classRoster.printAverageDaysInCourse("A5");
   cout << '\n';
   classRoster.printByDegreeProgram(degreeProgram::SOFTWARE);
    cout << '\n';
    classRoster.remove("A3");
    cout << '\n';
    classRoster.printAll();
    cout << '\n';
    classRoster.remove("A3");
    cout << '\n';
    return 0;
}
