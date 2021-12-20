#pragma once 

#include <string>
#include <iostream>
#include <math.h>

class Vector{
    //zaprzyjazniony operator mnozenia, ktory mnozy po kolei wspolrzedne wektora
    friend double operator*(const Vector&, const Vector&);
    //zaprzyjazniony operator mnozenia, ktory dodaje po kolei wspolrzedne wektora
    friend Vector operator+(const Vector&,const Vector&);
    
    //zaprzyjaznienie klasy Complex, zeby umozliwic dzialanie konstruktora Complex::Complex(Vector);
    friend class Complex;

    private:
        int _size;
        double *values;

    public:

        //przeladowanie operatora [], umozliwiajace przypisanie wartosci elementom tablicy values poprzez imnie obiektu
        double &operator[](int) ;
        //operator rzutowania na typ double
        operator double() const;

        //konstructor inicujacy tablice values o podanym rozmiarze, wypelniona zerami
        explicit Vector(int);
        //konstruktor inicujacy wektor o dwoch wspolrzednych
        Vector(double,double);
        //konstruktor kopiujacy
        Vector(const Vector&);

        ~Vector();

        //funkcja obliczajaca norme wektora
        double norm() const;
        //funkcja wypisujaca obiekt klasy w okreslonym formacie
        void print(std::string) const;
};

 

 