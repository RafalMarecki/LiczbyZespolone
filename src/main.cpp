#include <iostream>
#include <string>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include "BazaTestu.hh"
#include "Statystyka.hh"
using namespace std;

/***********************************************************
 *
 * ABY ZAINICJALIZOWAĆ TEST TRUDNY, W PLIKU Makefile W LINIJCE 7 NALEZY 
 * ZMIENIĆ SŁOWO "latwy" NA SŁOWO "trudny"  
 *
 ***********************************************************/

int main(int argc, char **argv)
{

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };
  
  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;
  
  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Wynik;
  Statystyka S; S.dobra=0; S.zla=0;
  
    while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe)) {
    cout<<"Oblicz wyrazenie:"<<WyrZ_PytanieTestowe;
    cout<<endl<<" Twoja odpowiedz:";
    cin >> Wynik;
    if(!cin.good())/*Wychodzi z pętli, jeśli 3 razy wpisano zly format liczby*/
	break;
    if (Wynik == Oblicz(WyrZ_PytanieTestowe))
      {
	cout<<" Jest to poprawna odpowiedz\n"<<endl;
	dobra_odp(S);
      }
    else
      {
	cout<<" Jest to niepoprawna odpowiedz\n"<<endl;
	zla_odp(S);
      }
  }
  cout << endl;
  statystyka (S); /*Wyswietla procent poprawnych odpowiedzi*/
  cout << " Koniec testu" << endl;
  cout << endl;

}
