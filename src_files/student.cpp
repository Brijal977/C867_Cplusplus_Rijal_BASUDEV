#pragma once

#include <string>
#include <iostream>
#include "student.h"
   
using namespace std;

// D2. Student constructor
Student::Student()
{
    this->SID = "";
    this->Fname = "";
    this->Lname = "";
    this->Email = "";
    this->Age = "";
    for (int i = 0; i < 3; i++) { this->DtC[i] = 0; }
    this->DP = DEF;
};


// GETTERS- definations
// Each functio specifically returns one attribute value for 1 student
string Student::getSID() { return SID; }
string Student::getFname() { return Fname; }
string Student::getLname() { return Lname; }
string Student::getEmail() { return Email; }
string Student::getAge() { return Age; }
int Student::getDtC(int index) { return DtC[index]; }
DegreeProgram Student::getDP() { return DP; }


// SETTERS
// Each functions specifically insert/update one attribute value for 1 student
void Student::setSID(string SID) { this->SID = SID; }
void Student::setFname(string Fname) { this->Fname = Fname; }
void Student::setLname(string Lname) { this->Lname = Lname; }
void Student::setEmail(string Email) { this->Email = Email; }
void Student::setAge(string Age) { this->Age = Age; }
void Student::setDtC(int x, int y, int z) { this->DtC[0] = x; this->DtC[1] = y; this->DtC[2] = z; }   // Assigns all three array values
void Student::setDP(DegreeProgram degree) { this->DP = degree; }   // Enumarated value (label)


// PRINTER
// Each functions specifically prints one attribute value for 1 student
void Student::print(int i)
{
    if (i == 0) { cout <<"       " << SID; }  // Spaces for presentation (margin)
    else if (i == 1) { cout  << Fname; }
    else if (i == 2) { cout << Lname; }
    else if (i == 3) { cout << Email; }
    else if (i == 4) { cout << Age; }
    else if (i == 5) { cout << DtC[0]; }
    else if (i == 6) { cout << DtC[1]; }
    else if (i == 7) { cout << DtC[2]; }
    else if (i == 8) { cout << DP; }
} 