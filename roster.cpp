#include "roster.h"
#include <iostream>

using namespace std;

//The empty constuctor
Roster::Roster() {
	this->maxMinSize = 0;
	this->indexNumber = -1;
	this->classRosterArray = nullptr;
}

//The constructor
Roster::Roster(int maxMinSize) {
	this->maxMinSize = maxMinSize;
	this->indexNumber = -1;
	this->classRosterArray = new Student*[maxMinSize];
}


Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}
/*
This code parses through the provided data in main and pulls out the info by category - I referenced code by youTube user Doctor Krypto 
in his Soldier Roster series as well as his Book Repository series to come up with this code to parse the data as his explanations
of why he was doing what he was doing helped bring a lot of concepts together in my head. I also referenced various chapters in the zyBook 
dealing with enumClasses and data parsing. As far as I know, this is the only section that I was using outside references to create a solution.
*/

void Roster::parseAndAdd(string studentDataIn) {
	if (indexNumber < maxMinSize) { //check to prevent it from taking in more info than was allocated
		indexNumber = indexNumber + 1;

		int end = studentDataIn.find(delim); //sets the integer 'end' with the int value from the first occurance of the delimiter
		string studentID = studentDataIn.substr(0, end); //puts all the data up to the delim (set by the variable 'end') into the string variable studentID

		int start = end + 1; //tells the loop to 'start' at the index value just after the first found delimiter
		end = studentDataIn.find(delim, start);
		string firstName = studentDataIn.substr(start, end - start);

		start = end + 1;
		end = studentDataIn.find(delim, start);
		string lastName = studentDataIn.substr(start, end - start);

		start = end + 1;
		end = studentDataIn.find(delim, start);
		string emailAddress = studentDataIn.substr(start, end - start);

		start = end + 1;
		end = studentDataIn.find(delim, start);
		int age = stoi(studentDataIn.substr(start, end - start));

		start = end + 1;
		end = studentDataIn.find(delim, start);
		int daysInCourse1 = stoi(studentDataIn.substr(start, end - start));

		start = end + 1;
		end = studentDataIn.find(delim, start);
		int daysInCourse2 = stoi(studentDataIn.substr(start, end - start));

		start = end + 1;
		end = studentDataIn.find(delim, start);
		int daysInCourse3 = stoi(studentDataIn.substr(start, end - start));

		start = end + 1;
		DegreeProgram theDegreeProgram = DegreeProgram::SECURITY; //sets an initial value for the temp variable of DegreeProgram type to "SECURITY"
		string degreeprogram = studentDataIn.substr(start, studentDataIn.length() - start);
		//This will set the value for the enum class depending on the input from the string and using the degreeprogram string to match up.
		if (degreeprogram == "SECURITY") {
			theDegreeProgram = DegreeProgram::SECURITY;
		}

		else if (degreeprogram == "NETWORK") {
			theDegreeProgram = DegreeProgram::NETWORK;
		}

		else if (degreeprogram == "SOFTWARE") {
			theDegreeProgram = DegreeProgram::SOFTWARE;
		}

		else { // If, for some reason, there is not a degree program found, then it will exit this (as that is missing data)
			return;
		}

		//This will send all the new values for these variables to the "add" program below
		add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, theDegreeProgram); 
	}
}

//used to all all the parsed data into the classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram theDegreeProgram) {
	classRosterArray[indexNumber] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, theDegreeProgram);
}

void Roster::remove(string studentID) {
	cout << "Looking for student " << studentID << "..." << endl;
	cout << "..." << endl;
	bool isID = false; //This will help control the check to make sure the student ID searching for exists
	for (int i = 0; i < maxMinSize; ++i) {
		string tStudentID = this->classRosterArray[i]->getID();
		if (tStudentID == studentID) {
			isID = true;
			cout << "Student " << tStudentID << " is being removed from the Roster." << endl;
			int numDel = stoi(studentID.substr(1, 1));
			delete this->classRosterArray[i];
			for (int j = maxMinSize; j > numDel; --j) {
				this->classRosterArray[i] = this->classRosterArray[i + 1];
				++i;
			}
			indexNumber--;

			cout << " ..... " << endl;
			cout << "Student " << studentID << " has been removed from the Roster!" << endl;

		}

	}
	//this will make sure that, if the studentID doesn't exist, that the user knows about it
	if (isID == false) {
		cout << "Student with this ID not found" << endl;
	}

}

