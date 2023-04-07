#include "SubjectGrade.h"
#include <stdexcept>
#include <iostream>
SubjectGrade::SubjectGrade(int i, float g, Subject s1) {
	setStudentId(i);
	setStudentGrade(g);
	s = s1;
}
void SubjectGrade::setStudentId(int id) {
	if (id > 0)
		StudentId = id;
	else
	{
		throw invalid_argument("Student id inavlid");
	}
}
int SubjectGrade::getStudentId() const {
	return StudentId;
}
void SubjectGrade::setStudentGrade(float g) {
	if (g >= 0 && g <= 100)
		grade = g;
	else
	{
		throw invalid_argument("Grade inavlid");
	}
}

float SubjectGrade::getStudentGrade() const {
	return grade;
}
void SubjectGrade::printInfo() const {
	cout << "\nSubject Info " << endl;
	s.printInfo();
	cout << "\nStudent Grade : " << getStudentGrade() << endl;
}