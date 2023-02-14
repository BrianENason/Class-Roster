
#pragma once
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;
/*
class Roster {
private:
	static const int numStudents = 5;
	Student* classRosterArray[numStudents]; //array of pointers to students because they will be declared dynamically
	int currentStudentIndex = -1;
	int daysInCourse1 = 0;

public:
	Roster();
	//int ParseStudents(std::string row);
	//void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgramEnum degreeProgram);
	void parseThenAdd();
	//void remove(string studentID);
	void printAll();
	
	void printAverageDaysInCourse();
	void printInvalidEmails();
	//void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};
*/


class Roster {
private:
	int indexNumber;
	int maxMinSize;
	Student** classRosterArray;
	const char delim = ',';

public:
	Roster();
	Roster(int maxMinSize);

	Student* getStudentAt(int index);
	void parseAndAdd(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram theDegreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};
