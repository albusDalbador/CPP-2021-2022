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

    listName = new char[strlen(name) + 1];

    strcpy(listName,name);
}

MyList::~MyList(){
    std::cout << "Destruktor MyList: " << listName << std::endl;
    
    this->clearList();
    delete [] listName;

}

void MyList::append(Element *elem) {
    elem->setNext(nullptr);

    if (this->tail)
        this->tail->setNext(elem);

    this->tail = elem;

    if (this->head == nullptr) {
        this->head = elem;
    }
}

void MyList::append(char *text) {
    Element *newElem = new Element();

    newElem->setName(text);

    if (this->tail)
        this->tail->setNext(newElem);

    this->tail = newElem;

    if (this->head == nullptr) {
        this->head = newElem;
    }
}

void MyList::prepend(Element *elem) {
    elem->setNext(this->head);

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
        return false;
    } else {
        return true;
    }
}

void MyList::removeFirst() {
    Element *step = this->head;

    if (step) {
        this->head = this->head->getNext();

        delete [] step->getName();
        delete step;
    }
}

void MyList::clearList() {
    if (this->head) {
        while (this->head) {
            this->removeFirst();
        }
    } else {
        // std::cout << "list is already empty\n";
    }
}


//nonmember functions

void print(const MyList *list) {
    std::cout << list->getName() << " = [" ;

    if (list->getHead()) {
        Element *step = list->getHead();

        while( step) {
            std::cout << step->getName();

            if (step->getNext()) std::cout << " ";

            step = step->getNext();
        } 
    }
        std::cout <<"]\n";
}