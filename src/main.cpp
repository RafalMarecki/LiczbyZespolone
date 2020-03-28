#include <iostream>
#include <string>
#include <climits>
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
  int i;
  Statystyka S; S.dobra=0; S.zla=0;
  
    while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe)) {
    cout<<endl<<"Oblicz wyrazenie:"<<WyrZ_PytanieTestowe;
    cout<<endl<<endl;
    for (i=0; i<3; i++)
      {
	cout<<" Wpisz wynik:";
	cin>>Wynik;
	if (!cin.good())
	  {
	    cin.clear();
            cin.ignore(INT_MAX, '\n');
	    cout<<" Blad zapisu."<<endl;
	    if(i==0)
	      {
	        cout<<" Masz jeszcze 2 proby na wpisanie wyniku w poprawnym formacie."<<endl;
              }
	  }
	else
	  break;
      }
    
    if (Wynik == Oblicz(WyrZ_PytanieTestowe))
      {
	cout<<" Jest to poprawna odpowiedz\n"<<endl;
	dobra_odp(S);
      }
    else  /*Mógłbym tu napisać if(Wynik != Oblicz(WyrZ_PytanieTestowe))*/
      {
	cout<<" Jest to niepoprawna odpowiedz\n"<<endl;
	zla_odp(S);
      }
  }
  cout << endl;
  statystyka (S); /*Wyswietla ilosc popr. niepopr. odp. oraz % popr. odp.*/
  cout << " Koniec testu" << endl;
  cout << endl;

}
