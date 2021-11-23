#include <iostream>

//struktura przechowujaca lancuch znakow. Struktura posiada wlasna nazwe
struct MyText {
    char *text;
    char *name;
};

//zmienia podany symbol na uppercase, w przypadku, gdy przekazano lowercase i odwrotnie
int up2low_low2up(int);

//funkcja wypisuje lanuch znakow, przechowywanych pod podanym adresem
void printStr(char *);

//wypisuje cala strukture (nazwa + wartosc)
void print(MyText *);

//funkcja zwraca wskaznik do lancuhca znakow, przechowywanego w strukturze
char* getStr(MyText *);

//dodaje tekst do lancuha znakow przechowywanego w przekazanej strukturze
MyText* append(MyText*,char*);

//funkcja zwraca "false", jezeli pole "text" w przekazanej strukturze nie jest puste i "true" w przeciwnym wypadku
bool empty(MyText*);

//funkca tworzy strukture o podanej nazwie i zwraca wskaznik do niej
MyText *initMyText(char *) ;

//tworzy strukture o podanej nazwie i zapisuje do pola text wartosc, przechowywana w przekazanej strukturze
MyText *initMyText(char*,MyText *);

//funkcja pomocnicza do kopiowania ciagu znakow, prechowywanych pod adresem "src" do "dst"
void copyStr(char*,char*);

//funkcja pomocnicza, zwracajaca dlugosc ciagu znakow
int getStringLen(char *);

//zwraca rozmiar (w bajtach) calej struktury
int size(MyText *);

//zmienia w tekscie symbol na podanej pzycji
void setChar(MyText*,int, char);

//usuwa symbole z tekstu w podanym przedizale (lacznie z poczatkie i wylaczajac koniec)
void erase(MyText *, int ,int);
 
//dodaje do tekstu podany lancuch zaczynajac od podanej pozycji
void insert(MyText *,int,char*);

//zminia text w przekazanej strukturze uzywajac przekazanej funkcji
void modify(MyText *, int (*)(int));

//dealokuje pamiec zajmowana przez przekazana stukture
void clear(MyText *);