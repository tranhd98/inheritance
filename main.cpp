/*
 * Title:		Main Class Declaration Person Class, Professor Class, and Student Class.
 * Purpose:		To generate all member classes and implement functions in each including in school for example Person Class, Professor Class, and Student Class.
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#include "date.h"
#include "person.h"
#include "student.h"
#include "professor.h"


#include <iostream>
#include <vector>
#include <fstream>
using std::cin;
using std::cerr;
using std::cout;
using std::endl;
using std::vector;
using namespace std;
size_t Menu();

int main(int argc, char* argv[]) {
	vector<Person*> people; // This is the only vector you need, remember to release the memory
	int userOption;
	while ( (userOption = Menu()) != 15) {
        if (userOption == 1) {            // Add Person
            string name;
            Date tempDate;
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> tempDate;
            size_t day = tempDate.GetDay();
            size_t month = tempDate.GetMonth();
            size_t year = tempDate.GetYear();
            Date birthDate(year, month, day);
            while (birthDate.IsInvalidDate()) {
                cout << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> tempDate;
                size_t day = tempDate.GetDay();
                size_t month = tempDate.GetMonth();
                size_t year = tempDate.GetYear();
                Date tempDate2(year, month, day);
                birthDate = tempDate2;
            }
            people.push_back(new Person(name, birthDate));
            cout << "Person inserted in position: " << people.size() - 1 << endl;
        }else if (userOption == 2) {        // Add Student
            string name;
            Date tempDate;
            string major;
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> tempDate;
            size_t day = tempDate.GetDay();
            size_t month = tempDate.GetMonth();
            size_t year = tempDate.GetYear();
            Date birthDate(year, month, day);
            while (birthDate.IsInvalidDate()) {
                cout << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> tempDate;
                size_t day = tempDate.GetDay();
                size_t month = tempDate.GetMonth();
                size_t year = tempDate.GetYear();
                Date tempDate2(year, month, day);
                birthDate = tempDate2;
            }
            cout <<"Major: ";
            cin >> major;
            people.push_back(new Student(name, Date(birthDate), major));
            cout << "Student inserted in position: " << people.size() - 1 << endl;
		}else if (userOption == 3){		// Add Professor
            string name;
            Date tempDate;
            string Department;
            Date tempHireDate;
            cout << "Name: ";
            cin >> name;
            cout << "Birth date yyyy mm dd: ";
            cin >> tempDate;
            size_t day = tempDate.GetDay();
            size_t month = tempDate.GetMonth();
            size_t year = tempDate.GetYear();
            Date birthDate(year, month, day);
            while (birthDate.IsInvalidDate()) {
                cout << "Invalid Date!" << endl;
                cout << "Birth date yyyy mm dd: ";
                cin >> tempDate;
                size_t day = tempDate.GetDay();
                size_t month = tempDate.GetMonth();
                size_t year = tempDate.GetYear();
                Date tempDate2(year, month, day);
                birthDate = tempDate2;
            }
            cout << "Department: ";
            cin >> Department;
            cout << "Hire date yyyy mm dd: ";
            cin >> tempHireDate;
            size_t day1 = tempHireDate.GetDay();
            size_t month1 = tempHireDate.GetMonth();
            size_t year1 = tempHireDate.GetYear();
            Date HireDate(year1, month1, day1);
            while (HireDate.IsInvalidDate()) {
                cout << "Invalid Date!" << endl;
                cout << "Hire date yyyy mm dd: ";
                cin >> tempHireDate;
                size_t day = tempHireDate.GetDay();
                size_t month = tempHireDate.GetMonth();
                size_t year = tempHireDate.GetYear();
                Date tempHireDate2(year, month, day);
                HireDate = tempHireDate2;
            }
            people.push_back(new Professor(name, Date(birthDate), Department, HireDate));
            cout << "Professor inserted in position: " << people.size() - 1 << endl;
		}else if (userOption == 4){		// List All People
            for(Person* person : people){
                cout << person->ToString() << endl;
            }
		}else if (userOption == 5){		// Show Students Report
            for(Person * person: people){
                if(dynamic_cast<Student*>(person) != nullptr){
                    cout << person->ToString() << endl;
                }
            }
		}else if (userOption == 6){		// Show Professor Report
            for(Person * person: people){
                if(dynamic_cast<Professor*>(person) != nullptr){
                    cout << person->ToString() << endl;
                }
            }
		}else if (userOption == 7){		// Show !Professor !Student
            for(Person* person: people){
                if(dynamic_cast<Student*>(person) == nullptr && dynamic_cast<Professor*>(person) == nullptr){
                    cout << person->ToString() << endl;
                }
            }
		}else if (userOption == 8){// Calculate Average GPA
            int total = 1;
            float Average = 0.0;
            for(Person * person: people){
                if(dynamic_cast<Student*>(person) != nullptr){
                    Student* student = dynamic_cast<Student*>(person);
                    Average = (Average + student->GetGPA()) / total;
                    total++;
                }
            }
            cout << "The average GPA of the students is: " << Average << endl;
		}else if (userOption == 9){ //Calculate Average Salary
            int total = 1;
            float Average = 0.0;
            for(Person * person: people){
                if(dynamic_cast<Professor*>(person) != nullptr){
                    Professor* professor = dynamic_cast<Professor*>(person);
                    Average = (Average + professor->GetSalary()) / total;
                    total++;
                }
            }
            cout << "The average salary of the professors is: " << Average << endl;
		}else if (userOption == 10){	// Input Grades to Student
            if(people.size() == 0){
                cout << " No input at all " << endl;
            }
            else {
                bool checked = false;
                for (size_t i = 0; i < people.size(); i++) {
                    if (dynamic_cast<Student *>(people[i]) != nullptr) {
                        cout << i << " " << people[i]->ToString() << endl;
                        checked = true;
                    }
                }
                if (checked == false) {
                    cout << " No input of Student. Please add" << endl;
                } else {
                    size_t number;
                    float grade;
                    int credits;
                    cout << "Number of student to input grades to: ";
                    cin >> number;
                    while (cin.fail() || number > people.size() - 1 ||
                           dynamic_cast<Student *>(people[number]) == nullptr) {
                        if (number > people.size() - 1) {
                            cout << "Position out of range!" << endl;
                            cout << "Number of student to input grades to: ";
                        } else if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cerr << "Incorrect input!" << endl;
                            cout << "Number of student to input grades to: ";
                        } else if (dynamic_cast<Student *>(people[number]) == nullptr) {
                            cout << "Person" << people[number]->ToString() << " not a student" << endl;
                            cout << "Number of student to input grades to: ";
                        }
                        cin >> number;
                    }
                    cout << "Grade of the student [0.0 to 4.0 scale]:";
                    cin >> grade;
                    while (cin.fail() || grade > 4.0 || grade < 0.0) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cerr << "Incorrect input!" << endl;
                            cout << "Grade of the student [0.0 to 4.0 scale]: ";
                        } else if (grade > 4.0 || grade < 0.0) {
                            cout << "Invalid grade value, make sure [0.0, 4.0]" << endl;
                            cout << "Grade of the student [0.0 to 4.0 scale]: ";
                        }
                        cin >> grade;
                    }
                    cout << "Credits {1, 2, 3, 4, 5}: ";
                    cin >> credits;
                    while (cin.fail() || credits > 5.0 || credits < 0.0) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cerr << "Incorrect input!" << endl;
                            cout << "Credits {1, 2, 3, 4, 5}: ";
                        } else if (credits > 5.0 || credits < 0.0) {
                            cout << "Invalid grade value, make sure Credits {1, 2, 3, 4, 5}:" << endl;
                            cout << "Credits {1, 2, 3, 4, 5}: ";
                        }
                        cin >> credits;
                    }
                    dynamic_cast<Student *>(people[number])->AddGrade(grade, credits);
                }
            }
		}else if (userOption == 11){// Promote Professor
            if(people.size() == 0){
                cout << " No input at all" << endl;
            }
            else {
                bool checked = false;
                for (size_t i = 0; i < people.size(); i++) {
                    if (dynamic_cast<Professor *>(people[i]) != nullptr) {
                        cout << i << " " << people[i]->ToString() << endl;
                        checked = true;
                    }
                }
                if (checked == false) {
                    cout << " No input of Professor. Please add" << endl;
                } else {
                    size_t number;
                    cout << "Number of professor to promote: ";
                    cin >> number;
                    while (cin.fail() || number > people.size() - 1 ||
                           dynamic_cast<Professor *>(people[number]) == nullptr) {
                        if (number > people.size() - 1) {
                            cout << "Position out of range!" << endl;
                            cout << "Number of professor to promote: ";
                        } else if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cerr << "Incorrect input!" << endl;
                            cout << "Number of professor to promote: ";
                        } else if (dynamic_cast<Professor *>(people[number]) == nullptr) {
                            cout << "Person" << people[number]->ToString() << " not a professor" << endl;
                            cout << "Number of professor to promote: ";
                        }
                        cin >> number;
                    }
                    dynamic_cast<Professor *>(people[number])->Promote();
                }
            }
		}else if (userOption == 12){	// Give Raise to Professor
            if(people.size() == 0) {
                cout << " No input at all" << endl;
            }
            else {
                bool checked = false;
                for (size_t i = 0; i < people.size(); i++) {
                    if (dynamic_cast<Professor *>(people[i]) != nullptr) {
                        cout << i << " " << people[i]->ToString() << endl;
                        checked = true;
                    }
                }
                if (checked == false) {
                    cout << " No input for Professor. Please add" << endl;
                } else {
                    size_t number;
                    cout << "Number of professor to give raise: ";
                    cin >> number;
                    while (cin.fail() || number > people.size() - 1 ||
                           dynamic_cast<Professor *>(people[number]) == nullptr) {

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cerr << "Incorrect input!" << endl;
                            cout << "Number of professor to give raise: ";
                        } else if (number > people.size() - 1) {
                            cout << "Position out of range!" << endl;
                            cout << "Number of professor to give raise: ";
                        } else if (dynamic_cast<Professor *>(people[number]) == nullptr) {
                            cout << "Person" << people[number]->ToString() << " not a professor" << endl;
                            cout << "Number of professor to give raise: ";
                        }
                        cin >> number;
                    }
                    float raising;
                    cout << "Raise to the professor [0.0, 50.0]: ";
                    cin >> raising;
                    while (cin.fail() || raising > 50.0 || raising < 0.0) {
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(255, '\n');
                            cerr << "Incorrect input!" << endl;
                            cout << "Raise to the professor [0.0, 50.0]: ";
                        } else if (raising > 50.00 || raising < 0.0) {
                            cout << "Invalid grade value, make sure [0.0, 50.0]" << endl;
                            cout << "Raise to the professor [0.0, 50.0]: ";
                        }
                        cin >> raising;
                    }
                    dynamic_cast<Professor *>(people[number])->Raise(raising);
                }
            }
		}else if (userOption == 13){	// Load from File
            ifstream infile;
            string filename = "";
            string prefix;
            cout << "Input Filename: ";
            cin >> filename;
            infile.open(filename);
            if(!infile.is_open()){
                cout << "Unable to open file " << filename << endl;
            }
            else {
                while (!infile.eof()) {
                    infile >> prefix;
                    if (prefix == "P") {
                        Person *p = new Person("", Date(0, 0, 0));
                        p->Read(infile);
                        people.push_back(p);
                    }
                    else if (prefix == "S") {
                        Person *p = new Student("", Date(0, 0, 0));
                        p->Read(infile);
                        people.push_back(p);
                    }
                    else if (prefix == "R"){
                        Person *p = new Professor("", Date(0, 0, 0),"");
                        p->Read(infile);
                        people.push_back(p);
                    }
                }
            }
            infile.close();
		}else if (userOption == 14){	// Write to File
            ofstream outfile;
            string nameFile = " ";
            cout << "Enter name of your file: ";
            cin >> nameFile;
            outfile.open(nameFile);
            if(!outfile){
                cerr << "Error: file could not be opened" << endl;
                exit(1);
            }
            for(Person * person : people){
                person->Write(outfile);
            }
            outfile.close();
		}
	}
	for(Person * p : people){
	    delete p;
	}
	return 0;
}

size_t Menu(){
	int option = 0;
	while(true){
		cout << "-------------------------------------------" << endl;
		cout << "1. Add a Person" << endl;
		cout << "2. Add a Student" << endl;
		cout << "3. Add a Professor" << endl;
		cout << "4. List all People" << endl;
		cout << "5. Show Students Report" << endl;
		cout << "6. Show Professors Report" << endl;
		cout << "7. Show People (not Professors or Students)" << endl;
		cout << "8. Calculate all Students Average GPA" << endl;
		cout << "9. Calculate all Professors Average Salary" << endl;
		cout << "10. Input Grades to Student" << endl;
		cout << "11. Promote Professor" << endl;
		cout << "12. Give Raise to Professor" << endl;
		cout << "13. Load Data from File" << endl;
		cout << "14. Write Data to File" << endl;
		cout << "15. Exit" << endl;

		cin >> option;
		if (cin.fail()){
			cin.clear();
			cin.ignore(255, '\n');
			cerr << "Incorrect input!" << endl;
			continue;
		}
		if (option < 1 || option > 15){
			cerr << "Incorrect menu option!" << endl;
			continue;
		}
		break;
	}
	cout << endl;
	return static_cast<size_t>(option);
}
