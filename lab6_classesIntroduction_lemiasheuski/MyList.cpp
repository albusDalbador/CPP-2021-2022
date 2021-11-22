#include "MyList.h"
#include "Element.h"
#include <string.h>
#include <iostream>

MyList::MyList() {
    head = nullptr;
    tail = nullptr;
}

MyList::MyList(char *name) {
    head = nullptr;
    tail = nullptr;

    listName = new char[strlen(name)];

    strcpy(listName,name);
}

MyList::~MyList(){
    std::cout << "Destruktor Element: " << this->getName() << std::endl;
}

void MyList::append(Element *elem) {
    Element *step = this->head;

    // this->head = elem;

    elem->setNext(this->head);

    this->head = elem;

    if (this->tail == nullptr) {
        this->tail = elem;
    }
}

void MyList::append(char *text) {
    Element *newElem = new Element();

    newElem->setName(text);
    newElem->setNext(this->head);

    this->head = newElem;

    if (this->tail == nullptr) {
        this->tail = newElem;
    }
}

void MyList::prepend(Element *elem) {

    this->tail->setNext(elem);

    this->tail = elem;

}

Element* MyList::getHead()const {
    return this->head;
}

Element* MyList::getLast() const {
    return this->tail;
}

char* MyList::getName() const {
    return this->listName;
}

char* MyList::isEmpty() const {
    if (this->head) {
        return "Nie";
    } else {
        return "Tak";
    }
}

void MyList::removeFirst() {
    Element *step = this->head;

    this->head = this->head->getNext();

    // delete step;
    step->~Element();
}

void MyList::clearList() {
    if (this->head) {
        while (this->head) {
            this->removeFirst();
        }
    } else {
        std::cout << "list is already empty\n";
    }
}


//nonmember functions

//funkcja wypisuje cala liste razem z nazwa
void print(const MyList *list) {
    std::cout << list->getName()
        << " = [" ;

    if (list->getHead()) {
        Element *step = list->getHead();


        while( step->getNext()) {
            std::cout << step->getName() << " ";
            step = step->getNext();
        } 

        std::cout << step->getName() <<"]\n";
    }

    std::cout << "]\n";
}