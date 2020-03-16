#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>
#include <cstdio>

using namespace std;

void Wyswietl(WyrazenieZesp  WyrZ)
{
  cout<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg1.im<<std::noshowpos<<"i)"<<WyrZ.Op<<"("<<WyrZ.Arg2.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)\n";
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
  switch(WyrZ.Op)
    {
    case 0:
      Wynik = WyrZ.Arg1 + WyrZ.Arg2;
      break;
      
    case 1:
      Wynik = WyrZ.Arg1 - WyrZ.Arg2;
      break;

    case 2:
      Wynik = WyrZ.Arg1 * WyrZ.Arg2;
      break;

    case 3:
      Wynik = WyrZ.Arg1 + WyrZ.Arg2;
      break;
    }
  return Wynik;
}

