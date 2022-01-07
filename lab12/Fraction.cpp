#include "Fraction.h"

std::ostream &operator<<(std::ostream &stream, Fraction &frac) {
    return stream << frac._meter << "/" << frac._denominator;
}

Fraction::operator double() const {
    return (double)this->_meter / (double)this->_denominator;
}

void Fraction::operator*(const Fraction &frac) {
    this->_meter = this->_meter * frac.getMeter();
    this->_denominator = this->_denominator * frac.getDenominator();
}

void Fraction::operator=(const Fraction &frac) {
    this->_meter = frac.getMeter();
    this->_denominator = frac.getDenominator();
}



void Fraction::Licznik(int l) const{
    const_cast<Fraction*>(this)->_meter = l; 
}

void Fraction::Mianownik(int a) {
    this->_denominator = a == 0 ? 1 : a;
}

Fraction Pomnoz(Fraction first, Fraction second) {

    return Fraction(first.getMeter() * second.getMeter(), first.getDenominator() * second.getDenominator());
}

void Fraction::Print(std::string str) const {
    std::cout << str;

    if (_meter == 0 ) std::cout << 0;
    else if (_denominator == 0) std::cout << _meter;
    else std::cout << _meter << "/" << _denominator;

    std::cout << "\n";
}

void Fraction::Set(const Fraction &item) const{
    const_cast<Fraction *>(this)->_meter = item.getMeter();
    const_cast<Fraction *>(this)->_denominator = item.getDenominator();
}

