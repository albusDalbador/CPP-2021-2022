#pragma once

#include "Wrapper.h"
#include <vector>

class PVec {

    friend std::ostream& operator<<(std::ostream&,const PVec&);

    private:
        std::vector<Wrapper*> data;

    public:
        void operator<<(Wrapper*);
        Wrapper& operator[](int) const;

        PVec& push_back(Wrapper*);

        void printType() const;
        int size() const;
        // std::string type() 

        ~PVec();
};


std::ostream& operator<<(std::ostream &os, const PVec &vec) {
    os << "[ ";
    for (auto item : vec.data) {
        item->print(os);
        os <<  " ";
    }
    return os << "]\n";
}

void PVec::operator<<(Wrapper *wrap) {
    (*this).push_back(wrap);
}

Wrapper& PVec::operator[](int index)const {
    return *data[index];
}

// void PVec::operator[](int index) const 

PVec& PVec::push_back(Wrapper *wrap) {
    data.push_back(wrap);
    return *this;
}

void PVec::printType() const {
    std::cout << "[ ";
    for (auto item : data) {
        std::cout << item->dataType << " ";
    }
    std::cout << "]\n";
}

int PVec::size() const {
    return data.size();
}

PVec::~PVec() {
    for (auto item : data){
        delete item;
    }
}