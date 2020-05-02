#include "../inc/LZespolona.hh"
#include <math.h>
#include <iostream>


LZespolona & LZespolona:: operator = (const double l)
{
    re=l;
    im=0;
    return *this;
}
bool LZespolona:: operator == (const double  l) const
{
    if(abs(this->re==l) && abs(this->im==l))
        return true;

    return false;
}
bool LZespolona:: operator != (const double  l) const
{
    return !(*this==l);
}
LZespolona  LZespolona:: operator += (const LZespolona & LZ) const
{

    return (*this)+LZ;
}
LZespolona LZespolona:: operator += (const double & liczba) const
{
    LZespolona LZ=*this;
    LZ.re+=liczba;
    return LZ;
}

LZespolona LZespolona:: operator * (const double liczba) const
{
    LZespolona LZ=*this;
    LZ.re*=liczba;
    LZ.im*=liczba;

    return LZ;
}

LZespolona operator + (const LZespolona  Skl1,const  LZespolona  Skl2)
{
    LZespolona  Wynik;

    Wynik.re = Skl1.re + Skl2.re;
    Wynik.im = Skl1.im + Skl2.im;
    return Wynik;
}
LZespolona Utworz(const double re,const double im)
{
LZespolona lz;
lz.re=re;
lz.im=im;
return lz;
}

std::ostream & operator << (std::ostream & strm, const LZespolona & lz)
{
    strm<<'('<<lz.re<<std::showpos<<lz.im<<std::noshowpos<<"i)";
    return strm;
}
std::istream & operator >> (std::istream & strm, LZespolona & lz)
{
    char znak;
    strm >> znak;
    if (znak != '(') strm.setstate(std::ios::failbit);
    strm >> lz.re;
    strm >> lz.im;
    strm >> znak;
    if (znak != 'i') strm.setstate(std::ios::failbit);
    strm >> znak;
    if (znak != ')') strm.setstate(std::ios::failbit);
    return strm;

}
LZespolona Sprzezenie(const LZespolona lz)
{
    LZespolona l=lz;
    l.im= -l.im;
    return l;
}

double  abs(const LZespolona lz)
{
    double mod = sqrt(lz.re*lz.re+ lz.im*lz.im);
    return mod;
}
LZespolona operator / (const LZespolona lz,const double lr)
{

    LZespolona Wynik;

    if(lr==0)
    {
        std::cerr<<"Dzielenie przez zero\n";
        exit(1);
    }

        Wynik.re = lz.re / lr;
        Wynik.im = lz.im / lr;
        return Wynik;

}
LZespolona operator / (double l,LZespolona LZ)
{
    LZespolona LZ1(l,0);
    return LZ1/LZ;
}
LZespolona operator - (const LZespolona l1,const LZespolona l2)
{
    LZespolona Wynik;

    Wynik.re = l1.re - l2.re;
    Wynik.im = l1.im - l2.im;
    return Wynik;
}

LZespolona operator * (const LZespolona l1,const LZespolona l2)
{
    LZespolona Wynik;

    Wynik.re = l1.re*l2.re - l1.im*l2.im;
    Wynik.im = l1.re*l2.im + l1.im*l2.re;
    return Wynik;
}

LZespolona operator / (const LZespolona l1,const LZespolona l2)
{
    LZespolona Wynik;
    LZespolona Sprz;

    Sprz=Sprzezenie(l2);

    Wynik=l1 * Sprz;
    Wynik= Wynik / (abs(l2)*abs(l2));
    return Wynik;
}
bool operator  == (const LZespolona l1,const LZespolona l2)
{
    if(l1.re == l2.re && l1.im==l2.im) return true;
    return false;
}
bool operator != (const LZespolona l1,const LZespolona l2)
{
    if(l1==l2) return false;
    return  true;
}
LZespolona operator * (const double liczba, const LZespolona LZ)
{
    LZespolona LZP=LZ;
    LZP.re*=liczba;
    LZP.im*=liczba;

    return LZP;
}

