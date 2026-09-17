#include "Room.h"
#include <iostream>
#include <iomanip>

using namespace std;

Room::Room() {
    roomId = "";
    roomType = "";
    price = 0;
    status = "AVAILABLE";
}

Room::Room(string roomId, string roomType, double price, string status) {
    this->roomId = roomId;
    this->roomType = roomType;
    this->price = price;
    this->status = status;
}

string Room::getRoomId() const {
    return roomId;
}

string Room::getRoomType() const {
    return roomType;
}

double Room::getPrice() const {
    return price;
}

string Room::getStatus() const {
    return status;
}

void Room::setRoomType(string roomType) {
    this->roomType = roomType;
}

void Room::setPrice(double price) {
    this->price = price;
}

void Room::setStatus(string status) {
    this->status = status;
}

void Room::display() const {
    cout << left
        << setw(12) << roomId
        << setw(20) << roomType
        << setw(15) << price
        << setw(15) << status
        << endl;
}
bool Room::operator<(const Room& other) const {
    return price < other.price;
}
