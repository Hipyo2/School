//Nicholas Ang
//Project 3
//RentalCar Class Header File and Implementations

#include "RentalCar.h"
#include "my_string.h"
#include <iostream>
#include <fstream>
using namespace std;

RentalCar::RentalCar()
{
setYear(0);
setPrice(0);
setAvailable(false);
}

RentalCar::RentalCar(int year, char *make, char *model, double price, bool available)
{
setYear(year);
setPrice(price);
setAvailable(false);
setMake(make);
setModel(model);
}

int RentalCar::getYear()
{
return m_year;
}

void RentalCar::setYear(int year)
{
m_year = year;
}

double RentalCar::getPrice()
{
return m_price;
}
void RentalCar::setPrice(double price)
{
m_price = price;
}

bool RentalCar::getAvailable()
{
return m_available;
}
void RentalCar::setAvailable(bool available)
{
m_available = available;
}

char RentalCar::getMake()
{
return *m_make;
}
void RentalCar::setMake(char *make)
{
myStringCopy(m_make,make);
}

char RentalCar::getModel()
{
return *m_model;
}
void RentalCar::setModel(char *model)
{
myStringCopy(m_model,model);
}

void RentalCar::fileInput(std::ifstream &infile)
{
infile >> m_year >> m_make >> m_model >> m_price >> m_available;
}

void RentalCar::print()
{
cout << m_year << " " << m_make << " " << m_model << ", $" << m_price << " per day, Available: " << std::boolalpha << m_available << " " << endl;


}

double RentalCar::getEstimate(int days)
{
double estimatePrice;
estimatePrice = m_price * days;

return estimatePrice;
}
