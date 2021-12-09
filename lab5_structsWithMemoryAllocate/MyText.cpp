#include "MyText.h"
#include <iostream>
#include <cstring>

 

int up2low_low2up(int symbol) {
    if ((char)symbol == ' ') return ' ';
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

            delete [] item->text;

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

    newItem->name = new char [strlen(newName) + 1];

    strcpy( newItem->name,newName);

    return newItem;
}

MyText *initMyText(char *newName, MyText *oldItem) {
    // MyText *newItem = new MyText;

    // newItem->text = NULL;
    // newItem->name = NULL;

    // newItem->name = new char [getStringLen(newName) + 1];
    
    // strcpy( newItem->name,newName);

    // if (oldItem->text) {
    //     newItem->text = new char[getStringLen(oldItem->text)];

    //     strcpy(newItem->text,oldItem->text);
    // }

    // return newItem;
}

void modify(MyText *item, int (*func)(int)) {
    if (item->text) {
        for (int i = 0; i < getStringLen(item->text); i++) {
            item->text[i] = func(item->text[i]);
        }
    }
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
        char *step = new char[getStringLen(item->text) + 1];
        strcpy(step,item->text);

        delete [] item->text;

        item->text = new char [getStringLen(item->text) + getStringLen(pattern) + 1];

        strcpy(item->text,step);
        strcpy(item->text + getStringLen(item->text), pattern);

        delete [] step;
    }
    else {
        // delete [] item->text;

        item->text = new char [getStringLen(pattern) + 1];

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

void clear(MyText *item) {
    if (item->text)
    delete [] item->text;
    if (item->name)
    delete [] item-> name;
    delete item;
}