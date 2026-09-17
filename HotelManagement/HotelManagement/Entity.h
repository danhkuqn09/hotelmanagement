#ifndef ENTITY_H
#define ENTITY_H

class Entity {
public:
    virtual void display() const = 0;
    virtual ~Entity() {}
};

#endif