#include "Invoice.h"

Invoice::Invoice()
{
    invoiceId = "";
    customerId = "";
    roomId = "";
    total = 0;
}

Invoice::Invoice(
    string invoiceId,
    string customerId,
    string roomId,
    double total
)
{
    this->invoiceId = invoiceId;
    this->customerId = customerId;
    this->roomId = roomId;
    this->total = total;
}

string Invoice::getInvoiceId() const
{
    return invoiceId;
}

string Invoice::getCustomerId() const
{
    return customerId;
}

string Invoice::getRoomId() const
{
    return roomId;
}

double Invoice::getTotal() const
{
    return total;
}

void Invoice::display() const
{
    cout << "Ma hoa don: " << invoiceId << endl;
    cout << "Ma khach hang: " << customerId << endl;
    cout << "Ma phong: " << roomId << endl;
    cout << "Tong tien: " << total << endl;
}