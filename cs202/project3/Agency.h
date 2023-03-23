
#ifndef AGENCY_H
#define AGENCY_H

#include "RentalCar.h"

#define maxName 256
#define zipCodeSize 5
#define inventory 5
#define agencyNum 3
#define maxcars 5

struct RentalAgency
{
	char name[maxName];
	int zipcode[zipCodeSize];
	RentalCar carsInventory[inventory];
};


#endif /* AGENCY_H */
