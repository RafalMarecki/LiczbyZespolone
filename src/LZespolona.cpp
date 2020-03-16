#include "LZespolona.hh"
#include <iostream>
#include <cstdio>
#include <math.h>
#include <cmath>
#include <string>

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona Sprzezenie (LZespolona lz)
{
  lz.im = -lz.im;
  return lz;
}

double Modul2 (LZespolona lz)
{
  double Wynik;
  Wynik = pow(lz.re,2) + pow(lz.im,2);
  return Wynik;
}

LZespolona DzielenieR (LZespolona lz, double r)
{
  LZespolona Wynik;
  Wynik.re = lz.re/r;
  Wynik.im = lz.im/r;
  return Wynik;
}

LZespolona Utworz (double re, double im) /***/
{
  LZespolona lz;
  lz.re = re;
  lz.im = im;
  return lz;
}

void Wyswietl (LZespolona lz) /***/
{
  cout<<"("<<lz.re<<std::showpos<<lz.im<<std::noshowpos<<"i)\n";
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;
  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.im * Skl2.re + Skl1.re * Skl2.im;
  return Wynik;
}

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik, Sprze;
  double Mod;
  Sprze = Sprzezenie(Skl2);
  Mod = Modul2(Skl2);
  Wynik= DzielenieR (Skl1 * Sprze, Mod);
  return Wynik;  
}

bool operator == (LZespolona  Skl1,  LZespolona  Skl2)
{
  bool Wynik = false;
  if (Skl1.re == Skl2.re && Skl1.im == Skl2.im)
    Wynik = true;
  return Wynik;
}

LZespolona operator >> (string Liczba) /*****************************/
{
  LZespolona Wynik;
  string Liczba1, Liczba2;
  
  for (int i = 1; i < sizeof(Liczba)-3; i ++)
    {
      while (isdigit(Liczba[i]))
	{
	  Liczba1 += Liczba[i];
	}
      Wynik.re = stod (Liczba1);
      if (i==sizeof(Liczba)-2)
	Wynik.im = stod (Liczba2);
    }
  return Wynik;
}

