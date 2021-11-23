/*
 1. Skompilować program z linii poleceń (bez użycia programu make) z użyciem kompilatora g++.
 2. Napisać podstawowy makefile, w którym jawnie będą wypisane cele i zależności (można wykorzystać dołączony wzorzec)
   * Proszę przypisać flagę -O kompilatora do zmiennej CFLAGS
   * Proszę przypisać flagę -E kompilatora do zmiennej CFLAGS i podejrzeć plik main
   * Proszę przypisać flagę -g kompilatora do zmiennej CFLAGS
 3. Co spowoduje dodanie flagi -DNDEBUG do CFLAGS? Odkomentować linie assert(5==3);
 4*. Wykonać test z wykorzystaniem nm -a dla plików .o
 5*. Przeanalizować Makefile generyczny
*/

#include<iostream>
#include"Suma2.h"
#include"PolozeniePoczatkowe.h"
#include"Czas.h"
#include"Przyspieszenie.h"
#include"Predkosc.h"

#include"assert.h"

int main ()
{
  using namespace std;
  
#ifndef NDEBUG
  cout<<"This is debug version!\n";
#endif

  //assert(5==3);

#ifdef WELCOME
  cout<<"Good day to you sir!\n";
#endif
  
  cout<<"a = "<<Przyspieszenie()<<"\n";
  cout<<"v = "<<Predkosc()<<"\n";
  cout<<"r_0 = "<<PolozeniePoczatkowe()<<"\n";
  cout<<"t = "<<Czas()<<"\n";

  cout<<"r = a*t^2/2 + v*t + r_0 = "<<Suma2()<<"\n";

  return 0;
}
