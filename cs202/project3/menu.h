//Nicholas Ang
//Project 3
//Menu Header File


#ifndef MENU_H
#define MENU_H

//Libraries
#include <iostream>
#include <fstream>
using namespace std;

#include "RentalCar.h"
#include "Agency.h"


//Function Prototypes

//Menu Function
void userMenuPrompt(RentalAgency *Agency, RentalAgency *cheapCar);

//Functions used in the menu
//Read names from file and places into Car Struct Array. Returns integer of number of entries. Creates an index for order of names
void readCars(RentalAgency *carAgency, ifstream &infile);
void printAgenciesToTerminal(RentalAgency *carAgency);
void estimateRentalCost(RentalAgency *carAgency, int *indexAgency, int *indexCar);
void findCheapestRental(RentalAgency *carAgency, RentalAgency *cheapCar);
void reserveCar (RentalAgency *carAgency, int *indexAgency, int *indexCar);

#endif /* MENU_H */
