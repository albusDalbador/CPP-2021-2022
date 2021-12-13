#include "Wymierne.h"

// Wymierne::operator Zespolone() const {
//     return Zespolone((double)this->_licz / (double)this->_mian,0);
// } 

Wymierne::operator double() const {
    return (double)this->_licz / (double)this->_mian;
}


Wymierne Pomnoz(const Wymierne &num1, const Wymierne &num2) {
    return Wymierne(num1.getLicz() * num2.getLicz(), num1.getMian() * num2.getMian());
}



void Wymierne::Print(std::string str) const {

    if (_licz != 0 && _mian != 1)
        std::cout <<  str << _licz << "/" << _mian << "\n";
    else if (_licz == 0)
        std::cout << str << "0\n";
    else 
        std::cout << str  << _licz << "\n";
}

double sqrt(Wymierne &item) {
    return (double)sqrt(item.getLicz()) / (double)sqrt(item.getMian());
}