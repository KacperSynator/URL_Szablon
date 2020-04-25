#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>


struct  LZespolona {
    double   re;
    double   im;

    LZespolona() : re(0), im(0) {};
    LZespolona(double _re,double _im) : re(_re), im(_im) {};
    LZespolona operator = (const double l);
    double KonwersjaLZD();
    LZespolona operator += (const LZespolona & LZ) const;
    LZespolona operator += (const double & liczba) const;
    LZespolona operator * (const double liczba) const;

};

LZespolona operator * (const double liczba, const LZespolona LZ);
LZespolona operator + (const LZespolona  Skl1,const  LZespolona  Skl2);
LZespolona operator - (const LZespolona l1,const LZespolona l2);
LZespolona operator * (const LZespolona l1,const LZespolona l2);
LZespolona operator / (const LZespolona l1,const LZespolona l2);
bool operator  == (const LZespolona l1,const LZespolona l2);
bool operator  != (const LZespolona l1,const LZespolona l2);
LZespolona operator / (const LZespolona lz,const double lr);
std::ostream & operator << (std::ostream & strm, const LZespolona & lz);
std::istream & operator >> (std::istream & strm, LZespolona & lz);
LZespolona Sprzezenie(LZespolona lz);
double abs(const LZespolona lz);


#endif
