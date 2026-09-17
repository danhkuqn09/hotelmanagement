#ifndef INVOICE_H
#define INVOICE_H

#include <string>
#include <iostream>

using namespace std;

class Invoice
{
private:
    string invoiceId;
    string customerId;
    string roomId;
    double total;

public:
    Invoice();

    Invoice(
        string invoiceId,
        string customerId,
        string roomId,
        double total
    );

    string getInvoiceId() const;
    string getCustomerId() const;
    string getRoomId() const;
    double getTotal() const;

    void display() const;
};

#endif