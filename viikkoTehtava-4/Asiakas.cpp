#include "Asiakas.h"
#include <iostream>

Asiakas::Asiakas(std::string nimi_param, double luottoraja) {
    nimi = nimi_param;
    kayttotili = new Pankkitili(nimi);
    luottotili = new Luottotili(nimi, luottoraja);
}

std::string Asiakas::getNimi() {
    return nimi;
}

void Asiakas::showSaldo() {
    std::cout << "Kayttotilin saldo: " << kayttotili->getBalance() << std::endl;
    std::cout << "Luottotilin saldo: " << luottotili->getBalance() << std::endl;
}

bool Asiakas::talletus(double amount) {
    return kayttotili->deposit(amount);
}

bool Asiakas::nosto(double amount) {
    return kayttotili->withdraw(amount);
}

bool Asiakas::luotonMaksu(double amount) {
    return luottotili->deposit(amount);
}

bool Asiakas::luotonNosto(double amount) {
    return luottotili->withdraw(amount);
}

bool Asiakas::tiliSiirto(double amount, Asiakas& toinen) {
    if (kayttotili->withdraw(amount)) {
        if (toinen.talletus(amount)) {
            return true;
        }
        kayttotili->deposit(amount);  
    }
    return false;
} 