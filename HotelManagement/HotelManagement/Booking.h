#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include "Entity.h"

class Booking : public Entity {
private:
    std::string bookingId;
    std::string customerId;
    std::string roomId;
    std::string checkIn;
    std::string checkOut;
    std::string status; // USING / CHECKEDOUT

public:
    Booking();

    Booking(
        std::string bookingId,
        std::string customerId,
        std::string roomId,
        std::string checkIn,
        std::string checkOut,
        std::string status = "USING"
    );

    std::string getBookingId() const;
    std::string getCustomerId() const;
    std::string getRoomId() const;
    std::string getCheckIn() const;
    std::string getCheckOut() const;
    std::string getStatus() const;

    void setStatus(std::string status);

    void display() const override;
};

#endif