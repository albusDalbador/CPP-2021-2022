#include "Grade.h"

Grade::Grade(Student stud,double grade) : _grade(grade) , _studentId(stud.getId()), _studentName(stud.getName())
{
    stud.addGrade(this);
}

Grade::~Grade()
{
    std::cout << "usuwamy ocene: " << _grade << " studenta: " << _studentName << "\n";
}

double Grade::getGrade() const {
    return _grade;
}

void Grade::print() const {
    std::cout << "Dziennik ocena=" << _grade << " student=" << _studentName << " ID=" << _studentId << "\n";
}