#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <fstream>
using namespace std;

void userMenuPrompt(/*struct RentalCar *cars*/);

void readCars(struct RentalCar *carArray, int &carNum, ifstream &infile, int *numbers);

void printNamesToTerminal(struct RentalCar *carArray, int carNum, int *numbers);

void printNamesToFile(struct RentalCar *carArray, int carNum, ofstream &outfile);

void sortCarsByPrice(struct RentalCar *carArray,int carNum, struct RentalCar temp);

void rentalCarQuery(struct RentalCar *carArray,int carNum, int *numbers);

void rentalCarReserve(struct RentalCar *carArray, int carNum, int *numbers);

#endif /* MENU_H */
