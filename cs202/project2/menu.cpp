#include "menu.h"
#include "my_string.h"

#define maxcars 5
#define carNameSize 10
#define maxfilename 100

struct RentalCar
{
	int year;
	char make[carNameSize+1];
	char model[carNameSize+1];
	double price;
	bool available;
};
RentalCar cars[maxcars-1];
RentalCar temp;


void userMenuPrompt()
{
	int input, index[maxcars];
	char inputfile [maxfilename];
	char outputfile [maxfilename];
	ifstream infile;
	ofstream outfile;
	int carAmount = 0;
	do{
		cout << "Select an option" << endl << "1. Read Data from Input File" << endl << "2. Print Data to Terminal" << endl <<"3. Print Data to Output File" << endl <<"4. Sort Cars by Ascending Price" << endl <<"5. Estimated Price For Rent" << endl <<"6. Rent a Vehicle" << endl << "7. EXIT" << endl;
		cin >> input;
		switch (input)
		{
			case 1: cout << "Please enter the name of the input file." << endl;
				cin >> inputfile;
				infile.open(inputfile);
				readCars(cars, carAmount,infile, index);
				break;

			case 2: printNamesToTerminal(cars, carAmount, index);
				break;

			case 3: cout << "Please enter the name of the output file." << endl;
				cin >> outputfile;
				outfile.open(outputfile);
				printNamesToFile(cars,carAmount, outfile);
				outfile.close();
				break;

			case 4: cout << "The cars have been sorted by ascending price." << endl << endl;
				sortCarsByPrice(cars, carAmount,temp);
				break;

			case 5: rentalCarQuery(cars, carAmount, index);
				break;

			case 6: rentalCarReserve(cars, carAmount,index);
				break;

			case 7: break;
		}
	}
	while(input != 7);
}


void readCars(struct RentalCar *carArray, int &carNum, std::ifstream &infile, int *numbers)
{
	//Sets up initial order and reads names from input file into array.
	for (int i =0; i< maxcars; ++i)
	{
		*numbers = i;
		numbers++;	
		
		infile >> carArray->year;
		infile >> carArray->make;
		infile >> carArray->model;
		infile >> carArray->price;
		infile >> carArray->available;
		
		carArray++;
		carArray->make[carNameSize+1] = '\0';
		carArray->model[carNameSize+1] = '\0';
		carNum = i+1;
		//File ends so stop, finds amount of names in file
		if(infile.eof())
		{
			carNum = i;
			break;
		}
	}
}


void printNamesToTerminal(struct RentalCar *carArray, int carNum, int *numbers)
{
	//Prints Names and Associated Number to Terminal
	for (int i =0; i< carNum; i++)
	{
		cout << "[" << *numbers << "] " << carArray->year << " " << carArray->make << " " << carArray->model <<" , $" << carArray->price << " per day , Available: " << boolalpha << carArray->available << endl;
		carArray++;
		numbers++;
	}
	cout << endl;
}

void printNamesToFile(struct RentalCar *carArray, int carNum, ofstream &outfile)
{
	//Prints Names and Associated Number to output file
	for (int i =0; i< carNum; i++)
	{
		outfile << carArray->year << " " << carArray->make << " " << carArray->model <<" " << carArray->price << " " << carArray->available << endl;
		carArray++;
	}
	outfile << endl;
}

void sortCarsByPrice(struct RentalCar *carArray,int carNum, struct RentalCar temp)
{
	//Sorts names by ascending price
	//Temporary values to hold swapping numbers
	for(int r=1; r<=carNum-1;r++)
	{
		for(int i=0; i<=carNum-r-1;i++)
		{
			if((carArray+i)->price > (carArray+i+1)-> price)
			{
				temp = *(carArray+i);
				*(carArray+i) = *(carArray+i+1);
				*(carArray+i+1) = temp;
			}
		}
	}
}



void rentalCarQuery(struct RentalCar *carArray,int carNum, int *numbers)
{
	int estimateDays;
	cout << "How many days would you like to rent a car?" << endl;
	cin >> estimateDays;
	for(int i =0; i<carNum; i++)
	{
		if (carArray->available == 1)
		{
			cout << "[" << *numbers << "] " << carArray->year << " " << carArray->make << " " << carArray->model <<" , Total Cost: $" << carArray->price*estimateDays << endl;
			carArray++;
			numbers++;
		}
		else
		{
			carArray++;
			numbers++;
		}
	}
	cout << endl;
}

void rentalCarReserve(struct RentalCar *carArray, int carNum, int *numbers)
{
	int actualDays;
	int index;
	printNamesToTerminal(carArray, carNum, numbers);
	cout << "Which car do you want to rent?" << endl;
	cin >> index;
	cout << "How many days would you like to rent a car?" << endl;
	cin >> actualDays;
	if ((carArray+index)->available == 0)
	{
		cout << "Sorry, the corresponding car is not available." << endl;
	}
	else if ((carArray+index)->available == 1)
	{
		cout << "The " << (carArray+index)->year << " " << (carArray+index)->make << " " << (carArray+index)->model << " will be rented to you for " << "$" << (carArray+index)->price*actualDays << " for " << actualDays << " days." << endl;
		(carArray+index)->available = 0;
	}

}
