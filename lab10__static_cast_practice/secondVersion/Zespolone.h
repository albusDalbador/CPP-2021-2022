#pragma once

#include "Wymierne.h"
#include <string>
#include <iostream>

// class Wymierne;

class Zespolone {

    // static_cast<Zespolone>(int);
    // int operator Zespolone() ;

    // Zespolone operator ()(int);

Zespolone operator()(int i) {
    return Zespolone(i);
}




    private:
        double _re;
        double _im;

    public:

        explicit Zespolone(double,double);

        explicit Zespolone(const double);

        Zespolone(Wymierne &);

        //member functions
        void Print(std::string) const;

        //getters & setters
        double Im() const;
        double Re() const;

};

//non- member function declaration

Zespolone Dodaj(Zespolone,Zespolone);


//constructors definitions
inline Zespolone::Zespolone(double re, double im) : _re(re), _im(im) {}




inline Zespolone::Zespolone(const double re) : _re(re), _im(0) {}


//casting function
inline Zespolone::Zespolone(Wymierne &item)  : _re((double)item._licz / item._mian) , _im(0) {}


//getters definition
inline double Zespolone::Im() const {
    return _im;
}

inline double Zespolone::Re() const {
    return _re;
}