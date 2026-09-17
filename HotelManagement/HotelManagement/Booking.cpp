#include "Booking.h"
#include <iostream>
#include <iomanip>

using namespace std;

// ==========================================
// CONSTRUCTOR
// ==========================================

Booking::Booking() {
    bookingId = "";
    customerId = "";
    roomId = "";
    checkIn = "";
    checkOut = "";
    status = "USING";
}

Booking::Booking(
    string bookingId,
    string customerId,
    string roomId,
    string checkIn,
    string checkOut,
    string status
) {
    this->bookingId = bookingId;
    this->customerId = customerId;
    this->roomId = roomId;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->status = status;
}

// ==========================================
// GETTER
// ==========================================

string Booking::getBookingId() const {
    return bookingId;
}

string Booking::getCustomerId() const {
    return customerId;
}

string Booking::getRoomId() const {
    return roomId;
}

string Booking::getCheckIn() const {
    return checkIn;
}

string Booking::getCheckOut() const {
    return checkOut;
}

string Booking::getStatus() const {
    return status;
}

// ==========================================
// SETTER
// ==========================================

void Booking::setStatus(string status) {
    this->status = status;
}

// ==========================================
// DISPLAY
// ==========================================

void Booking::display() const {

    cout << left
        << setw(12) << bookingId
        << setw(12) << customerId
        << setw(12) << roomId
        << setw(15) << checkIn
        << setw(15) << checkOut
        << setw(15) << status
        << endl;
}