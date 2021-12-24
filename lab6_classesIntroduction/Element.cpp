#include "Element.h"
#include <string.h>
#include <iostream>

Element::Element() {
    name = nullptr;
    next = nullptr;
}

Element::Element(char *text) {
    this->setName(text);
    this->next =nullptr;
}

 

char* Element::getName() {
    return name;
}

void Element::setName(char *text) {
    name = new char[strlen(text) + 1];
    strcpy(name,text);
}

Element* Element::getNext() {
    return this->next;
}

void Element::setNext(Element *next) {
    this->next = next;
}

void Element::printName() {
    std::cout <<  this->name;
}