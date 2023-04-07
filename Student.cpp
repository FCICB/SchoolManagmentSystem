#include "Student.h"
#include <stdexcept>
#include <iostream>
#include <iomanip>
using namespace std;
Student::Student(int id, string name, int date) {
	setRollNumber(id);
	setName(name);
	setDateOfBirth(date);
}

void Student::setRollNumber(int r) {
	if (r > 0)
		rollNumber = r;
	else
	{
		throw invalid_argument("Roll Number can not be negative\n");
	}
}
int Student::getRollNumber()const {
	return rollNumber;
}

void Student::setName(string n) {
	strncpy_s(name, n.c_str(), sizeof(name));
	name[sizeof(name) - 1] = '\0';
}
string Student::getName() const {
	return string(name);
}

void Student::setDateOfBirth(int y) {
	if (y < 0) {
		throw invalid_argument("year invalid");
	}
	else
	{
		year = y;
	}
}
int Student::getDateOfBirth()const {
	return year;
}

void Student::printInfo() {
	cout << "\nName : " << getName()
		<< "\nId : " << getRollNumber()
		<< "\nyear of birth : " << getDateOfBirth() << endl;
}
