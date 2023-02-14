#include <iostream>
#include "student.h"

using namespace std;

//First we have the empty constructor
Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	age = 0;
	daysInCourse1 = 0;
	daysInCourse2 = 0;
	daysInCourse3 = 0;
	theDegreeProgram = DegreeProgram::SECURITY;
}

//Next we have the full constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram theDegreeProgram) {
	this->studentID = studentID; // You can get rid of "this->" by making the variable a different name (consider string tempStudentID = studentID, etc.)
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse1 = daysInCourse1;
	this->daysInCourse2 = daysInCourse2;
	this->daysInCourse3 = daysInCourse3;
	this->theDegreeProgram = theDegreeProgram;
}

void Student::displayStudent() {
	cout << this->studentID << "\t"; // this is my interpretation of "tabed", might need to change the thing!
	cout << "First Name: " << this->firstName << "\t";
	cout << "Last Name: " << this->lastName << "\t";
	//cout << this->emailAddress << "   ";
	cout << "Age: " << this->age << "\t";
	cout << "daysInCourse: {" << this->daysInCourse1 << ", ";
	cout << this->daysInCourse2 << ", ";
	cout << this->daysInCourse3 << "} ";
	//since DegreeTypeStrings is an enum, we have to cast it into an int first and then run it through cout
	cout << "Degree Program: " << degreeProgramString[(int)this->theDegreeProgram] << endl << endl;
}

string Student::getID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmail() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int Student::getDaysInCourse1() {
	return daysInCourse1;
}
int Student::getDaysInCourse2() {
	return daysInCourse2;
}
int Student::getDaysInCourse3() {
	return daysInCourse3;
}
DegreeProgram Student::getDegreeProgram() {
	return theDegreeProgram;
}

void Student::setID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string emaiAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysInCourse1(int daysInCourse1) {
	this->daysInCourse1 = daysInCourse1;
}
void Student::setDaysInCourse2(int daysInCourse2) {
	this->daysInCourse2 = daysInCourse2;
}
void Student::setDaysInCourse3(int daysInCourse3) {
	this->daysInCourse3 = daysInCourse3;
}

//Deconstructor if it ever becomes necessary
Student::~Student() {
	
	//Use only if something is added later that does declare something dynamically. Then you need to fill it out.

}
