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

    delete [] listName;
}

void MyList::append(Element *elem) {
    Element *step = this->tail;

    // this->head = elem;

    elem->setNext(this->tail);

    this->tail = elem;

    if (this->head == nullptr) {
        this->head = elem;
    }
}

void MyList::append(char *text) {
    Element *newElem = new Element();

    newElem->setName(text);
    newElem->setNext(this->tail);

    this->tail = newElem;

    if (this->tail == nullptr) {
        this->tail = newElem;
    }
}

void MyList::prepend(Element *elem) {

    this->head->setNext(elem);

    this->head = elem;

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

bool MyList::isEmpty() const {
    if (this->head) {
        return true;
    } else {
        return false;
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

}