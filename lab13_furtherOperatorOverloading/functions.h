#pragma once
#include <iostream>
#include <math.h>

//Sin class
class Sin {

    private:
        double _a;
        double _b;

    public:
        Sin(double,double);
        double operator()(double) const;
};


//Sqrt class
class Sqrt {

    public:
        Sqrt();

        double operator()(double) const;        
};



//Linear class
class Linear {

    private:
        double _a;
        double _b;
        double _x;

    public:
        double linear(double x);

        Linear(double,double);

        double operator()(double) const;

        friend std::ostream& operator<<(std::ostream&, const Linear);
};


