
#ifndef CAR_H
#define CAR_H
#define maxName 256
#include <VehicleHeaders/Vehicle.h>
using namespace std;
class Car : public Vehicle 
{
private:
int m_throttle;
virtual void serialize(std::ostream &outfile) const;
public:
Car();
Car(float *lla);
Car(Car &car);
virtual ~Car();

int getThrottle();

void setThrottle(int throttle);

virtual void move(float *lla);
void drive(int throttle);
Car &operator=(const Car &car);
//friend std::ostream &operator<<(std::ostream &outfile,const Car &car);
};

#endif /* CAR_H */
