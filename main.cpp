#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

//A small chunk of code to separate each of the called functions in the output for easier reading
void printLine() {
	cout << endl;

	for (int i = 0; i < 61; ++i) {
		cout << "-";
	}
	cout << endl << endl;
}

int main() {

	const int numStudents = 5;

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Brian,Nason,bnason1@wgu.edu,35,20,25,30,SOFTWARE"
	};


	
	//This is where my student Information is going:
	cout << "Course Title:      SCRIPTING AND PROGRAMMING - APPLICATIONS - C867" << endl;
	cout << "Program Language:  C++" << endl;
	cout << "My WGU Student ID: ++++++++" << endl;
	cout << "My Name:           Brian Nason" << endl << endl;

	printLine();

	//This will call the empty constructor
	Roster classRoster(numStudents);

	//This for loop parses through the strings and creates a student object from each one and adds it to the roster
	for (int i = 0; i < numStudents; ++i) {
		classRoster.parseAndAdd(studentData[i]);
	}
	
	
	//This prints all the students through the parsed data
	cout << "\nThis is the class roster after the data is parsed into it...\n" << endl;
	classRoster.printAll();

	printLine();
	
	//This will look through the parsed data for emails that are entered incorrectly
	cout << "\nChecking for invalid Email(s)...\n" << endl;
	classRoster.printInvalidEmails();

	printLine();
	
	//This will loop through the data and print out the average days in course for all the students one-by-one
	cout << "\nThe following students have, on average, this many days left in their courses...\n" << endl;
	for (int i = 0; i < numStudents; ++i) {
		string tempStudentID = "";
		tempStudentID = classRoster.getStudentAt(i)->getID();
		classRoster.printAverageDaysInCourse(tempStudentID);	
	}

	printLine();

	//This will print out the data of who is a member of a particular degree program (in this case, SOFTWARE)
	cout << "\nThe following students are included in the specified degree program...\n" << endl;
	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
	
	printLine();

	//This will remove a student from the roster based on their ID number
	cout << "\nWe can remove a student from the roster based on their supplied ID number...\n" << endl;
	classRoster.remove("A3");

	printLine();

	//This will reprint the roster to make sure that the student has been deleted and the roster updated
	cout << "\nLet's view the roster to check and see if the student you wanted deleted no longer shows up...\n" << endl;
	classRoster.printAll();

	printLine();

	//This will check to make sure the student "A3" entered above doesn't appear anywhere
	cout << "\nFor piece of mind, let's try removing that student once again and see what happens...\n" << endl;
	classRoster.remove("A3");

	printLine();

	system("pause");
	
	return 0;
}
