//Nicholas Ang
//Project 3
//String Functions Source File


//Libraries and Header Files
#include "my_string.h"

//Function Declarations

//myStringCopy Function
char *myStringCopy(char *destination,const char *source)
{
	//Copies string from source to destination string
	int i=0;
	//Uses pointer arithmetic to go through each character
	for(i = 0; *source != '\0';i++ && source++ && destination++)
	{
		*destination = *source;
	}
	*destination = '\0';
	return destination;
}

//myStringCompare Function
int myStringCompare(const char *string1,const char *string2)
{
	//Compares each letter to see which string should go first
	int i=0;
	//Uses pointer arithmetic to go through each character
	for(i=0; *string1 != '\0' || *string2 !='\0';++i && string1++ && string2++)
	{
		if (*string1 < *string2)
		{
			return 1;
		}
		else if(*string1 > *string2)
		{
			return -1;
		}
		//If characters are the same, continue to next character
		if (*string1 == *string2)
		{
			if (*string1 < *string2)
			{
				return 1;
			}
			else if(*string1 > *string2)
			{
				return -1;
			}
		}
	}
	return 0;
}

//myStringLength Function
size_t myStringLength(const char *str)
{
	//Checks the length of a string
	int length;
	//Uses pointer arithmetic to go through each character
	for(length = 0; *str != '\0'; length++)
	{
		str++;
	}

	return length;
}

//myStringCat Function
char *myStringCat(char *destination, const char *source)
{
	//Uses pointer arithmetic to go through each character
	//Sets destination pointer to point to NULL character
	for(int i=0; *destination != '\0'; destination++ && i++)
	{
	}
	//Appends the characters of source to destination and places NULL character at the end
	for(int i=0; *source != '\0'; i++)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return destination;
}
