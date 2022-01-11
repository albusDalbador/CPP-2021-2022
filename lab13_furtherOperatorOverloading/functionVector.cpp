#include "functionVector.h"

 
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