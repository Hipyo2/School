//Nicholas Ang
//Precond Violated Except Header File

#ifndef PRECOND_VIOLATED_EXCEPT
#define PRECOND_VIOLATED_EXCEPT

//Libraries and Header Files
#include <stdexcept>
#include <string.h>

using namespace std;

//Precond Violated Except Class Declaration
class PrecondViolatedExcept : public std::logic_error
{
	//Public Methods
	public:
		//Parameterized Constructor
		PrecondViolatedExcept(const std::string &message = "");
};

//#include "PrecondViolatedExcept.cpp"
#endif /*PRECOND_VIOLATED_EXCEPT*/
