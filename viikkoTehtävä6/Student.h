#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

class Student {
private:
    std::string name;
    int age;

public:
    Student(std::string n, int a) : name(n), age(a) {}
    
    void setName(std::string n) { name = n; }
    void setAge(int a) { age = a; }
    
    std::string getName() const { return name; }
    int getAge() const { return age; }
    
    void printStudentInfo() const {
        std::cout << "Student " << name << " Age " << age << std::endl;
    }

    // İsme göre karşılaştırma için
    bool operator<(const Student& other) const {
        return name < other.name;
    }

    // Yaşa göre karşılaştırma için
    bool operator>(const Student& other) const {
        return age > other.age;
    }
};

#endif 