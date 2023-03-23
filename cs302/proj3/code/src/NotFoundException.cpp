//Nicholas Ang
//Not Found Exception CPP file

//Libraries and Header Files
#include "NotFoundException.h"

//Parameterized Constructor
//Outputs "Not Found Exception" with whatever message was inputted when logic error occurs
NotFoundException::NotFoundException(const std::string &message): std::logic_error("Not Found Exception: " + message)
{

}
