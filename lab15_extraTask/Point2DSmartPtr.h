#pragma once

#include <iostream>
#include <stddef.h>

class Point2D;
//deklaracja klasy Point2DSmartPtr
class Point2DSmartPtr {
    private:
        // double _x,_y;
        Point2D *ptr;

    public:
        //konstruktory
        Point2DSmartPtr() = default;
        Point2DSmartPtr(Point2D *point) : ptr(point) {}
        ~Point2DSmartPtr() { delete ptr; }

        //operatory
        Point2D* operator->()const;
};

//definicja konstruktorow
// inline Point2DSmartPtr::Point2DSmartPtr() : _x(x) , _y(y) {}

Point2D* Point2DSmartPtr::operator->() const {
    return ptr;
}

//deklaracja klasy Point2D
class Point2D {

    friend Point2D operator+(double,Point2D&);
    private: 
        double _x;
        double _y;

    public:
        //konstruktory
        Point2D();
        Point2D(double,double);

        //operatory
        // Point2D operator()(double);
        Point2D operator+(const Point2D&) const;
        Point2D operator--();
        Point2D operator++(int);
        void* operator new(size_t);
        void operator delete(void *);

        //funkcje skladowe
        void Print() const;
        double getX() const;
        double getY() const;
};


//definicja konstruktorow
inline Point2D::Point2D() : _x(0), _y(0) {}

inline Point2D::Point2D(double x, double y) : _x(x), _y(y) {}


//definicja operatorow
//skladowe
Point2D Point2D::operator+(const Point2D &point) const {
    return Point2D(this->_x + point._x, this->_y + point._y);
}

Point2D Point2D::operator--() {
    return Point2D(--this->_x, --this->_y);
}

Point2D Point2D::operator++(int x) {
    return Point2D(this->_x++,this->_y++);
}

void* Point2D::operator new(size_t size) {
    std::cout << "Point2D:: alokowanie " << size << " bajtow\n";
    void* step = ::new Point2D();
    return step;
}

void Point2D::operator delete(void *point) {
    std::cout << "Point2D:: zwalnianie wskaznika\n";
    ::delete static_cast<Point2D*>(point);
}



//zewnetrzne
Point2D operator+(double x,Point2D &point) {
    return Point2D (point._x + x, point._y);
}


//definicja funckcji skladowych
void Point2D::Print() const {
    std::cout << "Point2D:: (" << this->_x << "," << this->_y << ")\n";
}

double Point2D::getX() const {
    return _x;
}

double Point2D::getY() const {
    return _y;
}


