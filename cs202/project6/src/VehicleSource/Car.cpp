#include <VehicleHeaders/Car.h>
#include <VehicleHeaders/Vehicle.h>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;
#define drivespeed 75 

Car::Car() 
{
setThrottle(0);
cout << "Car: Default-ctor" << endl;
}

Car::Car(float *lla) : Vehicle(lla)
{
setThrottle(0);
cout << "Car: Parameterized-ctor" << endl;
}

Car::Car(Car &car) : Vehicle(car.m_lla)
{
setThrottle(car.m_throttle);
cout << "Car: Copy-ctor" << endl;
}

Car::~Car()
{
cout << "Car: Dtor" << endl;
}

int Car::getThrottle()
{
return m_throttle;
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
cout << "Car: DRIVE to destination with throttle @ " << drivespeed << endl;
Car::drive(drivespeed);
setLLA(lla);
}

Car &Car::operator=(const Car &car)
{
if(this != &car)
{
setThrottle(car.m_throttle);
setLLA(car.m_lla);
}
cout << "Car: Assignment" << endl;
return *this;
}

void Car::serialize(std::ostream &outfile) const
{
const float *lla = m_lla;
outfile << "Car: Throttle: " << m_throttle << "@ [" << *lla;
lla++;
outfile << ", " << *lla;
lla++;
outfile << ", " << *lla << "]" << endl;
}


/*std::ostream &operator<<(std::ostream &outfile, Car &car)
{
float *lla = car.m_lla;
outfile << "Car #" << car.m_vin << " Plates: " << car.m_plates << " ,Throttle: " << car.m_throttle << " @ [" << *lla;
lla++;
outfile << ", " << *lla;
lla++;
outfile << ", " << *lla << "]" << endl;
return outfile;
}*/
