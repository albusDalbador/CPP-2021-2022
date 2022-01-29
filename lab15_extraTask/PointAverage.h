#pragma once

#include "Point2DSmartPtr.h"
#include <iostream>

// class Point2D;

class PointAverage{
    private:
        double averageX;
        double averageY;
        int count; 

    public:
        PointAverage();

        void operator()(Point2D&);

        void Reset();
        void Print() const;
};

//konstruktor
inline PointAverage::PointAverage() : averageY(0), averageX(0), count(0) {}

//operatory
void PointAverage::operator()(Point2D &point) {
    // count++;
    this->averageX = (this->averageX * count + point.getX()) / ++count;
    this->averageY = (this->averageY * count + point.getY()) / ++count ;
}

//funkcje skladowe
void PointAverage::Reset() {
    averageY = averageX = count = 0;
}

void PointAverage::Print() const {
    std:: cout << "Average Point:: (" << averageX << "," << averageY << ")\n";
}