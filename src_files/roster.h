#ifndef roster_h
#define roster_h
#include "student.h"
#include<array>
#include<string>

using namespace std;

// A. Modify the “studentData Table” to include your personal information as the last item.
const string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Rijal,Basudev,brijal1@wgu.edu,25,15,25,35,SOFTWARE"
};

/*
E.Create a Roster class (roster.cpp) by doing the following :
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2.  Create a student object for each student in the data tableand populate classRosterArray.
        a.Parse each set of data identified in the “studentData Table.”
        b.Add each student object to classRosterArray.

3.  Define the following functions :
        a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) 
            that sets the instance variables from part D1 and updates the roster.

        b.  public void remove(string studentID)  that removes students from the roster by student ID.If the student ID does not exist, the function prints an error message indicating that the
            student was not found.

        c. public void printAll() that prints a complete tab - separated list of student data in the provided format : A1[tab] First Name : John[tab] Last Name : Smith[tab] Age : 20[tab]daysInCourse
            : {35, 40, 55} Degree Program : Security.The printAll() function should loop through all the students in classRosterArrayand call the print() function for each student.

        d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses.The student is identified by the studentID parameter.
        e.  public void printInvalidEmails() that verifies student email addressesand displays all invalid email addresses to the user.
        f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
*/

class Roster {
public:

    Roster();      // constructor
    ~Roster();    // destructor


    Student** class_Roster_Array;        // E1a.
    void parse_Array(int index);         // E2a. E2b.

    //E3a. E3b.
    void add_Student(int index, string xSID, string xFName, string xLName, string xEmail, string xAge, int DtC1, int DtC2, int DtC3, DegreeProgram DP);
    void remove_Student(string xSID);

    //E3c. E3d. E3e. E3f.
    void print_All();                       // prints all student data
    void print_Avg_DtC(string xSID);        // prints average days in/to course
    void print_Invalid_Email();             // prints all invalid emails 
    void print_By_DP(DegreeProgram xDP);    // prints students of a particular degree program

private:
    //returns strings values from index values of enumarated data "Degreeprogram"
    void print_DP_string(int xDP);
};

#endif