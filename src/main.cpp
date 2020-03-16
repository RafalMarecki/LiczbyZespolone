#include <iostream>
#include <string>
#include "WyrazenieZesp.hh"
#include "LZespolona.hh"
#include "BazaTestu.hh"

using namespace std;




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

  LZespolona L1 = Utworz(2,3); /***/
  Wyswietl(L1);
  LZespolona L2 = Utworz(2,-3);
  Wyswietl(L2);
  LZespolona L3 = L1 + L2;
  Wyswietl(L3);

  L1 = Utworz(1,2); /***/
  Wyswietl(L1);
  L2 = Utworz(3,4);
  Wyswietl(L2);
  L3 = L1 * L2;
  Wyswietl(L3);
  LZespolona L4 = L1 / L2;
  Wyswietl(L4);

  WyrazenieZesp   WyrZ_PytanieTestowe;
  LZespolona Wynik;
  string Liczba;
  
  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    cout<<"Oblicz wyrazenie:";
    Wyswietl(WyrZ_PytanieTestowe); /*DZIAŁA*/
    
    cout<<endl<<"Twoja odpowiedz:";
    cin >> Liczba; /**********************/
    /*Wynik = Liczba;*/
    if (Wynik == Oblicz(WyrZ_PytanieTestowe))
      cout<<"Poprawna odpowiedz\n";
    else
      cout<<"Niepoprawna odpowiedz\n";
      /*
    cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
      */
  }

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
