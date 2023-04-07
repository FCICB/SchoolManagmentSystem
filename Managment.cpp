#include "Managment.h"
#include <fstream>
#include <iostream>
#include <algorithm>

Managment::Managment() {
	// Load Student data
	ifstream studentFile("StudentDataBase.dat", ios::in | ios::binary);
	if (studentFile.is_open()) {
		Student temp;
		while (studentFile.read(reinterpret_cast<char*>(&temp), sizeof(Student))) {
			allStudents.emplace_back(temp);
		}
		studentFile.close();

	}
	else {
		cout << "Error: Could not open StudentDataBase.dat new database created" << endl;
	}

	// Load data for all subjects
	ifstream subjectFile("SubjectsDataBasr.dat", ios::in | ios::binary);
	if (subjectFile.is_open()) {
		Subject temp;
		while (subjectFile.read(reinterpret_cast<char*>(&temp), sizeof(Subject))) {
			allSubjects.emplace_back(temp);
		}
		subjectFile.close();

	}
	else {
		cout << "Error: Could not open Subjects.dat new database  be created" << endl;
	}

	// Load data for all subject grades
	ifstream subjectGradeFile("SubjectGradeDataBase.dat", ios::in | ios::binary);
	if (subjectGradeFile.is_open()) {
		SubjectGrade temp;
		while (subjectGradeFile.read(reinterpret_cast<char*>(&temp), sizeof(SubjectGrade))) {
			allSubjectsGrade.emplace_back(temp);
		}
		subjectGradeFile.close();

	}
	else {
		cout << "Error: Could not open SubjectGrade.dat new database created " << endl;
	}

}
void Managment::addStudent(Student newStudent) {
	allStudents.push_back(newStudent);
}
void Managment::viewStudent(int id) {
	for (int i = 0; i < allStudents.size(); i++) {
		if (allStudents[i].getRollNumber() == id) {
			allStudents[i].printInfo();
			viewSubjectsGrades(id);
			return;
		}
	}
	cout << "invalid id student not found view" << endl;
}
void Managment::removeStudent(int id) {
	for (int i = 0; i < allStudents.size(); i++) {
		if (allStudents[i].getRollNumber() == id) {
			allStudents.erase(allStudents.begin() + i);
			return;
		}
	}

	cout << "invalid id student not found to remove " << endl;

}
enum OPTION {
	ID = 1,
	NAME,
	YEAR, TERMINATE = -1
};
void Managment::modifyStudent(int id) {
	for (int i = 0; i < allStudents.size(); i++) {
		if (allStudents[i].getRollNumber() == id) {
			cout << "\nWhat do you want to change?"
				<< "\nPress 1 for id"
				<< "\nPress 2 for Name"
				<< "\nPress 3 for year of birth"
				<< "\n-1 to break : ";
			int input;
			cin >> input;
			OPTION choose = static_cast<OPTION>(input);
			while (choose != OPTION::TERMINATE)
			{
				switch (choose)
				{
				case ID:
					cout << "Enter new Id : ";
					{
						int id;
						cin >> id;
						allStudents[i].setRollNumber(id);

					}
					break;
				case NAME:
					cout << "Enter new Name : ";
					{
						string name;
						cin.ignore();
						getline(cin, name);
						allStudents[i].setName(name);
					}
					break;
				case YEAR:
					cout << "Enter new year Of birth";
					{
						int year;
						cin >> year;
						allStudents[i].setDateOfBirth(year);
					}
					break;

				default:
					break;
				}
				cout << "\nWhat do you want to change?"
					<< "\nPress 1 for id"
					<< "\nPress 2 for Name"
					<< "\nPress 3 for year of birth"
					<< "\n-1 to break : ";
				cin >> input;
				choose = static_cast<OPTION>(input);

			}
			return;
		}
	}
	cout << "invalid id student not found";
}

void Managment::modifyStudent(string name) {
	for (int i = 0; i < allStudents.size(); i++) {
		if (allStudents[i].getName() == name) {
			cout << "\nWhat do you want to change?"
				<< "\nPress 1 for id"
				<< "\nPress 2 for Name"
				<< "\nPress 3 for year of birth"
				<< "\n-1 to break : ";
			int input;
			cin >> input;
			OPTION choose = static_cast<OPTION>(input);
			while (choose != OPTION::TERMINATE)
			{
				switch (choose)
				{
				case ID:
					cout << "Enter new Id : ";
					{
						int id;
						cin >> id;
						allStudents[i].setRollNumber(id);

					}
					break;
				case NAME:
					cout << "Enter new Name : ";
					{
						string name;
						cin.ignore();
						getline(cin, name);
						allStudents[i].setName(name);
					}
					break;
				case YEAR:
					cout << "Enter new year Of birth";
					{
						int year;
						cin >> year;
						allStudents[i].setDateOfBirth(year);
					}
					break;

				default:
					break;
				}
				cout << "\nWhat do you want to change?"
					<< "\nPress 1 for id"
					<< "\nPress 2 for Name"
					<< "\nPress 3 for year of birth"
					<< "\n-1 to break : ";
				cin >> input;
				choose = static_cast<OPTION>(input);

			}
			return;
		}
	}
	cout << "invalid id student not found";
}
bool Managment::isStudent(int id) {
	for (int i = 0; i < allStudents.size(); i++) {
		if (allStudents[i].getRollNumber() == id)
			return true;
	}
	return false;
}

