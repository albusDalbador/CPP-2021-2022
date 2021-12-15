#ifndef _ZESPOLONE_H_
#define _ZESPOLONE_H_

#include "Wymierne.h"
#include <iostream>
#include <utility>


class Zespolone {

    private:
        double _real;
        double _imaginable;

    public:

        Zespolone();
        Zespolone(double);
        Zespolone(Wymierne);
        Zespolone(double,double);
        Zespolone(const Zespolone&);
        Zespolone(Zespolone &&);

        void Print(std::string) const;

        double Re() const;
        double Im() const;

};

//non-member definition
Zespolone Dodaj(Zespolone,Zespolone);



inline Zespolone::Zespolone() : _real(0), _imaginable(0) {}

inline Zespolone::Zespolone(double re) : _real(re), _imaginable(0) {}

inline Zespolone::Zespolone(Wymierne wym) : _real((double)wym.getMeter() / (double)wym.getDenominator()), _imaginable(0) {}

inline Zespolone::Zespolone(double a, double b) : _real(a), _imaginable(b) {}

inline Zespolone::Zespolone(const Zespolone &oldItem) : _real(oldItem._real) , _imaginable(oldItem._imaginable) {}

inline Zespolone::Zespolone(Zespolone &&oldItem) : _real(std::exchange(oldItem._real,0)) , _imaginable(std::exchange(oldItem._imaginable,0)) {}



//getters definition
inline double Zespolone::Re() const {
    return _real;
}

inline double Zespolone::Im() const {
    return _imaginable;
}


#endif



