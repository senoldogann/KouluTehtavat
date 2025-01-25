#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <iostream>
using namespace std;  

class Chef {
protected:  
    string name;  

public:
    Chef(string n); 
    virtual ~Chef();
    string getName() { return name; }  
    int makeSalad(int amount);
    int makeSoup(int amount);
};

class ItalianChef : public Chef {
private:
    string password;
    int flour;
    int water;
    int makePizza();

public:
    ItalianChef(string n);
    ~ItalianChef();
    bool askSecret(string pwd, int f, int w);  
};

#endif 