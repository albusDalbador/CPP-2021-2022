#include <iostream>
// YYMMDDXXXPK

bool leapYear( int );
int getControlNumber(int[11]);
bool PeselGenerator(const char[8],const char[4],int[11]);
void printPesel(int[11]);
char *sex(  const char[4]);
int getDay(const char[8]);
int getMonth(const char[8]);
int getYear(const char[8]);


// P-cyfra płci: podzielna przez 2 - kobieta, niepodzielna - mężczyzna, obie są podane jako napis XXXP