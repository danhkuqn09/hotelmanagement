#ifndef SERVICE_H
#define SERVICE_H

#include <string>

using namespace std;

class Service
{
private:
    string serviceId;
    string serviceName;
    double price;

public:
    Service();

    Service(string serviceId, string serviceName, double price);

    string getServiceId() const;
    string getServiceName() const;
    double getPrice() const;

    void setServiceName(string serviceName);
    void setPrice(double price);

    void display() const;
};

#endif