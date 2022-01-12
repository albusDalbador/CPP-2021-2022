#include "functionVector.h"

double FunctionVector::operator[](int num) const {
    double result = 0.5;

    for (int i = 0; i <= num; i++) {
        result = functions[i](result);
    }

    return result;
}
 
void FunctionVector::insert(std::function<double(double)> func) {
    functions.push_back(func);
}

double FunctionVector::calc(double x) {
    double result = x;

    for (auto func : functions) {
        result = func(result);
    }

    return result;
}