//Nicholas Ang
//Project 4
//Agency Class Source File

//Libraries and Header Files
#include <files/Agency.h>
#include <files/Car.h>
#include <files/Sensor.h>
#include <files/my_string.h>
#include <iostream>
using namespace std;

//Global Constants
#define maxCars 5
#define maxSensors 3
#define maxName 256
//Agency Default Constructor
Agency::Agency()
{
	myStringCopy(m_name, "");
	m_zipcode = 0;
}

//Getter and Setters for Agency Information
char *Agency::getName() 
{
return m_name;
}

int Agency::getZipcode() const
{
return m_zipcode;
}

void Agency::setZipcode(int zipcode)
{
m_zipcode = zipcode;
}

void Agency::setName(char *agencyName)
{
myStringCopy(m_name,agencyName);
}


//Agency Method to read all data from a file and place it into the appropriate classes and constructors
void Agency::readAllData(std::ifstream &infile)
{
	//Reads in Zipcode and Name of Agency
	int zip;
	infile >> m_name >> zip;
	setZipcode(zip);
	Car *carinventory = m_inventory;
	//Loops through each part of the car array
	//Reads in information of the car using overloaded operator >> 
	for(int i=0;i<maxCars;i++)
	{
		infile >>*carinventory;
		carinventory++;
	}
}

//Agency Method to Print out all cars from the car class array
void Agency::printAllCars()
{
	//Sets up index of cars
	int index[] = {1,2,3,4,5};
	int *indexptr = index;
	Car *carInfo = m_inventory;

	//Prints out Agency Information
	cout << m_name << " " << m_zipcode << endl;

	//Uses Agency Method to print out all sensors that are on the cars in the agency
	Agency::printActiveSensors();

	//Loop to print out all cars for a total of 5 cars
	for (int i = 0; i< maxCars; i++)
	{
		//Prints out index
		cout <<  "["<<*(indexptr+i) << "]";

		//uses Car Method to print out car
		carInfo->printCar();
		carInfo++;
	}
	cout << endl;
}

//Prints out the count of each sensor in all the cars
void Agency::printActiveSensors()
{
	//Uses Sensor Method to get the count of each sensor
	cout << "Active Sensors:" << " {gps}:" << Sensor::getGps() << " {camera}:" << Sensor::getCamera() << " {lidar}:" << Sensor::getLidar() << " {radar}:" << Sensor::getRadar() << endl;
}

//Operator Overload for index usage
Car &Agency::operator[](int index)
{
	return *(m_inventory + index);
}

//Agency Method to Print out available cars
void Agency::printFiltered()
{

//Index
int index2[] = {1,2,3,4,5};
int *indexptr2 = index2;

//Loops through all cars
//Checks if Car is available and prints it out if available
for(int i=0;i<maxCars;i++)
{
	if((m_inventory+i)->getAvailable() == true)
	{
		cout << "[" << *(indexptr2+i) << "]";
		(m_inventory+i)->printCar();
	}
}
cout << endl;
}

//Agency Method to reserve a car and refresh the list
void Agency::reserveOne()
{
	//Variables
	int reserve, days;
	char ownerName[maxName];

	//Agency Method to print all cars
	printAllCars();

	//User Prompts
	cout << endl << "Which car would you like to reserve? ";
	cin >> reserve;
	if(reserve <0 || reserve > 5)
	{
		cout << "Invalid Number";
	}
	else
	{
		reserve--;
		//Checks if Car is available to Reserve
		//If False, error message. If True, asks for days and print estimated cost, prompt for owner and link owner to car. Success message
		if((m_inventory+reserve)->getAvailable() == false)
		{
			cout << "This car cannot be reserved" << endl;
		}
		else if ((m_inventory+reserve)->getAvailable() == true)
		{
			//Gets days they want to car for. Give estimate with car method
			cout << "This car can be reserved." << endl << endl << "How many days do you want to reserve it for? ";
			cin >> days;
			cout << "It's estimated cost will be $" << (m_inventory+reserve)->estimateCost(days) << endl << endl;
			cout << "What should be put for the lessee's name? ";
			cin >> ownerName;
			//Change availability and set owner
			(m_inventory+reserve)->setAvailable(false);
			(m_inventory+reserve)->setOwner(ownerName);

			//Refresh and print all cars
			printAllCars();
			cout << "You have reserved this car." << endl;
		}
	}
}
