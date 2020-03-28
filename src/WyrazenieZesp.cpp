#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include <iostream>
#include <cstdio>

using namespace std;

/* FUNKCJA TA ZOSTALA ZASTAPIONA OPERATOREM << DLA WYRAZENIA ZESPOLONEGO I 
NIE JEST UZYWANA W PROGRAMIE! ALE ZOSTAWIAM JĄ BO NALEŻAŁO DOSTARCZYĆ JĄ BODAJŻE NA TYDZIEŃ 1.
void Wyswietl(WyrazenieZesp  WyrZ)
{
  switch(WyrZ.Op)
    {
    case 0:
      cout<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg1.im<<std::noshowpos<<"i)"<<"+"<<"("<<WyrZ.Arg2.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)";
      break;
      
    case 1:
      cout<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg1.im<<std::noshowpos<<"i)"<<"-"<<"("<<WyrZ.Arg2.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)";
      break;

    case 2:
      cout<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg1.im<<std::noshowpos<<"i)"<<"*"<<"("<<WyrZ.Arg2.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)";
      break;

    case 3:
      cout<<"("<<WyrZ.Arg1.re<<std::showpos<<WyrZ.Arg1.im<<std::noshowpos<<"i)"<<"/"<<"("<<WyrZ.Arg2.re<<std::showpos<<WyrZ.Arg2.im<<std::noshowpos<<"i)";
      break;
    }
}
*/

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
      Wynik = WyrZ.Arg1 / WyrZ.Arg2;
      break;
    }
  return Wynik;  
}

std::ostream & operator << (std::ostream & strm, const WyrazenieZesp &WyrZ)
{ 
  switch(WyrZ.Op)
    {
    case 0:
      strm<<WyrZ.Arg1<<"+"<<WyrZ.Arg2;
      break;
      
    case 1:
      strm<<WyrZ.Arg1<<"-"<<WyrZ.Arg2;
      break;

    case 2:
      strm<<WyrZ.Arg1<<"*"<<WyrZ.Arg2;
      break;

    case 3:
      strm<<WyrZ.Arg1<<"/"<<WyrZ.Arg2;
      break;
    }
  return strm;
}


