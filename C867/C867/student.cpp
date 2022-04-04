#include <iostream>
#include "student.h"
using namespace std;

Student::Student(string aStudentID, string aFirstName, string aLastName, string aEmail, int aAge, int aNumOfDays[], degreeProgram aDegree)
{
    setStudentID(aStudentID);
    setFirstName(aFirstName);
    setLastName(aLastName);
    setEmail(aEmail);
    setAge(aAge);
    setNumOfDays(aNumOfDays);
    setNumOfDays(aNumOfDays);
    setDegreeProgram(aDegree);
}
void Student::setStudentID(string aStudentID) {
    studentID = aStudentID;
}
void Student::setFirstName(string aFirstName) {
    firstName = aFirstName;
}

void Student::setLastName(string aLastName) {
    lastName = aLastName;
}

void Student::setEmail(string aEmail) {
    email = aEmail;
}
void Student::setAge(int aAge) {
    age = aAge;
}

void Student::setNumOfDays(int aNumOfDays[]) {
    numOfDays[0] = aNumOfDays[0];
    numOfDays[1] = aNumOfDays[1];
    numOfDays[2] = aNumOfDays[2];
}

void Student::setDegreeProgram(degreeProgram aDegreeProgram) {
    degree = aDegreeProgram;
}

string Student::getStudentID() {
    return studentID;
}

string Student::getFirstName() {
    return firstName;
}

string Student::getLastName() {
    return lastName;
}

string Student::getEmail() {
    return email;
}

int Student::getAge() {
    return age;
}

int* Student::getNumOfDays() {
    return numOfDays;
}

degreeProgram Student::getDegree() {
    return degree;
};

void Student::print() {
    cout << studentID << '\t';
    cout << firstName << '\t';
    cout << lastName << '\t';
    cout << email << '\t';
    cout << age << '\t';
    cout << numOfDays[0] << '\t';
    cout << numOfDays[1] << '\t';
    cout << numOfDays[2] << '\t';
    cout << degreeProgramStrings[(int)degree];
    cout << endl;
}

void Student::displayHeader() {
    cout << "Student ID\tFirst Name\tLast Name\tEmail\tAge\tnumOfDays\tDegree\n";
}