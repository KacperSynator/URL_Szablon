#include "Wektor.cpp"

template class Wektor<LZespolona,5>;
template std::istream & operator >>(std::istream & strm, Wektor<LZespolona,5> & W);
template std::ostream & operator <<(std::ostream & strm, const Wektor<LZespolona,5> & W);
template Wektor<LZespolona,5> operator * (double l1, Wektor<LZespolona,5> W2);


template class Wektor<double,5>;
template std::istream & operator >>(std::istream & strm, Wektor<double,5> & W);
template std::ostream & operator <<(std::ostream & strm, const Wektor<double,5> & W);
template Wektor<double,5> operator * (double l1, Wektor<double,5> W2);
