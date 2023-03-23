//Nicholas Ang
//Project 3
//RentalCar Class Header File and Methods

#ifndef RENTAL_CAR_H
#define RENTAL_CAR_H

#include <fstream>
using namespace std;
#define maxName 256
#define zipCodeSize 5
#define inventory 5
#define agencyNum 3
#define maxCars 5

class RentalCar
{
public:
RentalCar();
RentalCar(int year, char *make, char *model, double price, bool available);

int getYear();
void setYear(int year);

double getPrice();
void setPrice(double price);

bool getAvailable();
void setAvailable(bool available);

char getMake();
void setMake(char *make);

char getModel();
void setModel(char *model);

void print();
double getEstimate(int days);

void fileInput(std::ifstream &infile);
private:
	int m_year;
	char m_make[maxName+1];
	char m_model[maxName+1];
	double m_price;
	bool m_available;

};



#endif /* RENTAL_CAR_H */
