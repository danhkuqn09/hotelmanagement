#include "Service.h"
#include <iostream>

using namespace std;

Service::Service()
{
    serviceId = "";
    serviceName = "";
    price = 0;
}

Service::Service(string serviceId, string serviceName, double price)
{
    this->serviceId = serviceId;
    this->serviceName = serviceName;
    this->price = price;
}

string Service::getServiceId() const
{
    return serviceId;
}

string Service::getServiceName() const
{
    return serviceName;
}

double Service::getPrice() const
{
    return price;
}

void Service::setServiceName(string serviceName)
{
    this->serviceName = serviceName;
}

void Service::setPrice(double price)
{
    this->price = price;
}

void Service::display() const
{
    cout << serviceId << " | "
        << serviceName << " | "
        << price << endl;
}