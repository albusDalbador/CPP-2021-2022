/* Proszę zdefiniować klasę Student, reprezentującą studenta oraz klasę Grade reprezentującą ocenę danego studenta. 
 Każdy student ma identyfikator nadawany automatycznie od 1 oraz imię (proponuję wykorzystać std::string). Student może mieć wiele ocen.

 UWAGA!!!
 W zadaniu nie wolno używać mutable. Uzycie go oznacza 0 punktow za zadanie.

 UWAGA!!!
 Tablice powinny dostosowywać swój rozmiar do liczby przechowywanych obiektów.

 Pliku Main.cpp, nie wolno modyfikować.
*/

#include <iostream>
#include "Grade.h"
#include "Student.h"

int main() {

  std::cout<<"DANIEL\n";
  const Student daniel ("Daniel");//ID nadawane po kolei od 1
  daniel.print();

  const Grade danielPhysics (daniel, 4.5);
  daniel.print();

  const Grade danielMath (daniel, 5);
  daniel.print();
  danielMath.print();

  std::cout<<"\nMAREK\n";
  const Student marek ("Marek");
  marek.print();

  const Grade marekMath (marek, 3.5);
  marek.print();
  marekMath.print();

  std::cout<<"\nSTUDENT\n";
  const Student noname;
  const Grade nonameMath(Student(), 4);
  nonameMath.print();

  std::cout<<"\nDANIEL i MAREK\n";
  marek.print();
  daniel.print();

  return 0;
}
/* Oczekiwany output:
DANIEL
Daniel ID=1 oceny:
Daniel ID=1 oceny: 4.5
Daniel ID=1 oceny: 4.5 5
Dziennik ocena=5 student=Daniel ID=1

MAREK
Marek ID=2 oceny:
Marek ID=2 oceny: 3.5
Dziennik ocena=3.5 student=Marek ID=2

STUDENT
Dziennik ocena=4 student=Student ID=3

DANIEL i MAREK
Marek ID=2 oceny: 3.5
Daniel ID=1 oceny: 4.5 5
*/
