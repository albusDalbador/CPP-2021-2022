#pragma once 

#include "Vector.h"
#include <iostream>
#include <utility>

class Complex {
    //zaprzyjazniony operator dodawania, ktory zwraca obiekt klasy Complex
    friend Complex operator+(const Complex&,const Complex&);

    private:
        double _re;
        double _im;

    public:
        //przeladowanie operatora przypisania, pozwalajaca przypisywac wartosci typu double do obiektu klasy
        void operator=(double);

        //konstruktor, wykorzystany do rzutowania z klasy Vector
        explicit Complex(Vector);
        //konstruktor, wykorzystany do rzutowania z typu double
        explicit Complex(double);
        //konstructor klasy, inicujacy pola _re i _im
        explicit Complex(double,double);
        //konstruktor kopiujacy
        Complex(const Complex&);
        //konstruktor przenoszachy
        Complex(Complex &&);

        //funkcja wypisujaca obiekt klasy w okreslonym formacie
        void print(std::string) const;

};

inline Complex::Complex(Vector vector) : _re(vector.values[0]), _im(vector.values[1]) { }

inline Complex::Complex(const Complex &item) : _re(item._re), _im(item._im) {}

inline Complex::Complex(double re) : _re(re), _im(0) { }

inline Complex::Complex(double re, double im) : _re(re) , _im(im) {}

inline Complex::Complex(Complex &&oldItem) : _re(std::exchange(oldItem._re,0)) , _im(std::exchange(oldItem._im,0)) {}