#include <iostream>
#include "Statystyka.hh"

using namespace std;

void dobra_odp (Statystyka &s)
{
  s.dobra++;
}

void zla_odp (Statystyka &s)
{
  s.zla++;
}

double procent (Statystyka s)
{
  double procent=s.dobra*100/(s.dobra+s.zla);
  return procent;
}

void statystyka (Statystyka s)
{
  cout<<"Ilosc poprawnych odpowiedzi: "<<s.dobra<<endl;
  cout<<"Ilosc niepoprawnych odpowiedzi: "<<s.zla<<endl;
  if(s.dobra==0)
    {
      cout<<"Procent poprawnych odpowiedzi: "<<"0%"<<endl;
    }
  else
  cout<<"Procent poprawnych odpowiedzi: "<<procent(s)<<"%"<<endl;
}
