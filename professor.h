/*
 * Title:		Professor Class Declaration
 * Purpose:		A class to represent a simple Professor
 * Author:		Hung Tran
 * Date:		May 04, 2020
 */

#ifndef SCHOOL_INHERITANCE_PROFESSOR_H
#define SCHOOL_INHERITANCE_PROFESSOR_H

#include "date.h"

enum Rank {ASSISTANT_PROFESSOR, ASSOCIATE_PROFESSOR, PROFESSOR};

class Professor : public Person{
    string _department;
    Date _hireDate;
    Rank _rank;
    float _salary;
public:
    Professor(const string&, const Date&, const string&);
    Professor(const string&, const Date&, const string&, const Date & );
    Professor(const string&, const Date&, const string&, const Date&, Rank, float);
    virtual ~Professor();
    virtual string ToString()const;
    virtual void Read(istream&);
    virtual void Write(ostream&)const;
    void Raise(float);
    void Promote();
    Rank GetRank()const;
    float GetSalary()const;
};

#endif
