#ifndef PERSON_H
#define PERSON_H

#include <string>
#include "Entity.h"
using namespace std;

class Person : public Entity {
protected:
    string name;

public:
    Person(string name = "") {
        this->name = name;
    }

    virtual void showInfo() const = 0;

    virtual ~Person() {}
};

#endif