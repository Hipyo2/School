#include <VehicleHeaders/Vehicle.h>
#include <iostream>
#include <fstream>
using namespace std;
#define arraySizeLLA 3
int Vehicle::s_idgen = 0;

Vehicle::Vehicle() : m_vin(++s_idgen)
{
float *lla = m_lla;
for(int i = 0; i< arraySizeLLA;i++)
{
*lla = 0;
lla++;
}
cout << "Vehicle #" << m_vin << ": Default-ctor" << endl;
//s_idgen++;
}

Vehicle::Vehicle(int vin, float *lla) : m_vin(vin >=s_idgen ? vin : s_idgen)
{
/*if(vin >= s_idgen)
{
s_idgen = vin;
m_vin = s_idgen;
s_idgen++;
}
else
{
m_vin = s_idgen;
s_idgen++;
}*/
if(m_vin == vin)
{
s_idgen = vin;
}
else 
{
s_idgen = vin;
s_idgen++;
}
setLLA(lla);
cout << "Vehicle #" << vin << ": Parameterized-ctor" << endl;
}

Vehicle::Vehicle(Vehicle &vehicle) : m_vin(++s_idgen)
{
setLLA(vehicle.m_lla);
//m_vin = s_idgen;
//s_idgen++;
cout << "Vehicle #" << m_vin << ": Copy-ctor" << endl;
}

Vehicle::~Vehicle()
{
cout << "Vehicle #" << m_vin << ": Dtor" << endl;
}

float Vehicle::getLLA()
{
return *m_lla;
}

int Vehicle::getVin()
{
return m_vin;
}

int Vehicle::getIdgen()
{
return s_idgen;
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

/*void Vehicle::setVin(int vin)
{
m_vin = vin;

}*/

void Vehicle::move(float *lla) 
{
cout << "Vehicle #" << m_vin << ": CAN'T MOVE - I DON'T KNOW HOW" << endl;
}

std::ostream &operator<<(std::ostream &outfile, Vehicle &vehicle)
{
float *lla = vehicle.m_lla;
outfile << "Vehicle #" << vehicle.m_vin << " @ [" << *lla;
lla++;
outfile << ", " << *lla;
lla++;
outfile << ", " << *lla << "]" << endl;
return outfile;
}

Vehicle &Vehicle::operator=(const Vehicle &vehicle)
{
if(this != &vehicle)
{
setLLA(vehicle.m_lla);
}
cout << "Vehicle #" << vehicle.m_vin << ": Assignment" << endl;
return *this;
}
