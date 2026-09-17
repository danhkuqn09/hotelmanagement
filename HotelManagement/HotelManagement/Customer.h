#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include "Person.h"


using namespace std;

class Customer : public Person {
private:
    string customerId;
    string phone;

public:
    Customer();

    Customer(
        string customerId,
        string name,
        string phone
    );

    // Getter
    string getCustomerId() const;
    string getName() const;
    string getPhone() const;

    // Setter
    void setName(string name);
    void setPhone(string phone);

    // Da hinh
    void display() const override;
    void showInfo() const override;
};

#endif