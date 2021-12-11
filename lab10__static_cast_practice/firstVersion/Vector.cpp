#include "Vector.h"

Vector::operator double() const {
    return this->norm();
}

Vector::Vector() {

}

Vector::Vector(int length) {

    data = std::vector<double>(length,0.0);
}


Vector::Vector(double num)  {
    data.push_back(num);
}

Vector::Vector(const Vector &vector) {
    for (double num : vector.data)
    this->data.push_back(num);
}

Vector::Vector(Vector &&vector) : data(std::exchange(vector.data,std::vector<double>(0,0))) {} 

Vector::~Vector() {}

//methods:

double Vector::dot(const Vector &v1,const Vector &v2)  {
    std::vector<double> firstVec = v1.getVector();
    std::vector<double> secondVec = v2.getVector();

    double result = 0;

    for (int i = 0; i < (int)firstVec.size() ; i++) {
        // if (secondVec.size() <= i) {
        //     break;
        // }
        result += firstVec[i] * secondVec[i];
    }

    return result;
}

Vector Vector::extended(int num) {

    Vector step = *this;

    for (int i = 0; i < num; i++) {
        step.data.push_back(0.0);
    }

    return step;
}

int Vector::getSize() const {
    return data.size();
}

std::vector<double> Vector::getVector() const {
    return data;
}

double Vector::norm() const {
    double sum = 0 ;

    for (double i : data) {
        sum += i*i;
    }

    return sqrt(sum);
}

void Vector::print(std::string str) const {
    std:: cout << str << "[";

    for (int i = 0; i < (int)(data.size() -1) ; i++) {
        std::cout << data[i] << ",";
    }

    std::cout << data[data.size() -1];

    std::cout << "]\n";

}

Vector Vector::sum(const Vector &v1,const Vector &v2) {
    std::vector<double> firstVec = v1.getVector();
    std::vector<double> secondVec = v2.getVector();

    Vector result;

    int i = 0;

    for (; i < (int)firstVec.size() ; i++) {
        if ((int)secondVec.size() <= i) {
            for (int j = i; j < (int)firstVec.size(); j++){
                result.data.push_back(firstVec[j]);
            }
            break;
        }
        result.data.push_back(firstVec[i] + secondVec[i]);
    }

    while (i<(int)secondVec.size()) {
        result.data.push_back(secondVec[i]);
        i++;
    }

    return result;

}

double &Vector::vec(int num) {
    return  data[num];
}
 
// T& operator=(const T& other)
// {
//     // Guard self assignment
//     if (this == &other)
//         return *this;
 
//     // assume *this manages a reusable resource, such as a heap-allocated buffer mArray
//     if (size != other.size) {         // resource in *this cannot be reused
//         delete[] mArray;              // release resource in *this
//         mArray = nullptr;
//         size = 0;                     // preserve invariants in case next line throws
//         mArray = new int[other.size]; // allocate resource in *this
//         size = other.size;
//     } 
 
//     std::copy(other.mArray, other.mArray + other.size, mArray);
//     return *this;
// }