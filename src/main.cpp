#include <iostream>
#include <string>
#include <climits>
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
  
  WyrazenieZesp WyrZ_PytanieTestowe;
  LZespolona Wynik; 
  
    while (PobierzNastpnePytanie(&BazaT, &WyrZ_PytanieTestowe)) {
    cout<<"Oblicz wyrazenie:";
    cout<<WyrZ_PytanieTestowe; /* Test przeciazenia oeratora << dla WyrazenieZesp */
    /*Wyswietl(WyrZ_PytanieTestowe);*/ /* DZIAŁA*/
    cout<<endl<<"Twoja odpowiedz:";
    cin >> Wynik;
    cout << "Poprawny wynik to:" << Oblicz(WyrZ_PytanieTestowe); 
    cout << "Ty odpowiedziales:" << Wynik; /* Testuje przeciazenie operatora << dla LZespolona*/
    if (Wynik == Oblicz(WyrZ_PytanieTestowe)) 
      cout<<"Jest to poprawna odpowiedz\n"<<endl;
    else
      cout<<"Jest to niepoprawna odpowiedz\n"<<endl;
    cin.clear();
  }
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
