#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <utility>


class Vector {



    private:
        std::vector<double> data;

    public:

        operator double() const;

        std::vector<double> getVector() const;

        int getSize() const;

        explicit Vector(int);

        explicit Vector(double);

        Vector();

        Vector (const Vector&);

        Vector(Vector &&);

        ~Vector();

        static Vector sum(const Vector&,const Vector&);

        static double dot(const Vector&,const Vector&) ;

        Vector extended(int);

        double norm() const;

        void print(std::string) const;

        double &vec(int) ;

};