#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <string>

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    Pankkitili(std::string omistaja_nimi);
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
    double getBalance() const;
};

#endif // PANKKITILI_H 