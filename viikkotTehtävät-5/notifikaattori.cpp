#include "notifikaattori.hpp"
#include <iostream>

Notifikaattori::Notifikaattori() : seuraajat(nullptr) {}

Notifikaattori::~Notifikaattori() {
    Seuraaja* current = seuraajat;
    while (current != nullptr) {
        Seuraaja* next = current->next;
        delete current;
        current = next;
    }
}

void Notifikaattori::lisaa(Seuraaja* seuraaja) {
    seuraaja->next = seuraajat;
    seuraajat = seuraaja;
}

void Notifikaattori::poista(Seuraaja* seuraaja) {
    if (seuraajat == nullptr) return;
    
    if (seuraajat == seuraaja) {
        seuraajat = seuraaja->next;
        return;
    }
    
    Seuraaja* current = seuraajat;
    while (current->next != nullptr) {
        if (current->next == seuraaja) {
            current->next = seuraaja->next;
            return;
        }
        current = current->next;
    }
}

void Notifikaattori::tulosta() {
    std::cout << "Notifikaattorin seuraajat:" << std::endl;
    Seuraaja* current = seuraajat;
    while (current != nullptr) {
        std::cout << "Seuraaja " << current->getNimi() << std::endl;
        current = current->next;
    }
}

void Notifikaattori::postita(const std::string& viesti) {
    std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;
    Seuraaja* current = seuraajat;
    while (current != nullptr) {
        current->paivitys(viesti);
        current = current->next;
    }
} 