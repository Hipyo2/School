//Nicholas Ang
//Project 4
//Car Class Header File

#ifndef CAR_H
#define CAR_H

//Libraries and Header Files
#include <files/Sensor.h>
#include <fstream>
using namespace std;

//Global Constants
#define maxName 256
#define maxSensors 3

//Class Car Declarations
class Car
{
//Private Methods
private:
//Data Values
int m_year;
char m_model[maxName+1];
char m_make[maxName+1];
Sensor m_sensor[maxSensors];
double m_baseprice;
double m_finalprice;
bool m_available;
char m_owner[maxName+1];

//Public Methods
public:
//Constructors
Car();
Car(int year, char *model, char *make, char *owner, double baseprice, bool available, Sensor *sensor);
Car(Car &car);
//Getters and Setters
int getYear() const;
char *getModel();
char *getMake();
Sensor *getSensor();
double getBasePrice() const;
double getFinalPrice() const;
bool getAvailable() const;
char *getOwner();

void setYear(int year);
void setModel(char *model);
void setMake(char *make);
void setBasePrice(double baseprice);
void setAvailable(bool available);
void setOwner(char *owner);

//Car Method Functions to update price, print out cars and their information, and estimate cost;
double updatePrice();
void printCar();
double estimateCost(int days);

//Operator Overloads to add sensors, add owners, and read in information of car
friend std::ifstream &operator>>(std::ifstream &infile, Car &car);
Car &operator+(Sensor &sensor);
Car &operator+(const char *lessee);
};


#endif /* CAR_H */
