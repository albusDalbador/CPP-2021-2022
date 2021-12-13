#pragma once

#include "Wymierne.h"
#include <string>

class Wymierne;

class Zespolone {
    private:
        double _re;
        double _im;

    public:

        explicit Zespolone(double,double);

        Zespolone(const Wymierne &);

        //member functions
        void Print(std::string) const;

        //getters & setters
        double Im() const;
        double Re() const;

};

inline Zespolone::Zespolone(double re, double im) : _re(re), _im(im) {}

inline Zespolone::Zespolone(const Wymierne &item)  : _re(item.getLicz() / item.getMian()) , _im(0) {}

//getters definition
inline double Zespolone::Im() const {
    return _im;
}

inline double Zespolone::Re() const {
    return _re;
}