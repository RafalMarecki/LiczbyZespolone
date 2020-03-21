#ifndef LZESPOLONA_HH
#include <string>
#define LZESPOLONA_HH



/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */
LZespolona Utworz (double re, double im);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);
bool operator == (LZespolona  Skl1,  LZespolona  Skl2);
std::istream & operator >> (std::istream & strm,  LZespolona &Liczba);
std::ostream & operator << (std::ostream & strm, const LZespolona &Liczba);
/*bool Wczytaj_LZespolona (LZespolona &Liczba);*/

LZespolona Sprzezenie (LZespolona lz);
double Modul2 (LZespolona lz);
LZespolona operator / (LZespolona lz, double r);

void Wyswietl (LZespolona lz); 


#endif
