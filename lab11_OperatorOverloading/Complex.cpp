#include "Complex.h"

Complex operator+(const Complex&first,const Complex&second) {
    return Complex(first._re + second._re, first._im + second._im);
}

void Complex::operator=(double num) {
    this->_re = num;
}


void Complex::print(std::string name) const {
    std::cout << name;

    // std::cout << _re << " " << _im << "\n";

    if (_im == 0) {
        std::cout << _re << "\n";
    }
    else if (_re == 0) {
        std::cout << _im << "i\n";
    } else {
        std::cout << _re << " + " << _im << "i\n";
    }
}