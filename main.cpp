#include <iostream>
#include "Wektor.h"

int main()
{
    Wektor<LZespolona,5> WZ3;
    Wektor<double,3> W3;

    std::cin>> WZ3 ;
    std::cout<<WZ3.dlugosc();
}
