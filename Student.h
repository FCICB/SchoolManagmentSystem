#pragma once
#include <string>
using namespace std;
class Student
{
private:
	int rollNumber;
	char name[25];
	int year;
public:
	Student() = default;
	Student(int, std::string, int);

	void setRollNumber(int);
	int getRollNumber() const;

	void setName(string);
	string getName() const;

	void setDateOfBirth(int);
	int getDateOfBirth() const;

	void printInfo();


};

