#ifndef SEURAAJA_HPP
#define SEURAAJA_HPP

#include <string>

class Seuraaja {
private:
    std::string nimi;
    Seuraaja* next;

public:
    Seuraaja(const std::string& name);
    std::string getNimi() const;
    void paivitys(const std::string& viesti);
    
    friend class Notifikaattori;
    friend int main();
};

#endif // SEURAAJA_HPP 