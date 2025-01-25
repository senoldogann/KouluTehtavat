#include "chef.h"

Chef::Chef(string n) {
    name = n;  
    cout << "Chef " << n << " konstruktori" << endl;
}

Chef::~Chef() {
    cout << "Chef " << name << " destruktori" << endl;
}

int Chef::makeSalad(int amount) {
    int result = amount / 5; 
    cout << "Chef " << name << " with " << amount << " items can make salad " << result << " portions" << endl;
    return result;
}

int Chef::makeSoup(int amount) {
    int result = amount / 3;
    cout << "Chef " << name << " with " << amount << " items can make soup " << result << " portions" << endl;
    return result;
}


ItalianChef::ItalianChef(string n) : Chef(n) {  
    password = "pizza"; 
    flour = 0;
    water = 0;
    cout << "ItalianChef " << n << " konstruktori" << endl;
}

ItalianChef::~ItalianChef() {
    cout << "ItalianChef " << name << " destruktori" << endl;
}

bool ItalianChef::askSecret(string pwd, int f, int w) {
    flour = f;
    water = w;
    
    if (pwd == password) {
        cout << "Password ok!" << endl;
        makePizza();
        return true;
    }
    return false;
}

int ItalianChef::makePizza() {
    int pizzas = min(flour/5, water/5);
    cout << "ItalianChef " << name << " with " << flour << " flour and " 
         << water << " water can make " << pizzas << " pizzas" << endl;
    return pizzas;
} 