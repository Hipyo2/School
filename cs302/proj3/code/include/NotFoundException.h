//Nicholas Ang
//Not Found Exception Header File

#ifndef NOT_FOUND_EXCEPTION
#define NOT_FOUND_EXCEPTION

//Libraries and Header Files
#include <stdexcept>
#include <string.h>

using namespace std;

//Not Found Exception Class Declaration
class NotFoundException : public std::logic_error
{
	//Public Methods
	public:
		//Parameterized Constructor
		NotFoundException(const std::string &message = "");
};

//#include "NotFoundException.cpp"
#endif /*NOT_FOUND_EXCEPTION*/
