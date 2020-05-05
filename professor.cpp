/*
 * Title:		Person Class Declaration
 * Purpose:		Implementation of all date class methods
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#include "date.h"
#include "person.h"
#include "professor.h"
#include <sstream>
using namespace std;
/**
 * Professor Constructor
 * Creates a professor given its parameter.
 * @param name the name of professor
 * @param birthday the birthday of professor
 * @param department the department of professor
 */
Professor::Professor(const string& name, const Date& birthday, const string& department)
    :Person(name, birthday), _department(department), _hireDate(Date::Now()), _rank(ASSISTANT_PROFESSOR), _salary(60000.00){

}
/**
 * Professor Constructor
 * Creates a professor given its parameter.
 * @param name the name of professor
 * @param birthday the birthday of professor
 * @param department the department of professor
 * @param hireDate the hireDate of professor
 * @param rank the rank of professor base on difference between date now and hireDate
 * @param salary the salary of professor base on rank
 */
Professor::Professor(const string& name, const Date& birthday, const string& department, const Date & hireDate)
    :Person(name, birthday), _department(department), _hireDate(hireDate){
    if(hireDate.Difference(Date::Now()) < 1826){
        _rank = ASSISTANT_PROFESSOR;
        _salary = 60000.00;
    }
    else if(hireDate.Difference(Date::Now()) > 1825 && hireDate.Difference(Date::Now()) < 3652){
        _rank = ASSOCIATE_PROFESSOR;
        _salary = 70000.00;
    }
    else if(hireDate.Difference(Date::Now()) > 3652){
        _rank = PROFESSOR;
        _salary = 75000.00;
    }
}
/**
 * Professor Constructor
 * Creates a professor given its parameter.
 * @param name the name of professor
 * @param birthday the birthday of professor
 * @param department the department of professor
 * @param hireDate the hireDate of professor
 * @param rank the rank of professor
 * @param salary the salary of professor
 */
Professor::Professor(const string& name, const Date& birthday, const string& department, const Date& hireDate, Rank rank, float salary)
    :Person(name, birthday), _department(department), _hireDate(hireDate), _rank(rank), _salary(salary){

}
/**
 * destructor
 */
Professor::~Professor(){

}
/**
 * String representation of Professor
 * Creates a string that represents the professor.
 * @return the string representation of the professor
 */
string Professor::ToString()const{
    stringstream retVal;
    retVal << "{Person: " << Person::ToString() << ", department: " << _department << ", rank: " << _rank << ", hire-date: " << _hireDate.ToString() << ", salary: " << _salary << "}";
    return retVal.str();
}
/**
 * Read file data
 * Read from an input stream. If at anytime extraction operation fails
 * the name and department will be empty string, birthday, hiredate will be 0,0,0, and the rank will be 0. Exit(0) when it fails
 * @param input input stream to read from
 * @param student the instance where the values are going to be stored
 */
void Professor::Read(istream& input){
    string name;
    Date birthDay;
    string department;
    Date hireDate;
    int rankLevel;
    float salary;
    if(input.fail()){
        _name = " ";
        Date tempBirthDay(0,0,0);
        _birthDay = tempBirthDay;
        _department ="";
        rankLevel = 0;
        _salary = 0.0;
        exit(1);
    }
    input >> name >> birthDay >> department >> hireDate >> rankLevel >> salary;
    _name = name;
    _birthDay = birthDay;
    _department = department;
    _rank = static_cast<Rank>(rankLevel);
    _hireDate = hireDate;
    _salary = salary;
}

/**
* write to file
*  Writes a professor to an output stream
*  @param output output stream to write to
*  @param professor the instance of professor that is going to writen to output
* @param output
*/

void Professor::Write(ostream& output)const{
    output << "\nR" << " " << _name << " " << _birthDay << " " << _department << " " << _hireDate << " " << _rank << " " << _salary;
}

/**
 * raising the professor
 * using percentage and salary to raising percent of current salary of professor
 * @param percentage
 */
void Professor::Raise(float percentage) {
    _salary += ((_salary * percentage)/ 100);
}
/**
 * Promote Professor
 * Upgrading Professor to next level rank
 */
void Professor::Promote() {
    if(_rank == ASSISTANT_PROFESSOR){
        _rank = ASSOCIATE_PROFESSOR;
    }
    else{
        _rank = PROFESSOR;
    }
}
/**
 * rank Accessor
 * @return the rank of the professor
 */
Rank Professor::GetRank() const {
    return _rank;
}
/**
 * salary Accessor
 * @return the salary of the professor
 */
float Professor::GetSalary() const {
    return _salary;
}


