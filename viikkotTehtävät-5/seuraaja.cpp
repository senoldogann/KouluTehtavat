#include "seuraaja.hpp"
#include <iostream>

Seuraaja::Seuraaja(const std::string& name) : nimi(name), next(nullptr) {}

std::string Seuraaja::getNimi() const {
    return nimi;
}

void Seuraaja::paivitys(const std::string& viesti) {
    std::cout << "Seuraaja " << nimi << " sai viestin " << viesti << std::endl;
} 