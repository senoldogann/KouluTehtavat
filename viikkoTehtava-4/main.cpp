#include "Asiakas.h"
#include <iostream>
#include <string>
using namespace std;

void tulostaMenu() {
    cout << "\nValitse toiminto (0-7):\n";
    cout << "1: Luo uusi asiakas\n";
    cout << "2: Talleta rahaa\n";
    cout << "3: Nosta rahaa\n";
    cout << "4: Nayta saldo\n";
    cout << "5: Nosta luottoa\n";
    cout << "6: Maksa luottoa\n";
    cout << "7: Tee tilisiirto\n";
    cout << "0: Lopeta\n";
    cout << "Valinta: ";
}

int main() {
    string nimi;
    double maara, luottoraja;
    int valinta;
    Asiakas* asiakas1 = nullptr;
    Asiakas* asiakas2 = nullptr;

    cout << "Tervetuloa pankkiohjelmaan!\n";

    do {
        tulostaMenu();
        cin >> valinta;

        switch(valinta) {
            case 1: {
                if (asiakas1 == nullptr) {
                    cout << "Anna asiakkaan nimi: ";
                    cin >> nimi;
                    cout << "Anna luottoraja: ";
                    cin >> luottoraja;
                    asiakas1 = new Asiakas(nimi, luottoraja);
                    cout << "Asiakas " << nimi << " luotu!\n";
                } else if (asiakas2 == nullptr) {
                    cout << "Anna toisen asiakkaan nimi: ";
                    cin >> nimi;
                    cout << "Anna luottoraja: ";
                    cin >> luottoraja;
                    asiakas2 = new Asiakas(nimi, luottoraja);
                    cout << "Asiakas " << nimi << " luotu!\n";
                } else {
                    cout << "Et voi luoda enempaa asiakkaita!\n";
                }
                break;
            }
            case 2: {
                if (asiakas1 == nullptr) {
                    cout << "Luo ensin asiakas!\n";
                    break;
                }
                cout << "Anna talletettava summa: ";
                cin >> maara;
                if (asiakas1->talletus(maara)) {
                    cout << "Talletus onnistui!\n";
                } else {
                    cout << "Talletus epaonnistui!\n";
                }
                break;
            }
            case 3: {
                if (asiakas1 == nullptr) {
                    cout << "Luo ensin asiakas!\n";
                    break;
                }
                cout << "Anna nostettava summa: ";
                cin >> maara;
                if (asiakas1->nosto(maara)) {
                    cout << "Nosto onnistui!\n";
                } else {
                    cout << "Nosto epaonnistui!\n";
                }
                break;
            }
            case 4: {
                if (asiakas1 == nullptr) {
                    cout << "Luo ensin asiakas!\n";
                    break;
                }
                asiakas1->showSaldo();
                break;
            }
            case 5: {
                if (asiakas1 == nullptr) {
                    cout << "Luo ensin asiakas!\n";
                    break;
                }
                cout << "Anna nostettava luotto: ";
                cin >> maara;
                if (asiakas1->luotonNosto(maara)) {
                    cout << "Luoton nosto onnistui!\n";
                } else {
                    cout << "Luoton nosto epaonnistui!\n";
                }
                break;
            }
            case 6: {
                if (asiakas1 == nullptr) {
                    cout << "Luo ensin asiakas!\n";
                    break;
                }
                cout << "Anna maksettava summa: ";
                cin >> maara;
                if (asiakas1->luotonMaksu(maara)) {
                    cout << "Luoton maksu onnistui!\n";
                } else {
                    cout << "Luoton maksu epaonnistui!\n";
                }
                break;
            }
            case 7: {
                if (asiakas1 == nullptr || asiakas2 == nullptr) {
                    cout << "Luo ensin kaksi asiakasta!\n";
                    break;
                }
                cout << "Anna siirrettava summa: ";
                cin >> maara;
                if (asiakas1->tiliSiirto(maara, *asiakas2)) {
                    cout << "Tilisiirto onnistui!\n";
                } else {
                    cout << "Tilisiirto epaonnistui!\n";
                }
                break;
            }
        }
    } while (valinta != 0);

    delete asiakas1;
    delete asiakas2;
    return 0;
} 