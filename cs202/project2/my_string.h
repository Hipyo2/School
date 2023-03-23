#ifndef MY_STRING
#define MY_STRING

#include <iostream>
#include <fstream>
char *myStringCopy(char *destination,const char *source);

int myStringCompare(const char *string1,const char *string2);

size_t myStringLength(const char *str);

char *myStringCat(char *destination, const char *source);

#endif /*MY_STRING*/
