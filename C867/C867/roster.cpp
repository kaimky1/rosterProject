#include <iostream>
#include "student.h"
#include "roster.h"

using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degree) {
	int daysArray[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++addPosition] = new Student(studentID, firstName, lastName, email, age, daysArray, degree);
}

void Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= addPosition; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            Student* stu = classRosterArray[i];
            classRosterArray[i] = classRosterArray[addPosition];
            classRosterArray[addPosition] = stu;
            cout << studentID << " has been removed.\n";
            addPosition--;
        }
    }
        if (!found) cout << studentID << " not found.\n";
}

void Roster::printAll() {
	cout << "Displaying all students: \n";
	for (int i = 0; i <= addPosition; i++)
	{
		classRosterArray[i]->print();
	}
	cout << '\n';
}

void Roster::printAverageDaysInCourse(string studentID)
{
	cout << "Average Days In Course For " << studentID << ":\t";
	for (int i = 0; i <= Roster::addPosition; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			cout << ((double)classRosterArray[i]->getNumOfDays()[0]
				+ (double)classRosterArray[i]->getNumOfDays()[1]
				+ (double)classRosterArray[i]->getNumOfDays()[2]) / 3.0
				<< '\n';
		}
	}
}

void Roster::printByDegreeProgram(degreeProgram deg) {
    for (int i = 0; i <= Roster::addPosition; i++) {
         //deg = Roster::classRosterArray[i]->getDegree();
         if (classRosterArray[i]->getDegree() == deg)
            // cout << "Hi";
            classRosterArray[i]->print();
            
    }
    
};
void Roster::printInvalidEmails() {
	bool none = true;
	for (int i = 0; i <= Roster::addPosition; i++) {
		string email = Roster::classRosterArray[i]->getEmail();
		if (email.find('@') == string::npos
			|| email.find(' ') != string::npos
			|| email.find('.') == string::npos)
			cout << "Displaying invalid emails: " << email << " is invalid.\n" << endl;
	}
	};

void Roster::parse(string data) {
    size_t rhs = data.find(",");
    string studentID = data.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string firstName = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string lastName = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string email = data.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int age = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int numOfDays1 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int numOfDays2 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    int numOfDays3 = stoi(data.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = data.find(",", lhs);
    string strDegreeProgram = data.substr(lhs, rhs - lhs);

    degreeProgram deg = degreeProgram::SECURITY;
    if (strDegreeProgram == "NETWORK") {
        deg = degreeProgram::NETWORK;
    }
    else if (strDegreeProgram == "SOFTWARE") {
        deg = degreeProgram::SOFTWARE;
    }
    add(studentID, firstName, lastName, email, age, numOfDays1, numOfDays2, numOfDays3, deg);
}

Roster::~Roster() {
    for (int i = 0; i <= Roster::addPosition; i++)
    {
        delete Roster::classRosterArray[i];
        Roster::classRosterArray[i] = nullptr;
    }
}


