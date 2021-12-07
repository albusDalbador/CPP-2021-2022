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

int compareX(Point &a,  Point &b) {
    return a._x > b._x ? -1 : 1;
    // return 23;
}


int compareY(Point &a, Point &b) {
    return a._y > b._y ? -1 : 1;
}

void directions(Point &first,Point &second, int (*func)(Point&,Point&)) {

    if (func == compareX) {
        std::cout << first._name;
        std::string direction = compareX(first,second) > 0 ? " - na zach. od " : " - na wsch. od ";

        std::cout << direction << second._name << "\n";
    } 
    
    if (func == compareY) {
        std::cout << first._name;
        std::string direction = compareY(first,second) > 0 ? " - na pd. od " : " - na pn. od ";

        std::cout << direction << second._name << "\n";
    }
     
}


