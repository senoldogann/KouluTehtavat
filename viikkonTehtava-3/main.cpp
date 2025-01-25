#include "chef.h"

int main() {
    Chef gordon("Gordon");
    gordon.makeSalad(11);
    gordon.makeSoup(14);
    
    ItalianChef mario("Mario");
    mario.makeSalad(9);
    mario.askSecret("pizza", 12, 12);
    
    return 0;
} 