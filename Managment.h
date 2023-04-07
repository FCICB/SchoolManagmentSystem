#pragma once
#include "Student.h"
#include "Subject.h"
#include "SubjectGrade.h"
#include <vector>
class Managment
{
private:
	vector<Student> allStudents;
	vector<Subject> allSubjects;
	vector<SubjectGrade> allSubjectsGrade;
	Subject* isSubject(int);
public:
	Managment();

	// Student Functions

	void addStudent(Student);
	void viewStudent(int id);
	void viewAllStudent();
	void removeStudent(int);
	void modifyStudent(int);
	void modifyStudent(string);
	void AddSubjectToStudent(int studentId, int SubjectId);
	void removeSubjectsFromStudent(int);
	bool isStudent(int);

	// Subject Functions

	void viewSubjectsGrades(int);
	void AddSubject(Subject);
	void viewSubject(int subjectId);
	void deleteSubject(int subjectId);
	void viewSubjects();


	~Managment();
};

