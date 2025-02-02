#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoRaja;  

public:
    Luottotili(std::string omistaja_nimi, double raja);
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};

#endif 