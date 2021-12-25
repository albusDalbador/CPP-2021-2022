#include "Point.h"

int Point::number = 0;




Point Point::setPoint(  double x,  double y) {
    return Point("Punkt X",x,y);
}

Point Point::setContrary(  double x, double y) {
    return Point("Punkt X",-x,-y);
}

Point Point::newMoved(std::string name, double x, double y) {
    return Point(name,x + _x, y + _y);
}

Point::Point(std::string name, double x, double y) : _id(++number),  _name(name), _x(x), _y(y) {}

Point::Point() : Point("",0,0) {}

Point::Point(const Point &oldPoint) : Point(oldPoint._name,oldPoint._x,oldPoint._y)
{
    std::cout << "--- Kopiujemy " << oldPoint._id << ". " << oldPoint._name << "\n";
}

Point::Point( Point &&point) : _x(point._x) , _y(point._y), _name(point._name), _id(++number) {
    std::cout << "--- Przenosimy " << point._id << ". " << point._name << "\n";

    point._name= "";
    point._x = 0;
    point._y = 0;
    
}

Point::~Point() {
    number--;
}


void Point::changeName(std::string name) {
    _name = name;
    return;
}

void Point::fullPrint() const {
    std::cout << _id << ". " << _name << " (" << _x << "," << _y << ")\n";
}

int compareX(  Point &a,  Point &b) {
    return a.getX() == b.getX() ? 0 : a.getX() > b.getX() ? 1 : -1;
}


int compareY(  Point &a, Point &b) {
    return a.getY() == b.getY() ? 0 : a.getY() > b.getY() ? 1 : -1;
}

std::string Point::getName() const {
    return _name;
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

void directions(Point &first,Point &second,int(*func)(Point&,Point&)) {
    std::cout << first.getName() << " ";

    if (compareX == func) {

        if (func(first,second) > 0) {
            std::cout << "- na wsch. od ";
        } else if (func(first,second) < 0) {
            std::cout << "- na zach. od ";
        } else {
            std::cout << "- na tej samej szerokosci co ";
        }
    } else if (compareY == func) {
        if (func(first,second) > 0) {
            std::cout << "- na pn. od ";
        } else if (func(first,second) < 0) {
            std::cout << "- na pd. od ";
        } else {
            std::cout << "- na tej samej dlugosci co ";
        }
    }

    std::cout << second.getName() << std::endl;
}



