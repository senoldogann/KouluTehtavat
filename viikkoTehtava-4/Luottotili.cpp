#include "Luottotili.h"

Luottotili::Luottotili(std::string omistaja_nimi, double raja) 
    : Pankkitili(omistaja_nimi) {
    luottoRaja = raja;
}

bool Luottotili::deposit(double amount) {
    if (amount > 0) {
        saldo = saldo + amount;
        return true;
    }
    return false;
}

bool Luottotili::withdraw(double amount) {
    if (amount > 0 && saldo - amount >= -luottoRaja) {
        saldo = saldo - amount;
        return true;
    }
    return false;
} 