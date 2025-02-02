#ifndef ASIAKAS_H
#define ASIAKAS_H

#include "Pankkitili.h"
#include "Luottotili.h"
#include <string>

class Asiakas {
private:
    std::string nimi;
    Pankkitili* kayttotili;
    Luottotili* luottotili;

public:
    Asiakas(std::string nimi, double luottoraja);
    std::string getNimi();
    void showSaldo();
    bool talletus(double amount);
    bool nosto(double amount);
    bool luotonMaksu(double amount);
    bool luotonNosto(double amount);
    bool tiliSiirto(double amount, Asiakas& toinen);
};

#endif 