#ifndef _WYMIERNE_H_
#define _WYMIERNE_H_


#include <iostream>
#include <string>
#include <math.h>

class Wymierne {

    private:
        int _meter;
        int _denominator;

    public:

        operator double() const;
        // Wymierne operator () (int) ;

        Wymierne();
        explicit Wymierne(int);
        Wymierne(int,int);

        //const_cast usage here
        void Licznik(int) const;
        void Mianownik(int);
        void Print(std::string) const;
        void Set(const Wymierne&) const ;


        int getMeter() const;
        int getDenominator() const;

};

inline Wymierne::Wymierne() : _meter(0) , _denominator(1) {}

inline Wymierne::Wymierne(int a) : _meter(a), _denominator(1) {}

inline Wymierne::Wymierne(int a, int b) : _meter(a), _denominator(b) {}

//non-member declaration
Wymierne Pomnoz(Wymierne,Wymierne);


//getters definition
inline int Wymierne::getMeter() const {
    return _meter;
}

inline int Wymierne::getDenominator()const{
    return _denominator;
}


#endif