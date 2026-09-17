#ifndef HOTEL_H
#define HOTEL_H

#include <vector>

#include "Room.h"
#include "Customer.h"
#include "Booking.h"
#include "Service.h"
#include "Invoice.h"


class Hotel {
private:
    std::vector<Room> rooms;
    std::vector<Customer> customers;
    std::vector<Booking> bookings;
    std::vector<Service> services;
    std::vector<Invoice> invoices;


public:

    // ================= MENU =================
    void mainMenu();
    void roomMenu();
    void customerMenu();
    void bookingMenu();
    void reportMenu();
    void serviceMenu();
    void showServices();

    // ================= BOOKING =================
    void addBooking();
    void showBookings();

    // ================= CHECKOUT =================
    void checkout();
    void showUsingRooms();

    // ================= PAYMENT =================
    void payment();
    void showInvoices();

    // ================= ROOM =================
    void addRoom();
    void deleteRoom();
    void updateRoom();
    void showRooms();

    // ================= CUSTOMER =================
    void addCustomer();
    void deleteCustomer();
    void updateCustomer();
    void showCustomers();

    // ================= FILE =================
    void loadData();
    void saveData();
    // ================= SERVICE =================
    
    void addService();
    void deleteService();
    void updateService();
    // ================= SEARCH =================
    void searchMenu();
    void searchRoom();
    void searchCustomer();
    void searchBooking();
    
    
};

#endif