Subject* Managment::isSubject(int id) {
	for (int i = 0; i < allSubjects.size(); i++) {
		if (allSubjects[i].getSubjectId() == id)
			return &allSubjects[i];
	}
	return nullptr;
}

void Managment::AddSubjectToStudent(int id, int SubjectId) {
	Subject* s1 = isSubject(SubjectId);
	if (isStudent(id) && s1 != nullptr) {
		cout << "Enter Student Grade : ";
		int grade;
		cin >> grade;
		SubjectGrade subjecGrade1(id, grade, *s1);
		allSubjectsGrade.emplace_back(subjecGrade1);
	}
	else
	{
		throw invalid_argument("Subject not found \n");
	}
}
void Managment::viewAllStudent() {
	for (int i = 0; i < allStudents.size(); i++) {
		viewStudent(allStudents[i].getRollNumber());
		cout << "-----------------------------------\n";
	}
	cout << "\n";
}
void Managment::viewSubjectsGrades(int Studentid) {
	for (int i = 0; i < allSubjectsGrade.size(); i++) {
		if (Studentid == allSubjectsGrade[i].getStudentId())
		{
			allSubjectsGrade[i].printInfo();
		}
	}
}
void Managment::removeSubjectsFromStudent(int studentId) {
	for (int i = 0; i < allSubjectsGrade.size(); i++) {
		if (studentId = allSubjectsGrade[i].getStudentGrade());
		{
			cout << "Is that subject you want to delete ?" << endl;
			allSubjectsGrade[i].printInfo();
			cout << "\n1- to delete"
				<< "\n2- for next Subject"
				<< "\n3- for terminate : ";
			int choose;
			cin >> choose;
			if (choose == 3)
				break;
			else if (choose == 2)
			{
				continue;
			}
			else if (choose == 1)
			{
				allSubjectsGrade.erase(allSubjectsGrade.begin() + i);
				break;


			}



		}
	}
}
void Managment::AddSubject(Subject s) {
	allSubjects.emplace_back(s);
}
void Managment::viewSubjects() {
	for (int i = 0; i < allSubjects.size(); i++) {
		allSubjects[i].printInfo();
		cout << "\n-----------------------------------\n";
	}
}
void Managment::viewSubject(int subjectId) {
	for (int i = 0; i < allSubjects.size(); i++) {
		if (allSubjects[i].getSubjectId() == subjectId) {
			allSubjects[i].printInfo();
			return;
		}
	}
	throw invalid_argument("Subject does not exist \n");
}
void Managment::deleteSubject(int subjectId) {
	for (int i = 0; i < allSubjects.size(); i++) {
		if (allSubjects[i].getSubjectId() == subjectId) {
			allSubjects.erase(allSubjects.begin() + i);
			cout << "Student Deleted Successfully" << endl;
			return;
		}
	}
	throw invalid_argument("Subject does not exist");
}
Managment::~Managment() {
	// save data for all Students
	ofstream studentFile("StudentDataBase.dat", ios::out | ios::binary | ios::trunc);
	if (studentFile.is_open()) {
		for (int i = 0; i < allStudents.size(); i++) {
			studentFile.write(reinterpret_cast<char*>(&allStudents[i]), sizeof(Student));
		}
		cout << "Student Data Stored Succesfully" << endl;
		studentFile.close();

	}
	else {
		cout << "Error: Could not open StudentDataBase.dat" << endl;
	}

	// save data for all subjects
	ofstream subjectFile("SubjectsDataBasr.dat", ios::out | ios::binary | ios::trunc);
	if (subjectFile.is_open()) {
		for (int i = 0; i < allSubjects.size(); i++) {
			subjectFile.write(reinterpret_cast<char*>(&allSubjects[i]), sizeof(Subject));
		}
		cout << "Sybject Data Stored Succesfully" << endl;
		subjectFile.close();
	}
	else {
		cout << "Error: Could not open Subjects.dat" << endl;
	}

	// save data for all subject grades
	ofstream subjectGradeFile("SubjectGradeDataBase.dat", ios::out | ios::binary | ios::trunc);
	if (subjectGradeFile.is_open()) {
		for (int i = 0; i < allSubjectsGrade.size(); i++) {
			subjectGradeFile.write(reinterpret_cast<char*>(&allSubjectsGrade[i]), sizeof(SubjectGrade));
		}
		cout << "Subject Grades Data Stored Succesfully";
		subjectGradeFile.close();
	}
	else {
		cout << "Error: Could not open Subjects.dat" << endl;
	}
}
