//Nicholas Ang
//Project 4
//Car Class Source File

//Libraries and Header Files
#include <files/Car.h>
#include <files/Sensor.h>
#include <files/my_string.h>
#include <files/Agency.h>
#include <fstream>
#include <iostream>
using namespace std;

//Global Constants
#define maxSensors 3
#define maxCars 5
//Car Default Constructor
Car::Car()
{
	//Sets everything to 0 
	m_year = 0;
	myStringCopy(m_model,"\0");
	myStringCopy(m_make,"\0");
	myStringCopy(m_owner,"\0");
	m_baseprice = 0.0;
	m_finalprice = 0.0;
	m_available = false;
}

//Car Parameterized Constructor
Car::Car(int year, char *model, char *make, char *owner, double baseprice, bool available, Sensor *sensor)
{
	Sensor *sensorPtr= m_sensor;
	m_year = year;
	myStringCopy(m_model, model);
	myStringCopy(m_make,make);
	myStringCopy(m_owner,"\0");
	m_baseprice = baseprice;
	m_available = available;
	//Sets up each sensor
	for(int i=0; i<maxSensors;i++)
	{
		*sensorPtr = *sensor;
		sensor++;
		sensorPtr++;
	}
}

//Car Copy Constructor
Car::Car(Car &car)
{
	Sensor *sensorPtr= m_sensor;
	Sensor *carSensorPtr= car.m_sensor;
	m_year = car.m_year;
	myStringCopy(m_model, car.m_model);
	myStringCopy(m_make, car.m_make);
	myStringCopy(m_owner, car.m_owner);
	m_baseprice = car.m_baseprice;
	m_finalprice = car.m_finalprice;
	m_available = car.m_available;
	//Sets up each sensor
	for(int i =0; i<maxSensors;i++)
	{
		*sensorPtr = *carSensorPtr;
		sensorPtr++;
		carSensorPtr++;
	}
	updatePrice();
}

//Getters and Setters for Car information
int Car::getYear() const
{
	return m_year;
}
char *Car::getModel()
{
	return m_model;
}
char *Car::getMake()
{
	return m_make;
}
Sensor *Car::getSensor()
{
	return m_sensor;
}
double Car::getBasePrice() const
{
	return m_baseprice;
}
double Car::getFinalPrice() const
{
	return m_finalprice;
}
bool Car::getAvailable() const
{
	return m_available;
}
char *Car::getOwner()
{
	return m_owner;
}

void Car::setYear(int year)
{
	m_year = year;
}
void Car::setModel(char *model)
{
	myStringCopy(m_model,model);
}
void Car::setMake(char *make)
{
	myStringCopy(m_make,make);
}
void Car::setBasePrice(double baseprice)
{
	m_baseprice = baseprice;
}
void Car::setAvailable(bool available)
{
	m_available = available;
}
void Car::setOwner(char *owner)
{
	myStringCopy(m_owner,owner);
}

//Car Method to update price when new sensor is added
double Car::updatePrice()
{
	Sensor *sensorPtr = m_sensor;
	double priceTotal;
	priceTotal = m_baseprice;
	//Checks for each sensor and adds price
	for (int i =0;i< maxSensors; i++)
	{
		priceTotal += sensorPtr->getExtraCost();
		sensorPtr++;
	}
	return m_finalprice = priceTotal;
}

//Car Method to prints out car with all the sensors
void Car::printCar()
{
	Sensor *sensorPtr = m_sensor;
	cout << m_year << " " << m_make << " " << m_model << "  \t\tBase: " << m_baseprice << "\t\tWith {";
	cout << sensorPtr->getType() << " ";
	sensorPtr++;
	updatePrice();
	cout << sensorPtr->getType() << " ";
	sensorPtr++;
	updatePrice();
	cout << sensorPtr->getType();
	updatePrice();
	cout << "}: " << m_finalprice << "       \t\tAvailable: " << std::boolalpha << m_available << "     \tOwner:"<< m_owner << endl;
}

//Estimate the Total cost based on number of days
double Car::estimateCost(int days)
{
	return m_finalprice * days;
}

//Method to Add a sensor to the car
Car &Car::operator+(Sensor &sensor)
{
	Sensor *carSensor = m_sensor;
	for (int i =0; i<maxSensors;i++)
	{
		//Checks if there is a sensor in the first place.
		//If sensor is there, checks which type and update the correct price
		if(myStringCompare(carSensor->getType(), "none") != 0)
		{
		if(myStringCompare(carSensor->getType(), "gps") == 0)
		{
			carSensor->setType(sensor.getType());
			carSensor++;
			updatePrice();
			break;
		}
		else if(myStringCompare(carSensor->getType(), "lidar") == 0)
		{
			carSensor->setType(sensor.getType());
			carSensor++;
			updatePrice();
			break;
		}
		else if(myStringCompare(carSensor->getType(), "radar") == 0)
		{
			carSensor->setType(sensor.getType());
			carSensor++;
			updatePrice();
			break;
		}
		else if(myStringCompare(carSensor->getType(), "camera") == 0)
		{
			carSensor->setType(sensor.getType());
			carSensor++;
			updatePrice();
			break;
		}
	break;
	}
}
return *this;
}



//Method to read car information using a copy constructor
std::ifstream &operator>>(std::ifstream &infile, Car &car)
{
	int i = 0;
	infile >> car.m_year >> car.m_make >> car.m_model >> car.m_baseprice;
	//Skips '{' then starts reading sensors
	infile.get();
	infile.get();
	char sensor1[maxName];
	bool end;
	int length= myStringLength(sensor1);
	//Checks if string is a '}'
	if(*(sensor1+length-1) == '}')
	{
		*(sensor1+length-1) = '\0';
		end = 0;
	}
	else
	{
		end = 1;
	}
	//Loops until bracket '}' is found
	while (end == 1)
	{
		infile >> sensor1;
		int length= myStringLength(sensor1);
		if(*(sensor1+length-1) == '}')
		{
		*(sensor1+length-1) = '\0';
		end = 0;
		}
		else
		{
		end = 1;
		}

		*(car.m_sensor+i) = Sensor(sensor1);
		car.updatePrice();
		i++;
	}

	infile >> car.m_available;
	//If the car is not available, read in owner
	if(car.m_available == 0)
	{
		infile >> car.m_owner;
	}

	return infile;
}


//Adds the lessee's name to a car
Car &Car::operator+(const char *lessee)
{
	myStringCopy(m_owner,lessee);
	m_available = false;
	updatePrice();
	return *this;
}
