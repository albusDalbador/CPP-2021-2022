#pragma once 

#include <string>
#include <iostream>
#include <vector>


class Wrapper {

    public:
    //zmienna, przechowujaca typ klasy pochodnej
        std::string dataType;
        
        //operator inkrementacji, w razie wywolania na lancuhcu przetwarza do uppercase
        virtual void operator++(int) = 0;
        //funkcja wypisania, przeladowana odpowiednio w kazdej klasie pochodnej
        virtual void print(std::ostream &) const = 0;
        //funkcja zwracajaca wartosc pola dataType
        std::string type() const { return dataType;}

};


class IntWrapper : public Wrapper {
    private:
    //pole wartorsci
        int val;

    public:
    //konstruktor inicujacy val
        IntWrapper(int);

        void print(std::ostream &)const override;
        void operator++(int) ;
};

 


class StringWrapper : public Wrapper {
    private:
        std::string val;

    public:
        StringWrapper(std::string);

        void print(std::ostream &)const override;
        void operator++(int) ;
};

 



class FloatWrapper : public Wrapper {
    private:
        float val;

    public:
        FloatWrapper(float x);

        void print(std::ostream &)const override;
        void operator++(int) ;
};
 

