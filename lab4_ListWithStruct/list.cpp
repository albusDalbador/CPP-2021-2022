#include "MyList.h"
#include <string.h>
#include <iostream>



void init(MyList *list, char *name) {
    
    list->name = new char[strlen(name) + 1];
    strcpy(list->name,name); 

    list->head = NULL;
}


void append(MyList *list, char *str) {
    Node *newElem = new Node;

    newElem->next = list->head;

    newElem->data = new char[strlen(str)];
    strcpy(newElem->data,str);

    list->head = newElem;
}


bool empty(const MyList *list) {
    return !list->head;
}


void print(const MyList *list) {
    Node *step = list->head;

    while(step){
        std::cout << step->data << " ";

        step=step->next;
    }

    std::cout << std::endl;
}


void replace (MyList *list, char *oldStr, char *newStr) {

    Node *node = findElem(list,oldStr);

    if (node) {

        delete [] node->data;

        node -> data = new char[strlen(newStr)] ;

        strcpy(node->data, newStr);
    }

}


void insertAfter(MyList *list,char *oldStr, char *newStr) {
    Node *node = findElem(list,oldStr);

    if (node) {
        Node *elem = new Node;

        elem->next = node->next;

        elem->data = new char(strlen(newStr));

        strcpy(elem->data,newStr);

        node->next = elem;
    } else {
        std::cout << "Nie znaleziono elemntu o podanej nazwie : \"" << oldStr << "\""<< std::endl;
    }
}


void removeAfter(MyList *list, char *pattern) {
    Node *node = findElem(list, pattern);

    if (node) {
        if (node ->next) {
            Node *step = node->next;

            node->next = node->next->next;

            delete step;
        }
    } else { 
        std::cout << "Nie znaleziono elemntu o podanej nazwie : \"" << pattern << "\""<< std::endl;
    }
}


Node *findElem(const MyList *list, char *pattern) {

    Node *step = list->head;

    while (true) {
        if (step) {

            if (!strcmp(step->data,pattern)) {
                return step;
            }

            step=step->next;

        } else {
            break;
        }
    }

    return NULL;
}


void remove(MyList *list, char *value) {
    // Node **previous = NULL;
    // Node *item = findElelmToRemove(list,value,previous);

    Node *step = list->head;


    if (step) {
        if (!strcmp(step->data,value)) {
            std::cout << step->data << " " << step->next->data << std::endl;
            list->head = step->next;
            // delete [] step -> data;
            delete step;
            return;
        }

        while (step->next) {
            if (!strcmp(step->next->data,value)) {

                std::cout << step->next->data <<  std::endl;

                Node *item = step->next->next;
                // delete [] step->next->data;
                delete step->next;

                step->next = item;

                return;
            }

            step = step->next;
        } 
    }
    
    std::cout << "Lista nie zawiera elemntu o podanej nazwie : \"" << value << "\""<< std::endl;
     
}


void clear (MyList *list) {

    if (!empty(list)) {
        Node *item = list->head;

        // delete list;

        while (item) {
            list->head = item->next;
            delete [] item;
            // item=step;
        }

        // delete l
    }
}