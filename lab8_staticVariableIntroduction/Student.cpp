#include "Student.h"

int Student::staticId = 1;

Student::Student() : _name("STUDENT"), currentId(staticId++), gradeListLength(new int), gradeList(new Grade **)
{
    
    gradeListLength[0] = 0;
    gradeList[0] = nullptr;
}


Student::Student(std::string name ) : _name(name), currentId(staticId++) , gradeListLength(new int), gradeList(new Grade **)
{
    gradeListLength[0] = 0;
    gradeList[0] = nullptr;
}

Student::Student(const Student &oldStud) : currentId(oldStud.getId()), gradeList(oldStud.gradeList),  gradeListLength(oldStud.gradeListLength)
{
    _isCopy = true;
    gradeList[0] = oldStud.gradeList[0];
    gradeListLength[0] = oldStud.gradeListLength[0];
}

Student::~Student()
{
    if (!_isCopy) {
        delete  *gradeList;
        delete gradeList;
        delete gradeListLength;

        std::cout << "usuwamy studenta: " << _name << "\n";
    }

}

void Student::print() const {
    std::cout << _name << " ID=" << currentId << " oceny: ";

    if (gradeListLength)
    for (int i = 0 ; i < (*gradeListLength); i++) {
        std::cout << " " << (*gradeList)[i] -> getGrade();
    }

    std::cout << "\n";
}

void Student::addGrade(Grade *grade) const{

    Grade **temp = new Grade *[(*gradeListLength) + 1];
     
    
    for (int i = 0 ; i < (*gradeListLength); i++) {
        temp[i] = (*gradeList)[i];
    }

    if ((*gradeList) != nullptr) {
        delete [] (*gradeList);
    }

    *gradeList = temp;
    (*gradeList)[*gradeListLength] = grade;
    (*gradeListLength)++;

    return;
}

std::string Student::getName() const {
    return _name;
}

int Student::getId() const {
    return currentId;
}

