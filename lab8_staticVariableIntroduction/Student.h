#ifndef  _STUDENT_H_
#define _STUDENT_H_

#include "Grade.h"

#include <string>
#include <iostream>


class Grade;

class Student {
    private:
        bool _isCopy = false;
        static int staticId;
        const int currentId;
        const std::string _name;
        Grade *** gradeList = nullptr;
        int *gradeListLength = nullptr;

    public:
        void print() const;

        void addGrade(Grade *) const;

        Student(const Student&);

        Student(std::string);

        int getId() const;

        std::string getName() const;

        Student();

        ~Student();
};

#endif