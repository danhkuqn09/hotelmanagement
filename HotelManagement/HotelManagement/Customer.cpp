#include "Customer.h"
#include <iostream>
#include <iomanip>

using namespace std;

Customer::Customer() {
    customerId = "";
    name = "";
    phone = "";
}

Customer::Customer(string customerId,
    string name,
    string phone)
    : Person(name)
{
    this->customerId = customerId;
    this->phone = phone;
}

string Customer::getCustomerId() const {
    return customerId;
}

string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

void Customer::setName(string name) {
    this->name = name;
}

void Customer::setPhone(string phone) {
    this->phone = phone;
}

void Customer::display() const {
    cout << left
        << setw(15) << customerId
        << setw(30) << name
        << setw(15) << phone
        << endl;
}
void Customer::showInfo() const {
    cout << "Khach hang: " << name << endl;
}
