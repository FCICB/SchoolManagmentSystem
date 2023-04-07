#pragma once
#include <string>
using namespace std;
class Subject
{
private:
	int subjectId;
	char subjectName[20];
public:
	Subject() = default;
	Subject(int id, string name);
	void setSubjectId(int);
	int getSubjectId()const;
	void setSubjectName(string);
	string getSubjectName()const;
	void printInfo()const;

};

