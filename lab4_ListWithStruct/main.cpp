/* W liście jednokierunkowej, każdy obiekt poza ostatnim wskazuje
 na kolejny element listy. Następnik dla ostatniego elementu jest 
 ustawiany na NULL (nullptr), co umożliwia sprawdzenie końca listy.

 Zadanie najłatwiej rozwiązać tworząc dwie struktury: Node (węzeł)
 oraz właściwą strukturę MyList, trzymajacą wskaźnik na pierwszy węzeł oraz nazwę listy.

 W zadaniu proszę napisać listę połączoną jednokierunkowo, 
 służącą do przechowywania napisów (łańcuchów znaków).

 Napisy muszą być kopiowane do alokowanej pamięci. 
 Należy zadbać o zwolnienie pamięci przy czyszczeniu listy.

 Niektóre z funkcji nie zmieniają listy (np. print)
  i z tego powodu powinny odbierać stały wskaźnik do struktury MyList.
*/

#include "MyList.h"
#include <cstring>
#include <iostream>

int main() {
    std::cout << "--- Pierwsza lista ---" << std::endl;
    MyList testList;
    init(&testList, (char *)"Lista1"); //alokujemy dynamicznie pamięć dla nazwy listy
    
    /**************************************************/
    char buffer[50];
    strcpy(buffer, "kota");
    append(&testList, buffer);
    strcpy(buffer, "ma"); //dodajemy na początek listy
    append(&testList, buffer);
    append(&testList, (char *)"Ala");

    const MyList* lptr = &testList;

    std::cout << lptr->head->data << std::endl;
    std::cout << lptr->head->next->data << std::endl;
     
    // // // /**************************************************/
    std::cout << "Czy lista jest pusta? " 
              << (empty(lptr)? "TAK" : "NIE") << std::endl;
    print(lptr); // Ala ma kota
    replace(&testList,(char *)"Ala",(char *)"Alicja");
    replace(&testList,(char *)"kota",(char *)"psa");
    print(lptr);  // Alicja ma psa

    // /**************************************************/
    MyList drugaLista;
    init(&drugaLista, (char *)"Lista2");
    strcpy(buffer, "jest latwe.");
    append(&drugaLista, buffer);
    strcpy(buffer, "Zadanie");
    append(&drugaLista, buffer);
    print(&drugaLista); //Zadanie jest latwe

    // /********************* BASIC ***********************/
    #ifndef BASIC  // funkcje insertAfter i removeAfter
      std::cout << "\n--- Zadania dodatkowe ---" << std::endl;
      MyList* l1ptr = &testList;
      insertAfter(&testList,(char *)"Alicja",(char *)"Nowak"); //wstawiamy Nowak za Alicja
      insertAfter(l1ptr,(char *)"psa",(char *)"Puszka"); //wstawiamy Puszka za Psa
      print(l1ptr); //Alicja Nowak ma psa Puszka

      removeAfter(l1ptr,(char *)"Alicja"); //kasujemy Nowak
      removeAfter(l1ptr,(char *)"psa"); //kasujemy Puszka
      print(l1ptr); //Alicja ma psa

      removeAfter(&testList,(char *)"kota"); //nic nie kasujemy
      insertAfter(&testList,(char *)"Alicja",(char *)"Ala"); //wstawiamy Ala za Alicja
    #endif

    // // /****************** ADVANCE **********************/

    #ifndef ADVANCE  // funkcja remove
      remove(&testList,"Alicja"); //kasujemy Alicja
      insertAfter(&testList,"psa","owczarka"); //wstawiamy Ala za Alicja
      print(l1ptr);
      remove(&testList,"psa"); 
      print(l1ptr); //Ala ma psa
      remove(&testList,"Alicja"); //nic nie kasujemy
    #endif

    // ////////////////////////////////////////////////
    std::cout << "\n--- Czyszczenie ---" << std::endl;
    clear(&testList);
    std::cout << "Czy teraz lista jest pusta? " 
              << (empty(lptr)? "TAK" : "NIE") << std::endl;
              
    std::cout << "Probujemy wypisac pusta liste. " << std::endl;
    print(lptr);
    
    // /**************************************************/
    print(&drugaLista);
    clear(&drugaLista);
    
    clear(&drugaLista);
}

/*oczekiwany output

--- Pierwsza lista ---
Ala
ma
Czy lista jest pusta? NIE
Lista1: Ala ma kota 
Lista1: Alicja ma psa 
Lista2: Zadanie jest latwe. 

--- Zadania dodatkowe ---
Lista1: Alicja Nowak ma psa Puszka 
Lista1: Alicja ma psa 
Lista1: Ala ma owczarka 

--- Czyszczenie ---
Czy teraz lista jest pusta? TAK
Probujemy wypisac pusta liste. 
Lista2: Zadanie jest latwe. 
*/
