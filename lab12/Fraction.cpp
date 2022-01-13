#include "Fraction.h"

//constructors
Fraction::Fraction(int x,int y) {
    int reduct = std::gcd(x,y);

    if (x < 0 && y < 0) {
        _meter = -x / reduct;
        _delimeter = -y / reduct;
    } else {
        _meter = x / reduct;
        _delimeter = y / reduct;
    }
}

Fraction::Fraction(int x) : _meter(x), _delimeter(1) {}


//operators
std::ostream& operator<<(std::ostream &os, const Fraction &frac) {
    if (frac._meter < 0 || frac._delimeter < 0) {
        os << "-" << abs(frac._meter);
        if (frac._delimeter != 1)  os << "/" << abs(frac._delimeter);
    } else {
        os << abs(frac._meter);
        if (frac._delimeter != 1) os << "/" << frac._delimeter;
    }
    
    return os;
}


Fraction::operator double() {
    return (double)this->_meter / (double)this->_delimeter;
}


Fraction Fraction::operator*(const Fraction &frac) const {
    return Fraction(this->_meter * frac._meter, this->_delimeter * frac._delimeter);
}


void Fraction::operator*=(const Fraction &frac) {
    this->_meter *= frac._meter;
    this->_delimeter *= frac._delimeter;
}


Fraction Fraction::operator+(const Fraction &frac) const {
    int lowest = std::lcm(frac._delimeter,this->_delimeter);

    return Fraction(this->_meter *  lowest/this->_delimeter + frac._meter * lowest/frac._delimeter, lowest);
}


Fraction Fraction::operator-(const Fraction &frac) const {
    int lowest = std::lcm(frac._delimeter,this->_delimeter);

    return Fraction(this->_meter *  lowest/this->_delimeter - frac._meter * lowest/frac._delimeter, lowest);
}


void Fraction::operator-=(const Fraction &frac)  {
    int lowest = std::lcm(frac._delimeter,this->_delimeter);

    this->_meter = this->_meter *  lowest/this->_delimeter - frac._meter * lowest/frac._delimeter;

    this->_delimeter = lowest;

    //the same reduction as in constructor
    int greatest = std::gcd(_delimeter,_meter);
    _delimeter = _delimeter / greatest;
    _meter = _meter /greatest;
}


Fraction Fraction::operator-() const {
    // this->_meter = -this->_meter;
    if (this->_meter < 0 || this->_delimeter < 0) {
        return Fraction(abs(_delimeter),abs(_meter));
    } else {
        return Fraction(-_meter,_delimeter);
    }
}


bool Fraction::operator==(Fraction frac) const {
    return (this->_meter == frac._meter) && (this->_delimeter == frac._delimeter);
}