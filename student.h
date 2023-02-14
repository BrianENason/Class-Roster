#pragma once
#include <string>
#include "degree.h"

using namespace std;


class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	DegreeProgram theDegreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress,
		int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram theDegreeProgram);
	void displayStudent();
	string getID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int getDaysInCourse1();
	int getDaysInCourse2();
	int getDaysInCourse3();
	DegreeProgram getDegreeProgram();

	void setID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string emailAddress);
	void setAge(int age);
	void setDaysInCourse1(int daysInCourse1);
	void setDaysInCourse2(int daysInCourse2);
	void setDaysInCourse3(int daysInCourse3);
	
	~Student();
};