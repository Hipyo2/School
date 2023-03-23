//Nicholas Ang
//Precond Violated Except CPP file

//Libraries and Header Files
#include "PrecondViolatedExcept.h"

//Parameterized Constructor
//Outputs "Precond Violated Except" with whatever message was inputted when logic error occurs
PrecondViolatedExcept::PrecondViolatedExcept(const std::string &message): std::logic_error("Precond Violated Except: " + message)
{

}
