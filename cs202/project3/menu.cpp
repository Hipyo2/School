#include "menu.h"
#include "my_string.h"
#include "RentalCar.h"


void userMenuPrompt(RentalAgency *carAgency, RentalAgency *cheapCar)
{
	//Declared Variables and Arrays
	int input;
	char inputfile [maxName+1];
	ifstream infile;
	int indexAgency[agencyNum] = {1,2,3};
	int indexCar[maxCars] = {1,2,3,4,5};
	//Do While Loop to create Menu with Prompt
	do{
		cout << "Select an option" << endl << "1. Read Data from File" << endl << "2. Print Data to Terminal" << endl <<"3. Estimate Car Rental Cost" << endl <<"4. Find Cheapest Available Car" << endl <<"5. Reserve Car" << endl << "6. EXIT" << endl;
		cin >> input;
		//Switch Statement with 7 cases to create menu functions
		switch (input)
		{

			//Prompts for input file and reads from file to struct array and class array
			case 1: cout << "Please enter the name of the input file." << endl;
				cin >> inputfile;
				infile.open(inputfile);
				readCars(carAgency,infile);
				break;

			//Print Car Array and Agencies to Terminal
			case 2: printAgenciesToTerminal(carAgency);
				break;

			//Estimates Rental Cost for the cars based on intended number of days
			case 3: estimateRentalCost(carAgency, indexAgency,indexCar);
				break;

			//Finds the cheapest rental car in all three agencies
			case 4: findCheapestRental(carAgency, cheapCar);
				break;
			//Reserves a car from an agency and provides warning message if car is unavailable
			case 5: reserveCar(carAgency, indexAgency, indexCar);
				break;

			//Exits Program
			case 6: break;
		}
	}
	while(input != 6);
}


void readCars(RentalAgency *carAgency, std::ifstream &infile)
{
for (int j = 0; j< agencyNum; ++j)
{

int agencyZipCode;
infile >> carAgency->name >> agencyZipCode;
carAgency->zipcode[j] = agencyZipCode;

RentalCar *carArray = carAgency->carsInventory;
for (int i =0; i< maxcars; ++i)
	{	
		carArray->fileInput(infile);
		carArray++;
	}
carAgency++;
}
}

void printAgenciesToTerminal(RentalAgency *carAgency)
{
for (int j = 0; j< agencyNum; ++j)
{
cout << carAgency->name << " " << carAgency->zipcode[j] << endl;

RentalCar *carArray = carAgency->carsInventory;
for (int i =0; i< maxcars; ++i)
	{	
		carArray->print();
		carArray++;

	}
carAgency++;
cout << endl;
}
}

void estimateRentalCost(RentalAgency *carAgency, int *indexAgency, int *indexCar)
{
int inputAgency = 0, inputCar=0;
int estimateDays=0;
cout << "Which agency do you want to look at?" << endl;
for(int i=0; i< agencyNum; ++i)
{
cout << *indexAgency << ". " << carAgency->name << endl;
carAgency++;
indexAgency++;
}
carAgency-=3;
cin >> inputAgency;

if(inputAgency <1 ||inputAgency >3)
{
cout << "Invalid Number" << endl;
return;
}

carAgency+=(inputAgency-1);
RentalCar *carArray = carAgency->carsInventory;
for (int i =0; i< maxcars; ++i)
	{	
		cout << *indexCar << ". ";
		carArray->print();
		carArray++;
		indexCar++;

	}
cout << "Which car do you want an estimate for?" << endl;
cin >> inputCar;
inputCar--;
carArray -= 5;
carArray+=inputCar;
cout << "How many days do you want to rent it for?" << endl;
cin >> estimateDays;
cout << "Your estimated price is $" << carArray->getEstimate(estimateDays) << endl;

}


void findCheapestRental(RentalAgency *carAgency, RentalAgency *cheapCar)
{
RentalCar *cheapestCar = cheapCar->carsInventory;
cheapestCar = carAgency->carsInventory;
for (int j = 0; j< agencyNum; ++j)
{
RentalCar *carArray = carAgency->carsInventory;
for (int i =0; i< maxcars; ++i)
	{	
		if(carArray->getAvailable() == true)
		{
		if(carArray->getPrice() < cheapestCar->getPrice())
		{
		cheapestCar = carArray;
		}
		}
		carArray++;	
	}
carAgency++;
}
cout << "Cheapest Available Car: " ;
cheapestCar->print();
}

void reserveCar (RentalAgency *carAgency, int *indexAgency, int *indexCar)
{
int inputAgency = 0, inputCar=0;
cout << "Which agency do you want to look at?" << endl;
for(int i=0; i< agencyNum; ++i)
{
cout << *indexAgency << ". " << carAgency->name << endl;
carAgency++;
indexAgency++;
}
carAgency-=3;
cin >> inputAgency;
if(inputAgency <1 ||inputAgency >3)
{
cout << "Invalid Number" << endl;
return;
}
carAgency+= (inputAgency-1);
RentalCar *carArray = carAgency->carsInventory;
for (int i =0; i< maxcars; ++i)
	{	
		cout << *indexCar << ". ";
		carArray->print();
		carArray++;
		indexCar++;

	}
cout << "Which car do you want to reserve?" << endl;
cin >> inputCar;
if(inputCar <1 ||inputCar >5)
{
cout << "Invalid Number" << endl;
return;
}
inputCar--;
carArray -= 5;
carArray+=inputCar;
if (carArray->getAvailable() == false)
{
cout << "This car is unavailable." << endl;
}
else if (carArray->getAvailable() == true)
{
carArray->setAvailable(false);
carAgency-=(inputCar+1);
printAgenciesToTerminal(carAgency);
cout << "You have reserved the car" << endl << endl;
}
}

