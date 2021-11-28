#include <sstream>
#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

//==================Constructor/distructor functions definations =======================================================================
Roster::Roster() { class_Roster_Array = new Student * [sizeof(class_Roster_Array)]; };    //Constructor defination
Roster::~Roster() { delete[] class_Roster_Array; };		//Distructor defination								



//=================DP functions definations ===========================================================================================
// returns strings values from index values of enumarated data "Degreeprogram"
void Roster::print_DP_string(int DP)  
{
	if (DP == 0) { cout << "SECURITY"; }
	else if (DP == 1) { cout << "NETWORK"; }
	else if (DP == 2) { cout << "SOFTWARE"; }
	else { cout << "ERROR"; }

}



//================add/remove student functions definations ============================================================================
// insert/updates student records
void Roster::add_Student(int xindex, string xSID, string xFname, string xLname, string xEmail, string xAge, int DtC0, int DtC1, int DtC2, DegreeProgram xDP) {
	
	const int index = xindex;
	Student* xRecord = new Student();

	xRecord->setSID(xSID);
	xRecord->setFname(xFname);
	xRecord->setLname(xLname);
	xRecord->setEmail(xEmail);
	xRecord->setAge(xAge);
	xRecord->setDtC(DtC0, DtC1, DtC2);
	xRecord->setDP(xDP);

	class_Roster_Array[index] = xRecord;
}

// removes student records
void Roster::remove_Student(string stID) {
	int count = sizeof(class_Roster_Array);
	bool Flag = false;

	for (int i = 0; i < count; ++i) {
		if (class_Roster_Array[i]->getSID() == stID) {
			for (int j = i; j < count-1; ++j) {
				class_Roster_Array[j] = class_Roster_Array[j + 1];
			}
			Flag = true;
			count -= 1;
			cout << "       " << "Student " << stID << " Deleted." << endl;
		}
	}

	if (Flag == false) {
		cout <<"       " << "Error: No Student found !" << endl;
	}

}



//===============parse functions definations =========================================================================================
//parse the student data table and add to class roster array using add_student() function
void Roster::parse_Array(int index) {
	
	string xRecord = studentData[index];
	int Rec_Length = xRecord.length();
	
	string xSID, xFname, xLname,xEmail, xAge, xDtC0, xDtC1, xDtC2, xDP = "";
	DegreeProgram DP; 

	int skip = 0;
	for (int i = 0; i < Rec_Length; i++) {
		char s = xRecord.at(i);
		if (s != ',')
		{
			if (skip == 0) { xSID.push_back(s); }
			else if (skip == 1) { xFname.push_back(s); }
			else if (skip == 2) { xLname.push_back(s); }
			else if (skip == 3) { xEmail.push_back(s); }
			else if (skip == 4) { xAge.push_back(s); }
			else if (skip == 5) { xDtC0.push_back(s); }
			else if (skip == 6) { xDtC1.push_back(s); }
			else if (skip == 7) { xDtC2.push_back(s); }
			else if (skip == 8) { xDP.push_back(s); }	
		}
		else { skip = skip + 1; }


		int DtC0 = atoi(xDtC0.c_str());
		int DtC1 = atoi(xDtC1.c_str());
		int DtC2 = atoi(xDtC2.c_str());

		

		if (xDP == "SECURITY") { DP = SECURITY; }
		else if (xDP == "NETWORK") { DP = NETWORK; }
		else if (xDP == "SOFTWARE") { DP = SOFTWARE; }
		else { DP = DEF; }

		add_Student(index, xSID, xFname, xLname, xEmail,xAge, DtC0, DtC1, DtC2, DP);
	}

}



//===============print functions definations =========================================================================================
//prints the entire record of a studemt
void Roster::print_All()
{
	cout << "       SID" << "\tFirst Name" << "\tLast Name" << "\tAge" << "\t    Days In Course" << "\tDegree" << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < 5; i++)
	{
		//checks if student exists or not before trying to print data
		if (class_Roster_Array[i]->getSID() != "NUL") {
			for (int j = 0; j < 8; j++)
			{

				if (j == 3) { continue; }

				if (j == 5 or j == 6)
				{
					class_Roster_Array[i]->print(j);
					cout << "-";
					continue;
				}
				class_Roster_Array[i]->print(j);
				cout << "      \t";
			}
			print_DP_string(class_Roster_Array[i]->getDP());
			cout << endl;
		}

	}
	cout << endl;
}

//prints the avarage days in class record of a studemt
void Roster::print_Avg_DtC(string xSID) {


	for (int i = 0; i < 5; ++i) {
		string check_ID = class_Roster_Array[i]->getSID();
		if (check_ID == xSID) {
			int total_days = 0;
			int avg = 0;
			for (int j = 0; j < 3; ++j) {
				total_days += class_Roster_Array[i]->getDtC(j);
			}
			avg = total_days / 3;
			cout << "      * "<<"student ID: "<<check_ID<< ",    Average Days in course: " << avg << endl;
		}
		else {};

	}
	return;

	}


//Prints invalid emails
void Roster::print_Invalid_Email() {
	
	for (int i = 0; i < 5; i++) {
		string email = class_Roster_Array[i]->getEmail();

		//email validatrion: checking for "@","." and space 
		if ((email.find('@') != string::npos) && email.find('.') != string::npos) {
			if (email.find(' ') != string::npos) {
			cout <<"      * "<< email;
			cout << endl;
			}
		}
		else {
			cout <<"      * "<< email;
			cout << endl;
		}
	}
	cout << endl;

}

//prints student entire recoed by Degree program
//prints aggregated (group) records using Degree_program
void Roster::print_By_DP(DegreeProgram degreeprogram) 
{
	cout << "       SID" << "\tFirst Name" << "\tLast Name" << "\tAge" << "\t    Days In Course" << "\tDegree" << endl;
	cout << "-------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < 5; i++) 
	{

		if (class_Roster_Array[i]->getDP() == degreeprogram) 
		{
			if (class_Roster_Array[i]->getSID() != "NUL") 
			{

					for (int j = 0; j < 8; j++)
					{

						if (j == 3) { continue; }

						if (j == 5 or j == 6)
						{
							class_Roster_Array[i]->print(j);
							cout << "-";
							continue;
						}
						class_Roster_Array[i]->print(j);
						cout << "      \t";
					}
					print_DP_string(class_Roster_Array[i]->getDP());
					cout << endl;
			}
		}
	}
}
