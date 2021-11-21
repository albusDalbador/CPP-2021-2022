#include "MyText.h"
#include <iostream>
#include <cstring>


char up2low_low2up(char symbol) {
    return symbol >= 97 ? symbol - 32 : symbol + 32;
}

bool empty(MyText *item) {
    return item->text == NULL;
}

void erase (MyText *item, int begin, int end) {
    if (item->text) {
        char *after = new char[getStringLen(item->text) - end + 1];
        char *before = new char[begin];
        
        strncpy(before,item->text,begin);
        strcpy(after,item->text + end);

        item->text = new char[getStringLen(item->text) - end + begin];

        strcpy(item->text,before);
        strcpy(item->text + begin,after);

        delete [] after;
        delete [] before;
    } else {
        std::cout << "text is empty, nothing to erase\n";
    }
}

void insert (MyText *item, int pos, char *pattern) {
    if (item->text) {
        if (getStringLen(item->text) >= pos) {
            
            char *before = new char[pos];
            char *after =new char[getStringLen(item->text) - pos];

            strncpy(before,item->text,pos);
            strcpy(after,item->text+pos);

            item->text = new char[getStringLen(item->text) + getStringLen(pattern)];

            strcpy(item->text,before);
            strcpy(item->text+pos,pattern);
            strcpy(item->text + pos + getStringLen(pattern) , after);

            delete [] before;
            delete [] after;
        } else {
            std::cout << "podana pozycja wykracza po za lancuch";
        }
    } else {
        std::cout << "tekst jest pusty, nie ma gdzie dodawac";
    }
}

MyText *initMyText(char *newName) {
    MyText *newItem = new MyText;

    newItem->text = NULL;
    newItem->name = NULL;

    newItem->name = new char [getStringLen(newName)];

    strcpy( newItem->name,newName);

    return newItem;
}

void printStr(char *str) {
    std::cout << "Wypisujemy \"";
    if (str)  {
        while(*str) std::cout << *str++;
    }
    std::cout << "\"" << std::endl;
}

void print(MyText *item) {

    std::cout << item -> name << " =  \""  << item->text << "\"" << std::endl;
}

char *getStr(MyText *item) {
    return item->text;
}

MyText *append(MyText *item, char *pattern) {
    
    if (item->text){
        char *step = new char[getStringLen(item->text)];
        strcpy(step,item->text);

        item->text = new char [getStringLen(item->text) + getStringLen(pattern)];

        strcpy(item->text,step);
        strcpy(item->text + getStringLen(item->text), pattern);
    }
    else {

        item->text = new char [getStringLen(pattern)];

        strcpy(item->text,pattern);
    }

    return item;
}

void setChar(MyText *item,int pos, char symbol) {
    if (item->text) {
        if (getStringLen(item->text) >= pos) {
            item->text[pos] = symbol;
        } else {
            std::cout << "index is out the range\n";
        }
    } else {
        std::cout << "text is empty, nothing to change\n";
    }
}

int size(MyText *item) {

    if (item->text) {
        return getStringLen(item->text);
    }

    return 0;
}

int getStringLen(char *str) {
    int result = 0;

    while(*str++) {
        result ++;
    } 

    return result;
}