#include <iostream>
#include "../inc/Wektor.h"
#include "../inc/MacierzKw.h"
#include "../inc/UkladRownan.h"

int main()
{
    char wybor;
    std::cin>>wybor;
    if(wybor=='r')
    {
        UkladRownan<double, 5> URL;
        std::cin>> URL ;
        std::cout<<URL<<std::fixed<<std::setprecision(2)<<std::endl;
        std::cout<<"Wektor rozwiązania:"<<std::endl;
        std::cout<<URL.Oblicz(UkladRownan<double, 5>::Gauss)<<std::endl;
        std::cout<<"Wektor bledu:"<<std::endl;
        std::cout<<std::scientific<<std::setprecision(1)<<URL.ZwrocWektorBledu()<<std::endl;
        std::cout<<"Dlugosc wektora bledu:"<<std::endl;
        std::cout<<URL.ZwrocWektorBledu().dlugosc()<<std::endl;

    }
    else if(wybor=='z')
    {
        UkladRownan<LZespolona, 5> URL;
        std::cin>> URL ;
        std::cout<<"Wektor rozwiązania:"<<std::endl;
        std::cout<<URL<<std::fixed<<std::setprecision(2)<<std::endl;
        std::cout<<URL.Oblicz(UkladRownan<LZespolona, 5>::Gauss)<<std::endl;
        std::cout<<"Wektor bledu:"<<std::endl;
        std::cout<<std::scientific<<std::setprecision(1)<<URL.ZwrocWektorBledu()<<std::endl;
        std::cout<<"Dlugosc wektora bledu:"<<std::endl;
        std::cout<<URL.ZwrocWektorBledu().dlugosc()<<std::endl;
    }
    else
    {
        std::cout<<"Błąd: zły wybór\n r - liczby rzeczywiste\n z - liczby zespolone\n";
        exit(1);
    }



}
