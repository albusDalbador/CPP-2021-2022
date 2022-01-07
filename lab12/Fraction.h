#ifndef _WYMIERNE_H_
#define _WYMIERNE_H_


#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

class Fraction  {

    private:
        int _meter;
        int _denominator;

    public:

        friend std::ostream &operator<<(std::ostream& ,Fraction&);

        explicit operator double() const;
        void operator*(const Fraction&);
        void operator=(const Fraction&);

        Fraction ();
        explicit Fraction (int);
        Fraction (int,int);

        //const_cast usage here
        void Licznik(int) const;
        void Mianownik(int);
        void Print(std::string) const;
        void Set(const Fraction &) const ;


        int getMeter() const;
        int getDenominator() const;

};

inline Fraction :: Fraction () : _meter(0) , _denominator(1) {}

inline Fraction :: Fraction (int a) : _meter(a), _denominator(1) {}

inline Fraction :: Fraction (int a, int b) : _meter(a), _denominator(b) {}

//non-member declaration Fraction  Pomnoz Fraction );

// Fraction operator*(Fraction &first,Fraction &second) {
//     return Fraction(first.getMeter() * second.getMeter(), first.getDenominator() * second.getDenominator());
// }

//getters definition
inline int Fraction ::getMeter() const {
    return _meter;
}

inline int Fraction ::getDenominator()const{
    return _denominator;
}


#endif