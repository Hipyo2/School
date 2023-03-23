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
private:
virtual void serialize(std::ostream &outfile) const;
public:
Vehicle();
Vehicle(float *lla);
Vehicle(const Vehicle &vehicle);
virtual ~Vehicle();

float getLLA();
void setLLA(const float *lla);

virtual void move(float *lla) = 0;
friend std::ostream &operator<<(std::ostream &outfile,Vehicle &vehicle);
Vehicle &operator=(const Vehicle &vehicle);
};
#endif /* VEHICLE_H */
