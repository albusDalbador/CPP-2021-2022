#include "Wrapper.h"

//intwrapper
void IntWrapper::operator++(int) {
    val++;
}

IntWrapper::IntWrapper(int x) : val(x) {dataType = "Int";}

void IntWrapper::print(std::ostream &os) const  {
    os << this->val;
}


//stringwrapper
void StringWrapper::operator++(int)  {
    for (auto &item : val) item = toupper(item);
}

 StringWrapper::StringWrapper(std::string str) : val(str) {dataType = "String";}

void StringWrapper::print(std::ostream &os) const {
    os << this->val;
}


//floatwrapper
void FloatWrapper::operator++(int) {
    val++;
}

 FloatWrapper::FloatWrapper(float x) : val(x) {dataType = "Float";}

void FloatWrapper::print(std::ostream &os) const {
    os << this->val;
}
