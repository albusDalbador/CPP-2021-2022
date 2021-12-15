#pragma once 

// #include "Zespolone.h"
#include <string>
#include <iostream>
#include <math.h>

class Wymierne {

    friend class Zespolone;

    

    private:
        int _licz;
        int _mian;

    public:

   

        operator double() const;

        Wymierne(int);

        explicit Wymierne();

        explicit Wymierne(int,int);

        //member functions
        void Print(std::string) const;

        void Mianownik(int);

        void Set(const Wymierne &);

        //getters & setters:

        int getLicz() const;
        int getMian() const;

        // void setLicz(int);
        // void setMian(int);
};

//non-member function declaration

Wymierne Pomnoz(const Wymierne &, const Wymierne &);

double sqrt(Wymierne&);

//definicja konstruktorow

inline Wymierne::Wymierne() : _licz(0), _mian(1) {}

inline Wymierne::Wymierne(int licz) : _licz(licz) , _mian(1) {}

inline Wymierne::Wymierne(int licznik,int mianownik) : _licz(licznik) {

    _mian = (mianownik == 0 ? 1 : mianownik) ;
}
 
//memeber-function declaration

inline void Wymierne::Mianownik(int mian) {
    _mian = mian == 0 ? 1 : mian;
}

inline void Wymierne::Set(const Wymierne &item) {
    _licz = item.getLicz(); 
    _mian = item.getMian();
}

//definicja getterow i setterow

inline int Wymierne::getLicz() const {
    return _licz;
}

inline int Wymierne::getMian() const {
    return _mian;
}
