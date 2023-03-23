#include <VehicleHeaders/Car.h>
#include <VehicleHeaders/Vehicle.h>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#define drivespeed 75 

Car::Car() 
{
strcpy(m_plates, "");
setThrottle(0);
cout << "Car #" << m_vin << ": Default-ctor" << endl;
}

Car::Car(char *plates,int vin , float *lla) : Vehicle(vin,lla)
{
setThrottle(0);
setPlates(plates);
cout << "Car #" << m_vin << ": Parameterized-ctor" << endl;
}

Car::Car(Car &car) : Vehicle(car)
{
setThrottle(car.m_throttle);
setPlates(car.m_plates);
cout << "Car #" << m_vin << ": Copy-ctor" << endl;
}

Car::~Car()
{
cout << "Car #" << m_vin << ": Dtor" << endl;
}

char *Car::getPlates()
{
return m_plates;
}

int Car::getThrottle()
{
return m_throttle;
}

void Car::setPlates(char *plates)
{
strcpy(m_plates,plates);
}

void Car::setThrottle(int throttle)
{
m_throttle = throttle;
}

void Car::drive(int throttle)
{
Car::setThrottle(throttle);
}

void Car::move(float *lla)
{
cout << "Car #" << m_vin << ": DRIVE to destination with throttle @ 75" << endl;
Car::drive(drivespeed);
setLLA(lla);
}

Car &Car::operator=(const Car &car)
{
if(this != &car)
{
setThrottle(car.m_throttle);
strcpy(m_plates,car.m_plates);
setLLA(car.m_lla);
}
cout << "Car #" << car.m_vin << ": Assignment" << endl;
return *this;
}


std::ostream &operator<<(std::ostream &outfile, Car &car)
{
float *lla = car.m_lla;
outfile << "Car #" << car.m_vin << " Plates: " << car.m_plates << " ,Throttle: " << car.m_throttle << " @ [" << *lla;
lla++;
outfile << ", " << *lla;
lla++;
outfile << ", " << *lla << "]" << endl;
return outfile;
}
