
class Roster {
public:
    void parse(string);
    Student* classRosterArray[5];
    void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, degreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(degreeProgram deg);
    ~Roster();
    int addPosition = -1;

};