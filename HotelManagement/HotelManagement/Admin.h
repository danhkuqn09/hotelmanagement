#ifndef ADMIN_H
#define ADMIN_H

#include "Person.h"
#include <iostream>

using namespace std;

class Admin : public Person {
public:

    Admin(string name = "Admin")
        : Person(name) {
    }

    void display() const override {
        cout << "Admin: " << name << endl;
    }

    void showInfo() const override {
        cout << "Quan tri vien: " << name << endl;
    }
};

#endif