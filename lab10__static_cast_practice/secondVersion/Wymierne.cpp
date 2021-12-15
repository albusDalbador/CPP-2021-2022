#include "Wymierne.h"

Wymierne::operator double() const {
    return (double)this->_meter / (double)this->_denominator;
}

void Wymierne::Licznik(int l) const{
    const_cast<Wymierne*>(this)->_meter = l; 
}

void Wymierne::Mianownik(int a) {
    this->_denominator = a == 0 ? 1 : a;
}

Wymierne Pomnoz(Wymierne first, Wymierne second) {

    return Wymierne(first.getMeter() * second.getMeter(), first.getDenominator() * second.getDenominator());
}

void Wymierne::Print(std::string str) const {
    std::cout << str;

    if (_meter == 0 ) std::cout << 0;
    else if (_denominator == 0) std::cout << _meter;
    else std::cout << _meter << "/" << _denominator;

    std::cout << "\n";
}

void Wymierne::Set(const Wymierne &item) const{
    const_cast<Wymierne *>(this)->_meter = item.getMeter();
    const_cast<Wymierne *>(this)->_denominator = item.getDenominator();
}

