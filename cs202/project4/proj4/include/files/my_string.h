//Nicholas Ang
//Project 4
//String Functions Header File

#ifndef MY_STRING
#define MY_STRING

//Libraries and Header Files
#include <iostream>
#include <fstream>
using namespace std;

//Function Prototypes
//Copies the characters from one source string to a destination string.
char *myStringCopy(char *destination,const char *source);

//Takes one string and compares it to another string. Returns a value that determines which one should be first.
int myStringCompare(const char *string1,const char *string2);

//Reads a string and counts how long the string is.
size_t myStringLength(const char *str);

//Appends characters from source string to a destination string. 
char *myStringCat(char *destination, const char *source);


#endif /*MY_STRING*/
