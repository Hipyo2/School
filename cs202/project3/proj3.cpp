//Nicholas Ang
//Project 3
//Main File

#include "menu.h"
#include "my_string.h"
#include "Agency.h"
#include "RentalCar.h"

RentalAgency rentalCarAgency[agencyNum];
RentalAgency cheapCar[agencyNum];

int main()
{
userMenuPrompt(rentalCarAgency, cheapCar);
return 0;
}
