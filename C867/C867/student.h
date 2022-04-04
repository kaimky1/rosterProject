#pragma once
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;


class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int numOfDays[3] = { 0,0,0 };
    degreeProgram degree;
public:
    Student(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int aNumOfDays[], degreeProgram aDegree);
    void setStudentID(string aStudentID);
    void setFirstName(string aFirstName);
    void setLastName(string aLastName);
    void setEmail(string aEmail);
    void setAge(int aAge);
    void setNumOfDays(int aNumOfDays[]);
    void setDegreeProgram(degreeProgram aDegree);

    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getNumOfDays();
    degreeProgram getDegree();

    void print();

    void displayHeader();


};


