#ifndef _MYLIST_H_
#define _MYLIST_H_

#include <iostream>

class Element;

class MyList
{
private:
    Element *head;
    Element *tail;
    char *listName;
public:
    //usuwa element listy, ale zachowuje sama liste
    void clearList();

    //dodaje przekazany element na poczatek listy
    void append(Element*);

    //tworzy nowy element, ustala w nim name na podana wartosc i dodaje ten element do listy
    void append(char *);

    //dodaje przekazany element na koniec listy
    void prepend(Element *);
    
    //zwraca wskaznik na pierwszy element listy
    Element *getHead() const;

    //zwraca wskaznik na ostatni element listy
    Element *getLast() const;

    //zwraca imie listy
    char *getName() const;

    //zwraca "TAK" jezeli lista jest pusta i "NIE" w przeciwnym wypadku
    bool isEmpty() const;

    //usuwa z listy pierwszy element
    void removeFirst();

    //usuwa z listy wszystkie elementy
    void celarList();
    
    //domyslny konstruktor
    MyList();

    //konstruktor, który inicjuje nazwe listy
    MyList(char *);

    //domyslny destruktor
    ~MyList();
};

//funkcja, wypisujaca przekazana liste
void print(const MyList *);



#endif