//When the printAll funtion is called in main, it will send it through this gate to the displaystudent function in studentclass
void Roster::printAll() {
	for (int i = 0; i <= this->indexNumber; ++i) {
		(this->classRosterArray)[i]->displayStudent();
	}
}



//This will take in the average days in course, add them, divide by 3, and output the result
void Roster::printAverageDaysInCourse(string studentID) {
	int daysForCourse1 = 0;
	int daysForCourse2 = 0;
	int daysForCourse3 = 0;
	int totalDays = 0;

	for (int i = 0; i < maxMinSize; ++i) {
		string tStudentId = classRosterArray[i]->getID();
		if (studentID == tStudentId) {
			daysForCourse1 = classRosterArray[i]->getDaysInCourse1();
			daysForCourse2 = classRosterArray[i]->getDaysInCourse2();
			daysForCourse3 = classRosterArray[i]->getDaysInCourse3();
			totalDays = (daysForCourse1 + daysForCourse2 + daysForCourse3) / 3;
			cout << "Student " << studentID << "'s average days in their courses is: " << totalDays << endl << endl;
		}
	}
}

//This will print out any emails that don't have proper formatting (spaces, too many/few @, etc.)
void Roster::printInvalidEmails() {
	cout << "The following list is comprised of those email entries that are invalid due to either:\n";
	cout << "a) They lack the @ symbol,\n";
	cout << "b) They lack the period,\n";
	cout << "c) They have a space incorrectly inserted in them." << endl << endl;

	string tempEmail = "";
	
	char atSymbol = '@';
	char period = '.';
	char space = ' ';
	
	for (int i = 0; i < maxMinSize; ++i) {
		string tempEmail = classRosterArray[i]->getEmail();

		if (tempEmail.find(atSymbol) == string::npos) {
			cout << classRosterArray[i]->getLastName() << ", " << classRosterArray[i]->getFirstName() << ": " << tempEmail << " -- Missing @ symbol!" << endl;
		}

		else if (tempEmail.find(period) == string::npos) {
			cout << classRosterArray[i]->getLastName() << ", " << classRosterArray[i]->getFirstName() << ": " << tempEmail << " -- Missing . symbol!" << endl;
		}

		else if (tempEmail.find(space) != string::npos) {
			cout << classRosterArray[i]->getLastName() << ", " << classRosterArray[i]->getFirstName() << ": " << tempEmail << " -- Has an illegal space!" << endl;
		}
				
	}
	
	cout << endl;
	cout << "Check finished. " << endl;
}

//This will print out the students by their degree program that is specified by an enumerated type
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	string degreeString = degreeProgramString[(int)degreeProgram];

	cout << "Students in the " << degreeString << " program are: " << endl << endl;

	for (int i = 0; i < maxMinSize; ++i) {
		DegreeProgram tDegree = classRosterArray[i]->getDegreeProgram();
		
		if (tDegree == degreeProgram) {
			cout << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << endl;
		}
	}
}

//This is the destructor to clear the memory. Because of the deleted student (A3), it should only have to destroy 4 objects.
Roster::~Roster() {
	for (int i = 0; i <= indexNumber; ++i) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
		cout << "\nStudent " << i + 1 << " Deleted!" << endl;
	}
	cout << "\nProgram is done!\n" << endl;
	cout << "Data is Deleted!\n" << endl;
	cout << "Have a nice day!\n" << endl;
	for (int j = 0; j < 4; ++j) {
		cout << ". " << endl;
	}
	cout << "\nGoodbye!" << endl;
}