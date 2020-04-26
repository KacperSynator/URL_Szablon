#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>


struct  LZespolona {
    double   re;
    double   im;

    LZespolona() {};
    LZespolona(double _re,double _im) : re(_re), im(_im) {};
    LZespolona & operator = (double l);
    double KonwersjaLZD() const;
    LZespolona  operator += (const LZespolona & LZ) const;
    LZespolona operator += (const double & liczba) const;
    LZespolona operator * (double liczba) const;

};

LZespolona operator * (double liczba, LZespolona LZ);
LZespolona operator + (LZespolona  Skl1, LZespolona  Skl2);
LZespolona operator - (LZespolona l1,LZespolona l2);
LZespolona operator * (LZespolona l1,LZespolona l2);
LZespolona operator / (LZespolona l1,LZespolona l2);
bool operator  == (LZespolona l1,LZespolona l2);
bool operator  != (LZespolona l1,LZespolona l2);
LZespolona operator / (LZespolona lz,double lr);
std::ostream & operator << (std::ostream & strm, const LZespolona & lz);
std::istream & operator >> (std::istream & strm, LZespolona & lz);
LZespolona Sprzezenie(LZespolona lz);
double abs(LZespolona lz);


#endif
