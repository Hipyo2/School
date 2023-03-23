//Nicholas Ang
//Project 4
//Agency Class Header File

#ifndef AGENCY_H
#define AGENCY_H

//Libraries and Header Files
#include <files/Car.h>
#include <iostream>
#include <fstream>
using namespace std;
//Global Constants
#define maxName 256
#define maxCars 5

class Agency
{
	//Private Methods
	private:
	int m_zipcode;
	char m_name[maxName+1];
	Car m_inventory[maxCars];

	//Public Methods
	public:
	//Constructors
	Agency();
	//Getters and Setters for Agency Name and Zipcode
	char *getName();
	int getZipcode() const;
	void setName(char *agencyName);
	void setZipcode(int zipcode);
	
	//Agency Methods to Read All Data from a file
	void readAllData(std::ifstream &infile);

	//Print active sensors in the Agency
	void printActiveSensors();

	//Print All Cars in the Agency
	void printAllCars();

	//Print ONLY available in the Agency
	void printFiltered(); 

	//Allows user to reserve car, get estimate cost, change availability and set owner based on user input
	void reserveOne();
	
	//Operator Overload for Index
	Car &operator[](int index);
};


#endif /* AGENCY_H */
