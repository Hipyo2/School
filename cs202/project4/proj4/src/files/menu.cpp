//Nicholas Ang
//Project 4
//Menu Source File

#include <files/menu.h>
#include <files/my_string.h>
#include <files/Car.h>
#include <files/Agency.h>
#include <files/Sensor.h>


void userMenuPrompt(Agency agency)
{
	//Declared Variables and Arrays
	int input;
	char inputfile [maxName+1];
	ifstream infile;
	//Do While Loop to create Menu with Prompt
	do{
		cout << "Select an option" << endl << "1. Read Data from File" << endl << "2. Print All Cars" << endl <<"3. Print Available Cars" << endl <<"4. Reserve a Car and Refresh List" << endl <<"5. EXIT" << endl;
		cin >> input;
		//Switch Statement with 5 cases to create menu functions
		switch (input)
		{

			//Prompts for input file and reads from file to struct array
			case 1: cout << "Please enter the name of the input file." << endl;
				cin >> inputfile;
				infile.open(inputfile);
				agency.readAllData(infile);
				infile.close();
				break;

			//Print all cars in Agency's Car class array
			case 2: agency.printAllCars();
				break;

			//Prints only available cars to the terminal
			case 3: agency.printFiltered();
				break;

			//Reserves Car, gives estimate cost, takes name as the owner, changes availability of selected car
			case 4: agency.reserveOne();
				break;
			//Exits Program
			case 5: Sensor::resetGps();
				Sensor::resetCamera();
				Sensor::resetLidar();
				Sensor::resetRadar();
				break;
		}
	}
	while(input != 5);
}
