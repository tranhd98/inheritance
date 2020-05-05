/*
 * Title:		Student Class Method Definition
 * Purpose:		Implementation of all student class methods
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#include "date.h"
#include "person.h"
#include "student.h"
#include <sstream>
using namespace std;

/**
 * Student Constructor
 * Creates a student given its parameter.
 * @param name
 * @param birthday from date composition
 */
Student::Student(const string & name, const Date & birthday)
    : Person(name, birthday),_major("undecided"), _credits(0), _gpa(0.0){
}
/**
 * Date Constructor with major variable
 * Creates a Student with given its parameter
 * @param name
 * @param birthday from date composition
 * @param major
 */
Student::Student(const string& name, const Date& birthday, const string& major)
    : Person(name, birthday),  _major(major), _credits(0), _gpa(0.0){
}
/**
 * Destructor
 */
Student::~Student(){}
/**
 * string representation of student
 * @return the string that represent of the student
 */
string Student::ToString()const{
    stringstream retVal;
    retVal << "{Person: " << Person::ToString() << ", major: " << _major << ", gpa: " << _gpa << ", credits: " << _credits << "}";
    return retVal.str();
}
/**
 * Read file data
 * Read from an input stream. If at anytime extraction operation fails
 * the name and major will be empty string, birthday will be 0,0,0, and the credits will be 0. Exit(0) when it fails
 * @param input input stream to read from
 * @param student the instance where the values are going to be stored
 */
void Student::Read(istream& input){
    string name;
    Date birthDay;
    string major;
    size_t credits;
    float gpa;
    if(input.fail()){
        _name = " ";
        Date tempBirthDay(0,0,0);
        _birthDay = tempBirthDay;
        _major = " ";
        credits = 0;
        gpa = 0.0;
        exit(0);
    }
    input >> name >> birthDay >> major >> credits >> gpa;
    _name = name;
    _birthDay = birthDay;
    _major = major;
    _credits = credits;
    _gpa = gpa;
}
/**
 * write to file
 *  Writes a student to an output stream
 *  @param output output stream to write to
 *  @param stdent the instance of student that is going to writen to output
 * @param output
 */
void Student::Write(ostream& output)const{
    output << "\nS" << " " << _name << " " << _birthDay << " " << _major << " " <<_credits << " " << _gpa;
}
/**
 * addGrade
 * adding grade to instance student and updating with old gpa.
 * @param grade
 * @param credits
 */
void Student::AddGrade(float grade, size_t credits){
    float temp1;
    temp1 = _credits * _gpa;
    _credits += credits;
    _gpa = (temp1 + (grade * credits)) / (_credits);
}
/**
 * gpa Accessor
 * @return the gpa of the student
 */
float Student::GetGPA()const{
    return _gpa;
}
/**
 * credit Accessor
 * @return the credit of the student
 */
size_t Student::GetCredits()const{
    return _credits;
}
