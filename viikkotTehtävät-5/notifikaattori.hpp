#ifndef NOTIFIKAATTORI_HPP
#define NOTIFIKAATTORI_HPP

#include "seuraaja.hpp"

class Notifikaattori {
public:
    Seuraaja* seuraajat;

    Notifikaattori();
    ~Notifikaattori();
    void lisaa(Seuraaja* seuraaja);
    void poista(Seuraaja* seuraaja);
    void tulosta();
    void postita(const std::string& viesti);
};

#endif // NOTIFIKAATTORI_HPP 