#include "Zespolone.h"

// Zespolone::operator Wymierne() const {
    
// }

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