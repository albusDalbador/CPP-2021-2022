#include "Zespolone.h"



Zespolone Dodaj(Zespolone first, Zespolone second) {

    return Zespolone(first.Re() + second.Re(),first.Im() + second.Im());
}


void Zespolone::Print(std::string str) const {

    std::cout << str;

    if (_re == 0 && _im != 0) 
        std::cout << _im << "iiii";
    else if  (_re == 0 && _im == 0) 
        std::cout << "0";
    else if (_im ==0)
        std::cout << _re << "";
    
    std::cout << "\n";
}