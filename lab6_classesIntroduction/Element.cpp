#include "Element.h"
#include <string.h>
#include <iostream>

Element::Element() {
    name = nullptr;
    next = nullptr;
}

Element::Element(char *text) {
    this->name = text;
}

Element::~Element() {
    std::cout << "Destruktor Element: " << name << std::endl;
    
    // delete [] name;
}

char* Element::getName() {
    return name;
}

void Element::setName(char *text) {
    this->name = new char[strlen(text)];

    strcpy(this->name,text);
}

Element* Element::getNext() {
    return next;
}

void Element::setNext(Element *next) {
    this->next = next;
}

void Element::printName() {
    std::cout <<  this->name;
}