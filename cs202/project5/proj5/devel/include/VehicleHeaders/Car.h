
#ifndef CAR_H
#define CAR_H
#define maxName 256
#include <fstream>
#include <VehicleHeaders/Vehicle.h>
using namespace std;
class Car : public Vehicle 
{
private:
char m_plates[maxName+1];
int m_throttle;
public:
Car();
Car(char *plates, int vin, float *lla);
Car(Car &car);
~Car();

char *getPlates();
int getThrottle();

void setPlates(char *plates);
void setThrottle(int throttle);

void move(float *lla);
void drive(int throttle);
Car &operator=(const Car &car);
friend std::ostream &operator<<(std::ostream &outfile, Car &car);
};

#endif /* CAR_H */
