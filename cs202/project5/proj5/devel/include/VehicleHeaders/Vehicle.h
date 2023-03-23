#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#define arraySizeLLA 3

class Vehicle
{
protected:
float m_lla[arraySizeLLA];
const int m_vin;
private:
static int s_idgen;
public:
Vehicle();
Vehicle( int vin,float *lla);
Vehicle(Vehicle &vehicle);
~Vehicle();

float getLLA();
int getVin();
static int getIdgen();

void setLLA(const float *lla);
//void setVin(int vin);

void move(float *lla);
friend std::ostream &operator<<(std::ostream &outfile, Vehicle &vehicle);
Vehicle &operator=(const Vehicle &vehicle);
};
#endif /* VEHICLE_H */
