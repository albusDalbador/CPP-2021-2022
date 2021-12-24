#ifndef _ELEM_H_
#define _ELEM_H_

class Element
{
private:
    Element *next;
    char *name;
    
public:
    //zwraca wartosc prywatnej zmiennej name
    char *getName();

    //ustala wartosc prywatnej zmiennej name
    void setName(char *);

    //wypisuje ime elementu
    void printName();

    //zwraca wartosc prywatniej zmiennej next, (adres nastepnego elementu w liscie)
    Element *getNext();

    //ustala prywatny wskaznik next na przekazany element
    void setNext(Element*);

    //domyslny konstruktor
    Element();

    //konstruktor, ktory ustala nazwe na  przekazana wartoscia
    Element(char *);

    //domyslny destruktor
    ~Element();
};
 


#endif