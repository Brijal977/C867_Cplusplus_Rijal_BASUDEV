#ifndef student_h
#define student_h
#include <iostream>
#include "degree.h"
#include<string>

using namespace std;
/*
D.  For the Student class, do the following:
  1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
    •  student ID
    •  first name
    •   last name
    •  email address
    •  age
    •  array of number of days to complete each course
    •  degree program

  2.  Create each of the following functions in the Student class:
    a.  an accessor (i.e., getter) for each instance variable from part D1
    b.  a mutator (i.e., setter) for each instance variable from part D1
    c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
    d.  constructor using all of the input parameters provided in the table
    e.  print() to print specific student data
*/


class Student {
public:
    //D2d : Constructor
    Student();

    //D2a : Getters
    string getSID();
    string getFname();
    string getLname();
    string getEmail();
    string getAge();
    int getDtC(int index);  
    DegreeProgram getDP(); 

    //D2b: Setters
    void setSID(string SID);
    void setFname(string Fname);
    void setLname(string Lname);
    void setEmail(string Email);
    void setAge(string Age);
    void setDtC(int x, int y, int z);
    void setDP(DegreeProgram DP);

    //D2e: Print item
    void print(int item);

private:
    //D1: Attributes
    string SID;             // SID :-> Student ID
    string Fname;           // Fname :-> First Name
    string Lname;           // Lname :-> Last Name
    string Email;           // Email :->Email Address
    string Age;             //Age
    int DtC[3];             // DtC :-> Days to/in Class
    DegreeProgram DP;       //DP :-> Degree Program
};

#endif