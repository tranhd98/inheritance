/*
 * Title:		Person Class Declaration
 * Purpose:		A class to represent a simple date
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#ifndef SCHOOL_INHERITANCE_PERSON_H
#define SCHOOL_INHERITANCE_PERSON_H

#include "date.h"

class Person {
protected:
    string _name;
    Date _birthDay;
public:
    Person(const string&, const Date&);
    Person(const string&, size_t, size_t, size_t);
    virtual string ToString()const;
    string GetName()const;
    size_t GetAge()const;
    virtual void Read(istream&);
    virtual void Write(ostream&)const;
    virtual ~Person();
};


#endif
