#include <iostream>



void printPesel(int pesel[11]) {
    for (int i = 0 ; i < 11; i++) {
        std::cout << pesel[i];
    }
    std::cout << " ";
}

char *sex(  const char index[4]) {
    if ( (index[3] - 48 )  % 2 == 0) return "Kobieta";
    else return "Mezczyzna";
}

int getControlNumber(int num[11]) {
     int sum = 0;

     for (int i = 1; i <=11; i++ ){
         sum += i * num[i];
     }
     return 10 - sum % 10;
}

bool leapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }

int getDay(const char date[8]) {
    return (date[0] - 48) * 10 + date[1] - 48;
}

int getMonth(const char date[8]) {
    return  (date[2] - 48) * 10 + date[3] - 48;
}
 
int getYear(const char date[8]) {
    return (date[4] - 48) * 1000 + (date[5] - 48) * 100 + (date[6] - 48) * 10 + date[7] - 48;
}

bool PeselGenerator(const char date[8],const char index[4], int pesel[11] ) {
    int dayInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if (leapYear(getYear(date))) dayInMonth[1]++;

    if (getDay(date) > dayInMonth[getMonth(date)] ) {
        std::cout << "Nieprawidlowa data" <<std::endl;
        return false;
    }

    if (getMonth(date) > 12 ) {
        std::cout << "Nieprawidlowa data" <<std::endl;
        return false;
    } 


    pesel[0] = date[6] -48;
    pesel[1] = date[7] - 48;

    int month = getMonth(date);

    month += (getYear(date) / 100 - 19)*20;


    pesel[2] = month /10;
    pesel[3] = month % 10;

    pesel[4] = getDay(date) / 10;
    pesel[5] = getDay(date) %10;

    pesel[6] = index[0];
    pesel[7] = index[1];
    pesel[8] = index[2];
    pesel[9] = index[3];
    
    pesel[10] = getControlNumber(pesel);
}