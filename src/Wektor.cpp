/*
#include <cmath>
#include "Wektor.h"

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor()
{
    for(int i=0;i<ROZMIAR;i++)
        tab[i]=0;
}

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR>::Wektor(TYP * tab1)
{
    for(int i=0;i<ROZMIAR;i++)
      tab[i]=tab1[i];
}

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>:: operator + (const Wektor<TYP,ROZMIAR> & W2) const
{
    Wektor<TYP,ROZMIAR> WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]+W2.tab[i];

    return WP;
}

template<class TYP,int ROZMIAR>
 Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>:: operator - (const Wektor<TYP,ROZMIAR> & W2) const
{
    Wektor<TYP,ROZMIAR> WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]-W2.tab[i];

    return WP;
}

template<class TYP,int ROZMIAR>
TYP Wektor<TYP,ROZMIAR>:: operator * (const Wektor<TYP,ROZMIAR> & W2) const// SKALARNY
{
    TYP wynik;
    for(int i=0;i<ROZMIAR;i++)
        wynik += (*this)[i]*W2[i];

    return wynik;
}

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR>  Wektor<TYP,ROZMIAR>:: operator * (TYP li) const
{
    Wektor<TYP,ROZMIAR> WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]*li;

    return WP;
}

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> Wektor<TYP,ROZMIAR>:: operator / (TYP li) const
{
    if(li==0)
    {
     std::cout<<"Dzielenie przez zero"<<std::endl;
     exit(1);
    }
    Wektor<TYP,ROZMIAR> WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=this->tab[i]/li;

    return WP;
}


template<class TYP,int ROZMIAR>
double Wektor<TYP,ROZMIAR>:: dlugosc() const
{
    double wynik;
    wynik=*this * *this;
    return sqrt(wynik);
}



template<>
double Wektor<LZespolona,5>:: dlugosc() const
{
    Wektor<LZespolona,5> W,WS;
    W=*this;
    for(int i=0;i<5;++i)
        WS[i]=Sprzezenie(W[i]);

    return sqrt((WS*W).KonwersjaLZD());
}

template<class TYP,int ROZMIAR>
const TYP & Wektor<TYP,ROZMIAR>::  operator[] (int index) const {
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    return tab[index];
}

template<class TYP,int ROZMIAR>
TYP & Wektor<TYP,ROZMIAR>::  operator[] (int index)
{
    if (index < 0 || index >= ROZMIAR) {
        std::cerr << "poza zakresem" << std::endl;
        exit(1);
    }
    return tab[index];
}

template<class TYP,int ROZMIAR>
bool Wektor<TYP,ROZMIAR>:: operator == (const Wektor<TYP,ROZMIAR> & W2) const
{
    for(int i=0;i<ROZMIAR;i++)
        if(abs((*this)[i]-W2[i]) < EPSILON)
            return false;

    return true;
}

template<class TYP,int ROZMIAR>
bool Wektor<TYP,ROZMIAR>:: operator != (const Wektor<TYP,ROZMIAR> & W2) const
{
    return !((*this)==W2);
}

template<class TYP,int ROZMIAR>
std::ostream & operator <<(std::ostream & strm, const Wektor<TYP,ROZMIAR> & W)
{
    strm<<'(';
    int i;
    for (i = 0; i < ROZMIAR-1; ++i)
        strm<<W[i]<<',';

    strm<<W[i]<<')';
    return strm;
}

template<class TYP,int ROZMIAR>
std::istream & operator >>(std::istream & strm, Wektor<TYP,ROZMIAR> & W)
{
    for(int i=0;i<ROZMIAR;i++)
         strm>>W[i];

    return strm;
}

template<class TYP,int ROZMIAR>
Wektor<TYP,ROZMIAR> operator * (double l1, Wektor<TYP,ROZMIAR> W2)
{
    Wektor<TYP,ROZMIAR> WP;
    for(int i=0;i<ROZMIAR;i++)
        WP[i]=l1*W2[i];

    return WP;
}

*/