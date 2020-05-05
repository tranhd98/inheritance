/*
 * Title:		Person Class Method Definition
 * Purpose:		Implementation of all date class methods
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#include "person.h"
#include "date.h"
#include <sstream>
using namespace std;
/**
 * Person Constructor
 * Creates a person given its parameter.
 * @param name the name of person
 * @param birthday the birthday of person
 */
Person::Person(const string &name, const Date &birthday): _name(name), _birthDay(birthday){

}
/**
 * Person Constructor
 * Creates a person given its parameter.
 * @param name the name of person
 * @param year is the year of birthday of person
 * @param month is the month of birthday of person
 * @param day is the day of birthday of person
 */
Person::Person(const string& name, size_t year, size_t month, size_t day): _name(name), _birthDay(year, month, day){

}
/**
 * Destructor
 */
Person::~Person(){}
/**
 * String representation of Person
 * Creates a string that represents the person.
 * @return the string representation of the person
 */
string Person::ToString()const{
    stringstream retVal;
    retVal << "{name: " << _name << ", birthday: " << _birthDay.ToString() << "}";
    return retVal.str();
}
/**
 * Name Accessor
 * @return the name of the person
 */
string Person::GetName() const {
    return _name;
}
/**
 * Age Accessor
 * @return the age of the person
 */
size_t Person::GetAge() const {
    size_t retVal;
    return retVal = _birthDay.Difference(Date::Now()) / 365;
}
/**
* write to file
*  Writes a person to an output stream
*  @param output output stream to write to
*  @param person the instance of person that is going to writen to output
* @param output
*/
void Person::Write(ostream& output)const{
    output << "\nP" << " " << _name << " " << _birthDay;
}
/**
 * Read file data
 * Read from an input stream. If at anytime extraction operation fails
 * the name will be empty string, birthday will be 0,0,0. Exit(0) when it fails
 * @param input input stream to read from
 * @param person the instance where the values are going to be stored
 */
void Person::Read(istream& input){
    string name;
    Date birthDay;
    input >> name;
    if(input.fail()){
        _name = " ";
        Date tempBirthDay(0,0,0);
        _birthDay = tempBirthDay;
        exit(1);
    }
    input >> birthDay;
    if(input.fail()){
        _name = " ";
        Date tempBirthDay(0,0,0);
        _birthDay = tempBirthDay;
        exit(1);
    }
    _name = name;
    _birthDay = birthDay;
}
