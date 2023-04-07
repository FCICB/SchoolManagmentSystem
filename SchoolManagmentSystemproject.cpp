// SchoolManagment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Student.h"
#include "Subject.h"
#include <fstream>
#include <filesystem>
#include "SubjectGrade.h"
#include "Managment.h"
using namespace std;
enum mainChoice {
	STUDENT = 1,
	SUBJECT,
	Terminate

};
enum StudentChoice {
	ADD = 1,
	ViewOne,
	ViewAll,
	removeStudent,
	modify,
	AddSubject,
	removeSubjectFromStudent,
	Mainmenu
};
enum SubjectChoice {
	AddSubjectchoice = 1,
	viewSubjectchoice,
	deleteSubjectchoice,
	ViewAllSubjectchoice
};

int main()
{
	Managment management;
	cout << "-----------------------------------\n";
	cout << "Please choose an option:\n"
		<< "1. for student " << endl
		<< "2. for Subjects " << endl
		<< "3. terminate" << endl;
	int choice;
	cin >> choice;
	mainChoice choose = static_cast<mainChoice> (choice);
	// Main Menu
	while (choose != mainChoice::Terminate)
	{
		// Student Menu
		if (choose == mainChoice::STUDENT) {
			int Studchoice;
			cout << "-----------------------------------\n";
			cout << "1. AddStudent" << endl
				<< "2. ViewStudent" << endl
				<< "3. ViewAllStudents" << endl
				<< "4. remove Student " << endl
				<< "5. modify Student" << endl
				<< "6. Add Subject to Student " << endl
				<< "7. Main Menu : ";
			cin >> Studchoice;
			StudentChoice  Schoose = static_cast<StudentChoice> (Studchoice);
			switch (Schoose)
			{
			case ADD:
			{
				int id, date;
				cout << "Add Student please Enter Info" << endl;
				cout << "Enter Student ID : ";
				cin >> id;
				cout << "Enter Student Name : ";
				string name;
				cin.ignore();
				getline(cin, name);
				cout << "Year Of birth : ";
				cin >> date;
				try
				{
					Student s1(id, name, date);
					management.addStudent(s1);
					cout << "\nThe Student Added Successful." << endl;
				}
				catch (const std::exception& ex)
				{
					cout << "Error : " << ex.what();
				}
			}
			break;
			case ViewOne:
			{
				int id;
				cout << "Enter Student id to view : ";
				cin >> id;
				management.viewStudent(id);
				break;
			}
			case ViewAll:
			{
				cout << "View All Students\n";
				management.viewAllStudent();
				break;
			}
			case  removeStudent:
			{
				int id;
				cout << "Enter Id : ";
				cin >> id;
				management.removeStudent(id);
				break;
			}
			case  modify:
			{
				int modifyChoice;
				cout << "1. for modify by id" << endl
					<< "2. for modify by name : ";
				cin >> modifyChoice;
				if (modifyChoice == 1) {
					int id;
					cout << "\nEnter Id : ";
					cin >> id;
					management.modifyStudent(id);
				}
				else if (modifyChoice == 2)
				{
					cout << "\nEnter Student Name : ";
					string name;
					cin.ignore();
					getline(cin, name);
					management.modifyStudent(name);
				}
				break;
			}
			case AddSubject:
			{
				int Sid, Subid;
				cout << "Enter Student id you want to Add Subject to : ";
				cin >> Sid;
				management.viewSubjects();
				cout << "Enter id of subject you want to Add to Student";
				cin >> Subid;
				if (management.isStudent(Sid));
				try
				{
					management.AddSubjectToStudent(Sid, Subid);
					management.viewStudent(Sid);
				}
				catch (const std::exception& e)
				{
					cout << "Error : " << e.what();
				}
				break;
			}

			default:
				cout << "Invalid Choice";


			}

		}




		// Subject Menu

		else if (choose == mainChoice::SUBJECT) {

			int subjchoice;
			cout << "-----------------------------------\n";
			cout << "Please choose an option:\n"
				<< "1. for Add Subject " << endl
				<< "2. for view Subject " << endl
				<< "3. delete Subject" << endl
				<< "4. ViewAll Subjects";
			cin >> subjchoice;
			SubjectChoice  Sbchoose = static_cast<SubjectChoice> (subjchoice);
			switch (Sbchoose)
			{
			case AddSubjectchoice:
			{
				int id;
				string name;
				cout << "Enter Subject id : ";
				cin >> id;
				cout << "\nEnter Subject Name : ";
				cin.ignore();
				getline(cin, name);
				try
				{
					Subject s1(id, name);
					management.AddSubject(s1);
					cout << "Subject Added Succefuly" << endl;
				}
				catch (const std::exception& ex)
				{
					cout << "Error : " << ex.what();
				}
			}
			break;
			case viewSubjectchoice:
			{
				int id;
				cout << "Enter Subject id you want to view: ";
				cin >> id;
				try
				{
					management.viewSubject(id);
				}
				catch (const std::exception& e)
				{
					cout << "Error : " << e.what();
				}
			}
			break;
			case deleteSubjectchoice:
			{
				int id;
				cout << "Enter Subject id you want to delete: ";
				cin >> id;
				try
				{
					management.deleteSubject(id);
				}
				catch (const std::exception& e)
				{
					cout << "Error : " << e.what();
				}
			}
			break;
			case ViewAllSubjectchoice:
			{
				management.viewSubjects();
			}
			break;
			default:
				cout << "Inavlid choice " << endl;
				break;
			}


		}
		cout << "-----------------------------------\n";
		cout << "Please choose an option:\n"
			<< "1. for student " << endl
			<< "2. for Subjects " << endl
			<< "3. terminate" << endl;
		cin >> choice;
		choose = static_cast<mainChoice> (choice);





	}
}
