#include <iostream>
#include <string>
#include "roster.h"
#include <iomanip>

using namespace std;

int main() {
    //F1.Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
    const char* introduction = "\n"
        "      WGU C867 : Scripting and Programming Applications\n"
        "      Language used: C++\n"
        "      Coded by Basudev Rijal\n"
        "      Student ID: 001365006\n";
                                                                
    cout << introduction;
    cout <<"=======================================================================================================";
    cout  <<"\n\n\n";
   

    //F2. Create an instance of the Roster class called classRoster.
    Roster* classRoster = new Roster();

    //F3. Add each student to classRoster.
    for (int i = 0; i <= 5; i++) 
    {classRoster->parse_Array(i);}  
  

  
    //F4. given pseudo-code conversion:
    cout << "     # Printing all students: \n";  
    cout << "-------------------------------------------------------------------------------------------------------\n";
    classRoster->print_All();   
    cout << "\n\n";

    cout << "     # Printing invalid emails: \n";
    cout << "-------------------------------------------------------------------------------------------------------\n";
    classRoster->print_Invalid_Email(); 
    cout << "\n\n";
    
    cout << "     # Printing average days in course for each student: \n";
    cout << "-------------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < 5; i++) {
        classRoster->print_Avg_DtC(classRoster->class_Roster_Array[i]->getSID());
    }
    cout << "\n\n\n";

    cout << "     # Printing by Degree Program : SOFTWARE \n"; 
    cout << "-------------------------------------------------------------------------------------------------------\n";
    classRoster->print_By_DP(SOFTWARE);  
    cout << "\n\n\n";
   
    cout << "     # Remove the student ID : A3 \n";
    cout << "-------------------------------------------------------------------------------------------------------\n";
    classRoster->remove_Student("A3");
    cout << "\n\n\n";

    cout << "     # Printing all students: after removing A3 \n";
    cout << "-------------------------------------------------------------------------------------------------------\n";
    classRoster->print_All();
    cout << "\n\n";

    cout << "     # Trying to remove A3 again:\n";
    cout << "-------------------------------------------------------------------------------------------------------\n";
    classRoster->remove_Student("A3");
    cout << "\n\n";

    //F5:
    //When main returns 0, the destructor is called automatically.
    //Roster::~Roster();  -->it deallocates roster from memory dynamically
  
  

    return 0;
}