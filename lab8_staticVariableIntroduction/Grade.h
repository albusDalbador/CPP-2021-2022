#ifndef  _GRADE_H_
#define _GRADE_H_

#include "Student.h"
#include <iostream>

class Student;

class Grade
{
private:
    const double _grade;
    std::string _studentName;
    const int _studentId;
public:
    Grade(Student , double );

    ~Grade();

    void print() const ;

    double getGrade() const;
    
};
 


#endif