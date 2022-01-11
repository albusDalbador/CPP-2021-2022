#include "functions.h"

//for Sin class
double Sin::operator()(double x) const  {
    return sin(_a*x + _b);
}   

//for Sqrt class
double  Sqrt::operator()(double x) const {
    return sqrt(x);
}

Sqrt::Sqrt() {}

Sin::Sin(double a,double b) : _a(a), _b(b) {}

//for Linear class
double Linear::operator()(double x) const {
    return _a*x + _b;
}

std::ostream& operator<< (std::ostream&os, const Linear lin) {
    os << "f(x) = " << lin._a << "*x" ;

    if (lin._b < 0) os << lin._b;
    else os << "+" << lin._b;

    return os;
}

Linear::Linear(double a, double b) : _a(a), _b(b) {}

