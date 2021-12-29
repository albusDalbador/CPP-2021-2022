#include "Vector.h"
 #include "Complex.h"

double operator*(const Vector&first, const Vector&second) {
    double result = 0;

    for (int i = 0 ; i < first._size; i++) {
        result += first.values[i] * second.values[i];
    }

    return result;
}

Vector operator+(const Vector&first,const Vector&second) {

    int resultSize = first._size > second._size ? first._size : second._size;

    Vector result(resultSize);

    int stopSize = first._size < second._size ? first._size : second._size;

    int iterator = 0;
    for (; iterator < stopSize; iterator++) {
        result.values[iterator] += first.values[iterator] + second.values[iterator];
    }

    while (iterator < first._size) result.values[iterator] = first.values[iterator++];

    while (iterator < second._size) result.values[iterator] = second.values[iterator++];

    return result;
}

double & Vector::operator[](int index) {
    return this->values[index];
}

void Vector::operator=(Complex complex) {

    this->values = new double[2];

    this->values[0] = complex._re;
    this->values[1] = complex._im;
}

void Vector::operator=(Vector vec) {
    this->_size = vec._size;

    delete [] this->values;
    this->values = new double[vec._size];

    for (int i = 0; i < _size; i++) {
        this->values[i] = vec.values[i];
    }
}



Vector::operator double() const {
    return this->norm();
}

Vector::Vector(Complex complex) : _size(2) {
    this->values = new double[2];

    this->values[0] = complex._re;
    this->values[1] = complex._im;
}

Vector::Vector(int size) : _size(size) {

    this->values = new double[size];

    for (int i = 0 ; i < size; i++) {
        this->values[i] = 0;
    }
}

Vector::Vector(double x, double y) : _size(2) {

    this->values = new double[2];

    this->values[0] = x;
    this->values[1] = y;
}

Vector::Vector(const Vector &oldItem) {
    this->_size = oldItem._size;

    this->values = new double[_size];

    for (int i =0 ; i < _size; i++) 
        values[i] = oldItem.values[i];
}

Vector::~Vector() {
    // if (values) {
        delete [] values;
    //     values = nullptr;
    // }
}


double Vector::norm() const {
    double result = 0;

    for (int i =0 ; i < _size; i++) {
        result += pow(values[i],2);
    }
    return sqrt(result);
}


void Vector::print(std::string name) const {
    std::cout << name << " [";

    for (int i =0 ; i < _size-1; i++) {
        std::cout << values[i] << ",";
    }

    if (_size != 0) std::cout << values[_size-1] << "]\n";
}
