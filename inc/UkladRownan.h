#ifndef URL_UKLADROWNAN_H
#define URL_UKLADROWNAN_H

#include "MacierzKw.h"
#include <iomanip>

template<class TYP,int ROZMIAR>
class UkladRownan {

MacierzKw<TYP,ROZMIAR> A;
Wektor<TYP,ROZMIAR> B;

public:

    enum MetodaOliczania{MacierOdwrotna, Cramer, Gauss};

    UkladRownan() = default;
    UkladRownan(MacierzKw<TYP,ROZMIAR> AA, Wektor<TYP,ROZMIAR> bb) : A(AA), B(bb) {};

    const Wektor<TYP,ROZMIAR> & ZwrocWektorWolny() { return B; };
    const MacierzKw<TYP,ROZMIAR> & ZwrocMcierz() { return A; };
    Wektor<TYP,ROZMIAR> ZwrocWektorBledu () {return A*Oblicz(Gauss)-B;};

    void ZmienWektorWolny(Wektor<TYP,ROZMIAR> nowy)
    {
        B=nowy;
    }

    void ZmienMacierz(MacierzKw<TYP,ROZMIAR> nowy)
    {
        A=nowy;
    }


    Wektor<TYP,ROZMIAR> Oblicz(const MetodaOliczania Metoda) const
    {
        Wektor<TYP,ROZMIAR> X;
        MacierzKw<TYP,ROZMIAR> MP=A;

        switch (Metoda)
        {
            case MacierOdwrotna:
                X=MP.Odwrotnosc()*B;
                break;

            case Cramer:
            {
                TYP wyzG;
                wyzG = MP.Wyznacznik(MacierzKw<TYP,ROZMIAR>::Gauss);
                if (wyzG == 0) {
                    std::cout << "Równanie sprzeczne lub jest nieskończenie wiele rozwiązań" << std::endl;
                    exit(1);
                }
                for (int i = 1; i <= ROZMIAR; ++i) {
                    MP = A;
                    MP.ZmienKolumne(i - 1, B);
                    X[i - 1] = MP.Wyznacznik(MacierzKw<TYP,ROZMIAR>::Gauss) / wyzG;
                }
                break;
            }

            case Gauss:
                MP=A;
                X=B;
                TYP l;
                if(MP.Wyznacznik(MacierzKw<TYP,ROZMIAR>::Gauss)==0)
                {
                    std::cout << "Równanie sprzeczne lub jest nieskończenie wiele rozwiązań" << std::endl;
                    exit (1);
                }
                else
                    for (int i = 0; i <ROZMIAR-1 ; ++i)
                    {
                        if(MP[i][i]==0)
                        {
                            for (int k = 0; k < ROZMIAR; k++)
                            {
                                if (MP[i][k] != 0)
                                {
                                    Wektor WP = MP[i];
                                    TYP lp;
                                    lp=X[i];
                                    MP[i] = MP[k];
                                    X[i]=X[k];
                                    MP[k] = WP;
                                    X[k]=lp;
                                    break;
                                }
                            }

                        }
                        for (int j = i+1; j <ROZMIAR ; ++j)
                        {

                                l = MP[j][i]/MP[i][i];

                            MP[j]=MP[j]-l*MP[i];
                            X[j]=X[j]-l*X[i];
                        }
                    }
                for (int i = ROZMIAR-1; i >0 ; --i)
                {
                    if(MP[i][i]==0)
                    {
                        for (int k = 0; k < ROZMIAR; k++)
                        {
                            if (MP[i][k] != 0)
                            {
                                Wektor WP = MP[i];
                                TYP lp=X[i];
                                MP[i] = MP[k];
                                X[i]=X[k];
                                MP[k] = WP;
                                X[k]=lp;
                                break;
                            }
                        }

                    }
                    for (int j =i-1; j >=0 ; --j)
                    {
                        TYP l;
                        l= MP[j][i]/MP[i][i];
                        MP[j]=MP[j]-l*MP[i];
                        X[j]=X[j]-l*X[i];
                    }
                }
                for(int i=0;i<ROZMIAR;i++)
                {
                    X[i]=X[i]/MP[i][i];
                }
                break;

        }
        return X;
    }

};

template<class TYP,int ROZMIAR>
std::ostream & operator << (std::ostream & strm, UkladRownan<TYP,ROZMIAR> & UR)
{
    for (int i = 0; i < ROZMIAR; ++i)
    {
        strm<<'|';
        for (int j = 0; j < ROZMIAR; ++j)
            strm << std::setw(10) << UR.ZwrocMcierz()[i][j];

        strm<< std::setw(3)<<'|'<<std::setw(3)<<"| x_"<<i+1<<" |";
        if(i+1==(ROZMIAR+1)/2)
            strm<<std::setw(3)<<'='<<std::setw(3)<<'|'<<std::setw(7)<<UR.ZwrocWektorWolny()[i]<<std::setw(2)<<'|'<<std::endl;
        else
            strm<<std::setw(6)<<'|'<<std::setw(7)<<UR.ZwrocWektorWolny()[i]<<std::setw(2)<<'|'<<std::endl;
    }

    return strm;
}
template<class TYP,int ROZMIAR>
std::istream & operator >> (std::istream & strm, UkladRownan<TYP,ROZMIAR> & UR)
{
    MacierzKw<TYP,ROZMIAR> MP;
    Wektor<TYP,ROZMIAR> WP;

    strm>>MP>>WP;
    UR.ZmienMacierz(MP.transpozycja());
    UR.ZmienWektorWolny(WP);

    return  strm;
}

#endif
