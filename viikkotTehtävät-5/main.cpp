#include "notifikaattori.hpp"
#include "seuraaja.hpp"
#include <iostream>
#include <string>
#include <limits>

void tulostaMenu() {
    std::cout << "\nNotifikaattori Menü:" << std::endl;
    std::cout << "1. Lisää seuraaja" << std::endl;
    std::cout << "2. Poista seuraaja" << std::endl;
    std::cout << "3. Näytä kaikki seuraajat" << std::endl;
    std::cout << "4. Lähetä viesti" << std::endl;
    std::cout << "0. Lopeta" << std::endl;
    std::cout << "Valitse toiminto (0-4): ";
}

int main() {
    Notifikaattori n;
    int valinta;
    std::string nimi, viesti;
    
    std::cout << "Tervetuloa Notifikaattori-järjestelmään!" << std::endl;
    
    do {
        tulostaMenu();
        std::cin >> valinta;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch(valinta) {
            case 1: {
                std::cout << "Anna seuraajan nimi: ";
                std::getline(std::cin, nimi);
                Seuraaja* uusi = new Seuraaja(nimi);
                n.lisaa(uusi);
                std::cout << "Seuraaja " << nimi << " lisätty!" << std::endl;
                break;
            }
            case 2: {
                std::cout << "Anna poistettavan seuraajan nimi: ";
                std::getline(std::cin, nimi);
                
                // Etsi ja poista seuraaja
                Seuraaja* current = n.seuraajat;
                Seuraaja* poistettava = nullptr;
                
                while (current != nullptr) {
                    if (current->getNimi() == nimi) {
                        poistettava = current;
                        break;
                    }
                    current = current->next;
                }
                
                if (poistettava != nullptr) {
                    n.poista(poistettava);
                    delete poistettava;
                    std::cout << "Seuraaja " << nimi << " poistettu!" << std::endl;
                } else {
                    std::cout << "Seuraajaa ei löytynyt!" << std::endl;
                }
                break;
            }
            case 3:
                n.tulosta();
                break;
            case 4: {
                std::cout << "Kirjoita lähetettävä viesti: ";
                std::getline(std::cin, viesti);
                n.postita(viesti);
                break;
            }
            case 0:
                std::cout << "Kiitos ja näkemiin!" << std::endl;
                break;
            default:
                std::cout << "Virheellinen valinta!" << std::endl;
        }
        
    } while (valinta != 0);
    
    // Siivotaan muisti
    Seuraaja* current = n.seuraajat;
    while (current != nullptr) {
        Seuraaja* next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
} 