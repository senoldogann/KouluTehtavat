#include "Pankkitili.h"

Pankkitili::Pankkitili(std::string omistaja_nimi) {
    omistaja = omistaja_nimi;
    saldo = 0; 
}

bool Pankkitili::deposit(double amount) {
    if (amount > 0) {  
        saldo = saldo + amount;
        return true;
    }
    return false;
}

bool Pankkitili::withdraw(double amount) {
    if (amount > 0 && saldo >= amount) {  
        saldo = saldo - amount;
        return true;
    }
    return false;
}

double Pankkitili::getBalance() const {
    return saldo;
} 