#include "Subject.h"
#include <stdexcept>
#include <iostream>
Subject::Subject(int id, string name) {
	setSubjectName(name);
	setSubjectId(id);
}
void Subject::setSubjectId(int i) {
	if (i < 0) {
		throw invalid_argument("Subject id not valid");
	}
	else
	{
		subjectId = i;
	}
}
int Subject::getSubjectId() const {
	return subjectId;
}
void Subject::setSubjectName(string n) {
	strcpy_s(subjectName, n.c_str());
}
string Subject::getSubjectName() const {
	return string(subjectName);
}
void Subject::printInfo()const {
	cout << "\nSubject Name : " << getSubjectName()
		<< "\nSubject Id : " << getSubjectId() << endl;
}