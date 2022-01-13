#include <math.h>
// #include <algorithm>
#include <numeric>
#include <iostream>

class Fraction {

    friend std::ostream& operator<<(std::ostream&,const Fraction&);


    private:
        int _meter;
        int _delimeter;

    public:
        explicit operator double();

        Fraction operator*(const Fraction &) const;

        void operator*=(const Fraction &);

        Fraction operator+(const Fraction &) const;

        Fraction operator-(const Fraction &) const;

        void operator-=(const Fraction &);

        Fraction operator-() const;

        bool operator==(Fraction) const;


        Fraction(int,int);
        Fraction(int);
};

// inline Fraction::Fraction(int i) : _meter(i), _delimeter(1) {}






















