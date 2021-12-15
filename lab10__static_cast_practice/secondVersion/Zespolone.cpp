#include "Zespolone.h"


Zespolone Dodaj(Zespolone first,Zespolone second) {
    return Zespolone(first.Re() + second.Re(), first.Im() + second.Im());
}


void Zespolone::Print(std::string name) const {
    std::cout << name;

    if (_real != 0 ) std::cout << _real << " ";

    else if (_imaginable != 0 ) std::cout << _imaginable <<"i";

    else std::cout << 0;

    std::cout << "\n";
}