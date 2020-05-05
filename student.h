/*
 * Title:		Student Class Declaration
 * Purpose:		A class to represent a student class as derived class of person
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#ifndef SCHOOL_INHERITANCE_STUDENT_H
#define SCHOOL_INHERITANCE_STUDENT_H

#include "date.h"

class Student : public Person{
    string _major;
    size_t _credits;
    float _gpa;
public:
    Student(const string&, const Date&);
    Student(const string&, const Date&, const string&);
    virtual ~Student();
    virtual string ToString()const;
    virtual void Read(istream&);
    virtual void Write(ostream&)const;
    void AddGrade(float, size_t);
    float GetGPA()const;
    size_t GetCredits()const;
};

#endif
