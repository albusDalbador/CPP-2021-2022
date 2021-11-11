
#include <iostream>


struct Node
{
    char *data;
    Node *next;
}; //pojedynczy wezel listy


struct MyList
{
    char *name;
    Node *head;
}; //structura przechowujaca nazwe oraz wskaznik na pierwszy element listy


void init(MyList *, char *);
// funkcja, inicująca liste, zapisujaca nazwe (drugi argument) do przekazanej struktury (pierwszy argument) oraz ustawiajaca wskaznik do pierwszego elementu na null

void append(MyList *,char* );
//dodaje element na poczatek listy

bool empty(const MyList*);
//zwraca true, ezeli lista jest pusta i false w przeciwnym wypadku

void print(const MyList *);
//wypisuje elementy listy od pierwszego (head) po kolei

void replace(MyList *,char *, char*);
// zamienia wartosc elementu, ktory przechowywal lancuch podany jako drugi argument, na przekazana jako trzeci argument. W przypadku, ezeli elementu o podanej wartosci nie ma w liscie, wypisuje odpowiedni komunikat

void insertAfter(MyList *, char *, char *);
//dodaje do listy element, w miejscu po elemencie, ktory przechowuje wartosc podana jako drugi argument. wartosc nowego elementu przekazuje sie jako trzeci argument

void removeAfter(MyList *, char *);
//usuwa z listy element, przochowowany od razu po elemencie o podanej wartosci. W przypadku jezeli elementu o podanej wartosci nie znaleizono, wypisuje odpowiedni komunikat

Node *findElem(const MyList *, char *);
//zwraca wskaznik do elementu o podanej wartosci. W pszypadku, gdy elementu o podanej wartosci nie ma w liscie, zwraca null

void remove(MyList *,char *);
//usuwa z listy element o podanej wartosci

// Node *findElemToRemove(MyList *, char *,Node**) ;
//zwraca wskaznik na element, poprzedzajacy ten, ktory chcemy usunąc. Funkcja pomocnicza dla "remove()". 

void clear (MyList *);
//dealokuje pamiec ale nie dziala :(