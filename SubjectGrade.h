#pragma once
#include "Subject.h"
class SubjectGrade
{
private:
	int StudentId;
	float grade;
	Subject s;
public:
	SubjectGrade() = default;
	SubjectGrade(int, float, Subject);
	void setStudentId(int);
	int getStudentId()const;

	void setStudentGrade(float);
	float getStudentGrade()const;
	void printInfo()const;



};