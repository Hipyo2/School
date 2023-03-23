#include <VehicleHeaders/Vehicle.h>
#include <iostream>
#include <fstream>
using namespace std;
#define arraySizeLLA 3

Vehicle::Vehicle()
{
float *lla = m_lla;
for(int i = 0; i< arraySizeLLA;i++)
{
*lla = 0;
lla++;
}
cout << "Vehicle: Default-ctor" << endl;
}

Vehicle::Vehicle(float *lla)
{
setLLA(lla);
cout << "Vehicle: Parameterized-ctor" << endl;
}

Vehicle::Vehicle(const Vehicle &vehicle)
{
setLLA(vehicle.m_lla);
cout << "Vehicle: Copy-ctor" << endl;
}

Vehicle::~Vehicle()
{
cout << "Vehicle: Dtor" << endl;
}

float Vehicle::getLLA()
{
return *m_lla;
}

void Vehicle::setLLA(const float *lla)
{
float *vehiclella = m_lla;
for(int i=0; i< arraySizeLLA; i++)
{
*vehiclella = *(lla+i);
vehiclella++;
}

}

std::ostream &operator<<(std::ostream &outfile, Vehicle &vehicle)
{
vehicle.serialize(outfile);
return outfile;
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle)
{
if(this != &vehicle)
{
setLLA(vehicle.m_lla);
}
cout << "Vehicle: Assignment" << endl;
return *this;
}

void Vehicle::serialize(std::ostream &outfile) const
{
const float *lla = m_lla;
outfile << "Vehicle" << " @ [" << *lla;
lla++;
outfile << ", " << *lla;
lla++;
outfile << ", " << *lla << "]" << endl;
}
