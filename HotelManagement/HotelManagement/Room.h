#ifndef ROOM_H
#define ROOM_H

#include <string>
#include "Entity.h"

using namespace std;

class Room : public Entity {
private:
    string roomId;
    string roomType;
    double price;
    string status;

public:
    Room();

    Room(
        string roomId,
        string roomType,
        double price,
        string status
    );

    string getRoomId() const;
    string getRoomType() const;
    double getPrice() const;
    string getStatus() const;

    void setRoomType(string roomType);
    void setPrice(double price);
    void setStatus(string status);

    void display() const override;

    // Operator overloading
    bool operator<(const Room& other) const;
};

#endif