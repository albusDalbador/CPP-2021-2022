#ifndef _POINT_
#define _POINT_

#include <string>
#include <iostream>

class Point {

    //zaprzyjaznienie funkcji main?? nie wiem, na ile to dopuszczalna praktyka, ale ma to na celu umozliwienie dostepu do wartosci prywatnych, ktore byloby trudne do zrobienia w inny sposob bez edycji main'a
    friend int main();
    
    public:
        //nazwany konstruktor zwraca nowy obiekt Point, stworzony z przekazanych wartosci x i y
        static Point setPoint( double x,   double y);

        //nazwany konstruktor, ktory zwraca nowy obiekt utworzony z ujemnych wartosci x oraz y
        static Point setContrary(double,  double);

        //funkcja zwracajaca nowy obiekt, stworzony na podstawie wartosci obiektu, na ktorym zostal wywolany oraz obiektu, ktory zostal przekazany
        Point newMoved(std::string, double, double);

        //konstruktor klasy Point, przyjmujacy imie oraz dwie wartosci x i y
        Point(std::string,double,double);

        //konstruktor klasy Point, ustawiajacy domyslne wartosci _name, _x oraz _y(konstruktor delegowany :) )
        Point();

        //konstruktor kopiujacy
        Point(const Point&);

        //konstruktor przenoszacy
        Point( Point &&);

        //destrukor (przy wywolaniyu dekrementuje wartosc number, co sprawia, ze ta wartosc zawsze wskazuje ilosc istniejacych w pamieci obiektow)
        ~Point();

        //funkcja zmienia imnie obiektu na przekazana wartosc
        void changeName(std::string);

        //funkcja wypisuje caly obiekt w ustalonym formacie
        void fullPrint() const ;

        std::string getName() const;
        
        double getX() const;
        double getY() const;

    private:

    //przechowuje id danego obiektu
    const int _id;

    //przechowuje ilosc istniejacych w danym momencie obiektow
    static int number;
    
    //przechowuje imie danego obiektu
    std::string _name;
    
    double _x;
    double _y;

    
};

int compareX(Point&, Point&);

int compareY(Point&,Point&);

void directions(Point&,Point&,int(*)(Point&,Point&));


#endif